/**
 * Function: Memory copy
 * ^^^^^^^^^^^^^^^^^^^^^
 * Implements a generic memory copy function
 */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

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
void *memcopy(const void *restrict src, void *restrict dest, size_t nbytes) {
  void *dptr = dest;
  const uint8_t *convsrc = src;
  uint8_t *convdest = dest;
  for (; nbytes; *convdest++ = *convsrc++, nbytes--) {}
  return dptr;
}

void test_character_array() {
  char source[] = "what am I going to do with my life?";
  char destination[36];
  memcopy(source, destination, sizeof(char) * 36);

  assert(strcmp(source, destination) == 0);
  puts("Test 1 Passed: Character Array");
}

void test_double_array() {
  double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double destination[5];
  memcopy(source, destination, sizeof(source));

  for (uint8_t i = 0; i < 5; assert(destination[i] == source[i]), i++) {}
  puts("Test 2 Passed: Double Array");
}

void test_custom_struct() {
  typedef struct {
    char name[256];
    uint8_t age;
    float gpa;
  } Student;

  Student source = {"Bhargav", 20, 8.2};
  Student destination;
  memcopy(&source, &destination, sizeof(Student));

  assert(source.age == destination.age);
  assert(strcmp(source.name, destination.name) == 0);
  assert(source.gpa == destination.gpa);

  puts("Test 3 Passed: Student Struct");
}

void run_all_tests() {
  test_character_array();
  test_double_array();
  test_custom_struct();
}

int main() {
  run_all_tests();
  return 0;
}
