/**
 * Program: Custom 'strcspan' function
 * -----------------------------------
 * Create a `strcspan` function which is similar to the
 * standard library `strcspn` function. Optimization is
 * optional for now.
 */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#define MODE_SET 0
#define MODE_CHECK 1
#define BITS (8 * sizeof(size_t))

/* NOTE: This is the exact opposite of optimization as it
 * makes use of auxillary variables like index, offset and mask.
 * But using this function makes the bitwise operations much
 * clearer to understand.
 */
int bitop(size_t *bitmap, uint8_t c, uint8_t mode) {
  size_t index = c / BITS;
  size_t offset = c % BITS;
  size_t mask = (size_t)1 << offset;

  if (mode == MODE_SET) {
    bitmap[index] |= mask;
    return 1;
  }

  return !!(bitmap[index] & mask);
}

/**
 * @brief Get length of a substring
 *
 * Calculates the length (in bytes) of the initial segment
 * of @p space which entirely of bytes NOT in @p reject.
 *
 * @param[in] reject
 *      Rejectable array of characters.
 *
 * @param[in] space
 *      String to perform the function on.
 *
 * @return
 * - Difference in index between the first character not in
 *   @p accept and the start of the substring.
 */
size_t strcspan(const char *reject, const char *space) {
  size_t bitmap[32 / sizeof(size_t)] = {0};
  const char *counter = space;

  for (; *reject && bitop(bitmap, *reject, MODE_SET); reject++) {};
  for (; *counter && !bitop(bitmap, *counter, MODE_CHECK); counter++) {};

  return counter - space;
}

void test_string_cspan() {
  const char *strspace = "Bhargav;;";
  const char *rejectable = ";";

  assert(strcspan(rejectable, strspace) == 7);
  puts("Test 1 Passed: Valid substring length found.");
}

void test_string_cspan_empty() {
  const char *strspace = "aaaabbbb";
  const char *rejectable = "";

  assert(strcspan(rejectable, strspace) == 8);
  puts("Test 2 Passed: Empty substring length found.");
}

void run_all_tests() {
  test_string_cspan();
  test_string_cspan_empty();
}

int main() {
  run_all_tests();
  return 0;
}
