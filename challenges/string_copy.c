/**
 * Program: Custom function to copy strings from src to dst.
 * ---------------------------------------------------------
 * Goal: Implement a `strcopy` function similar to the `strcpy`
 * function from the standard library which copies a string
 * from it's source to a destination.
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Finds the length of a string.
 *
 * Finds the length of a string exclusive of the
 * terminating null character.
 *
 * @param[in] s
 *      The string to be measured.
 *
 * @return
 * The integer length of @p s.
 */
size_t strlength(const char *s) {
  size_t len = 0;
  for (; *s; ++s, ++len) {};

  return len;
}

/**
 * @brief Copies a string from src to dst.
 *
 * Takes source and destination as input and copies
 * the string over. The buffer for the destination
 * needs to be accounted for by the programmer.
 *
 * @param[in]      src The string to be copied.
 * @param[in, out] dst Where the string will be copied.
 *
 * @return Returns a pointer to the destination
 */
char *strcopy(const char *src, char *dst) {
  char *p = dst; // Temp pointer to not increment the original.
  while ((*p++ = *src++) != '\0') {};

  return dst;
}

void test_string_copy() {
  const char *s1 = "String to be copied.";
  char *s2 = malloc(strlength(s1) + 1);

  assert(strcopy(s1, s2) == s2); // Check if both point to the same location.
  assert(strlength(s1) == strlength(s2)); // Check if lengths are same.
  free(s2);
  puts("Test 1 Passed: Basic string copy.");
}

void run_all_tests() { test_string_copy(); }

int main() {
  run_all_tests();
  return 0;
}
