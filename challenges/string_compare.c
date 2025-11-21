/**
 * Program: Custom Lexicographical String Comparison
 * -------------------------------------------------
 * Goal: Implement a function similar to standard library `strcmp`
 * and use it to sort an array of strings lexicographically.
 */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

/**
 * @brief Compares two strings.
 *
 * Takes two strings as input and checks for difference.
 * Used for equality checks and lexicographical sorting.
 *
 * @param[in] s1  The first string
 * @param[in] s2  The second string
 *
 * @return Returns an integer
 * - 0:  Both strings are equal
 * - 1:  s1 is greater than s2
 * - -1: s2 is greater than s1
 */
int8_t strcompare(const char *s1, const char *s2) {
  // NOTE: Early exit if pointer aliasing is detected.
  if (s1 == s2)
    return 0;

  while (*s1 != '\0') {
    // NOTE: This condition checks if `s1` is a bigger
    // string in length than `s2`
    if (*s2 == '\0')
      return 1;

    // NOTE: This condition checks if the current character of
    // `s1` is smaller than the current character of `s2`
    if (*s2 > *s1)
      return -1;

    // NOTE: This condition checks if the current character of
    // `s1` is bigger than the current character of `s2`
    if (*s1 > *s2)
      return 1;

    s1++;
    s2++;
  }

  // NOTE: Checks if `s2` is greater than `s1`
  if (*s2 != '\0')
    return -1;

  return 0;
}

void test_compare_equal() {
  const char s1[] = "Word";
  const char s2[] = "Word";

  assert(strcompare(s1, s2) == 0);
  puts("Test 1 Passed: Both strings are equal");
}

void test_compare_greater() {
  const char s1[] = "word";
  const char s2[] = "words";

  assert(strcompare(s1, s2) == -1);
  puts("Test 2 Passed: `s2` is greater than `s1`");
}

void test_compare_empty() {
  const char s1[] = "";
  const char s2[] = "";

  assert(strcompare(s1, s2) == 0);
  puts("Test 3 Passed: Both empty strings are equal");
}

void test_compare_pointer_aliasing() {
  const char sentence[] = "same sentence";

  assert(strcompare(sentence, sentence) == 0);
  puts("Test 4 Passed: Pointer aliasing works.");
}

void run_all_tests() {
  test_compare_equal();
  test_compare_greater();
  test_compare_empty();
  test_compare_pointer_aliasing();
}

int main() {
  run_all_tests();
  return 0;
}
