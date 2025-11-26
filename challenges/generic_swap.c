/**
 * Program: Generic Memory Swap
 * ----------------------------
 * Implements a generic swap function that avoids heap allocation
 * by using a fixed-size stack buffer.
 */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// 256 bytes is small enough for the stack, but large enough
// to minimize the number of memcpy calls for medium objects.
#define CHUNK_SIZE 256

/**
 * @brief Copies a block of memory from source to destination.
 *
 * A simplified implementation of the standard `memcpy`. It
 * copies data byte-by-byte to ensure safety across all architectures,
 * ignoring potential CPU word-alignment optimizations for stability.
 *
 * @param[in]  src  The place to copy raw bytes from.
 * @param[out] dest The place to paste raw bytes to.
 * @param[in]  n    The number of bytes to copy.
 *
 * @return Pointer to the destination (@p dest).
 *
 * @note Performance Trade-off:
 * This implementation uses a byte-by-byte copy loop (`uint8_t`).
 * While less efficient than copying by the CPU's native word size
 * (e.g., `size_t` on 64-bit systems), it is strictly robust against
 * memory misalignment issues (SIGBUS errors on ARM/RISC) and requires
 * no complex preamble/postamble logic.
 */
void *memcopy(const void *restrict src, void *restrict dest, size_t n) {
  void *dptr = dest;
  const uint8_t *convsrc = (uint8_t *)src;
  uint8_t *convdest = (uint8_t *)dest;

  // Post-increment has higher precedence that dereference,
  // so this moves the pointers forward after assignment.
  for (; n; *convdest++ = *convsrc++, n--) {}

  return dptr;
}

/**
 * @brief Swaps the contents of two arbitrary memory blocks.
 *
 * Exchanges `size` bytes between `a` and `b`. Instead of allocating
 * a temporary buffer on the heap (which is slow and non-deterministic),
 * this function uses a small, fixed-size stack buffer and swaps the
 * memory in chunks.
 *
 * @param[in, out] a    Pointer to the first memory block
 * @param[in, out] b    Pointer to the second memory block
 * @param[in]      size Total size of the data to swap in bytes.
 *
 * @note Systems Programming Context:
 * - **Heap Avoidance:** `malloc` introduces non-deterministic latency.
 *   In high-performance contexts (like Kernels or HFT), using the stack
 *   ensures a predictable execution time.
 * - **Chunking:** Large objects are broken down into `CHUNK_SIZE` pieces
 *   to fit into the stack buffer, ensuring we don't blow the stack frame
 *   when swapping massive structures.
 */
void swap(void *a, void *b, size_t size) {
  uint8_t temp[CHUNK_SIZE];
  uint8_t *conva = a; // Unsigned char converted a
  uint8_t *convb = b; // Unsigned char converted b

  while (size > 0) {
    // size_t copysize = (size % CHUNK_SIZE) ? size : CHUNK_SIZE;
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    // This is so fucking dumb. I hate myself.

    // Determine the amount to copy: either a full chunk or the
    // remaining tail.
    size_t copysize = (size > CHUNK_SIZE) ? CHUNK_SIZE : size;

    // Perform the standard 3-step swap using the stack buffer
    memcopy(conva, temp, copysize);
    memcopy(convb, conva, copysize);
    memcopy(temp, convb, copysize);

    // Advance pointers and decrese remaining size.
    // conva++;
    // ^^^^^^^^
    // convb++;
    // ^^^^^^^^
    // size--;
    // ^^^^^^^
    // This is so fucking dumb. I hate myself. This just decreases
    // the size by only one which would result in wrong copysize
    // calculations and memcopy function calls. Even the pointers
    // are incremented by one and not by the amount of bytes copied.

    conva += copysize;
    convb += copysize;
    size -= copysize;
  }
}

void test_integer_case() {
  uint8_t num1 = 65;
  uint8_t num2 = 97;
  swap(&num1, &num2, sizeof(uint8_t));

  assert(num2 == 65 && num1 == 97);
  puts("Test 1 Passed: Integer Swap");
}

void test_integer_array_case() {
  uint8_t arr1[5] = {1, 2, 3, 4, 5};
  uint8_t arr2[5] = {6, 7, 8, 9, 10};
  swap(arr1, arr2, sizeof(arr1));

  for (uint8_t i = 0; i < 5; assert(arr2[i] + 5 == arr1[i]), i++) {}
  puts("Test 2 Passed: Integer Array Swap");
}

void test_struct_case() {
  typedef struct {
    char name[256];
    uint8_t age;
    float gpa;
  } Student;

  Student s1 = {"Bhargav", 20, 8.2f};
  Student s2 = {"John", 22, 6.0f};
  swap(&s1, &s2, sizeof(Student));

  assert(strcmp(s1.name, "John") == 0);
  assert(s1.age == 22);
  assert(s1.gpa == 6.0f);
  assert(strcmp(s2.name, "Bhargav") == 0);
  assert(s2.age == 20);
  assert(s2.gpa == 8.2f);

  puts("Test 3 Passed: Student Struct Swap");
}

void run_all_tests() {
  test_integer_case();
  test_integer_array_case();
  test_struct_case();
}

int main() {
  run_all_tests();
  return 0;
}
