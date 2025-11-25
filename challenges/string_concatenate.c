/**
 * Program: Custom function to concatenate strings.
 * ---------------------------------------------------------
 * Goal: Implement a `strconcat` function similar to the `strcat`
 * function from the standard library which concatenates a string
 * pointed to by src after the string pointed to by dst.
 */
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Finds the length of a string.
 *
 * Finds the length of a string exclusive of the
 * terminating null character.
 *
 * @param[in] s The string to be measured.
 *
 * @return Returns the found length.
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

/**
 * @brief Appends src after dst into dst.
 *
 * Concatenates the string pointed to by src after
 * the string pointed to by dst replacing it's
 * null terminator. The buffer for the destination
 * needs to be accounted for by the programmer.
 *
 * @param[in]      src The first string.
 * @param[in, out] dst The second string.
 *
 * @return Returns a pointer to the destination.
 */
char *strconcat(const char *src, char *dst) {
  // NOTE: dst = src + dst + `\0`
  strcopy(src, dst + strlength(dst));
  return dst;
}

void test_string_concatenation() {
  const char *s1 = "Hello ";
  const char *s2 = "World!";
  char *destination = malloc(strlength(s1) + strlength(s2) + 1);

  strcopy(s1, destination); // For initialization
  char *result = strconcat(s2, destination);

  // NOTE: Check for correct return value
  assert(result == destination);
  puts("Test 1 passed: Correct result.");

  // NOTE: Check final length
  assert(strlength(destination) == ((strlength(s1) + strlength(s2))));
  puts("Test 2 passed: Corrent resultant length.");

  free(destination);
}

void run_all_tests() { test_string_concatenation(); }

int main() {
  run_all_tests();
  return 0;
}
