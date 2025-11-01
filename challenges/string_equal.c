/*
Implement your own `strequal()` to check
if two strings are equal or not.
Use only pointers, no array indexing.
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// This function does NOT include the lexicographical
// cases which are needed for sorting.
bool strequal(const char *string1, const char *string2) {
  // Early exit if pointer aliasing is detected.
  // NOTE: Pointer aliasing means that both the pointers
  // are either same or point to the same memory, in
  // which case string comparison will always return
  // true.
  if (string1 == string2)
    return true;

  while (*string1 != '\0') {
    // If either the second string ends or the
    // dereferenced content does not match, return
    // false.
    if (*string2 == '\0' || *string1 != *string2)
      return false;

    string1++;
    string2++;
  }
  return true;
}

void test_compare_equal() {
  const char s1[] = "Word";
  const char s2[] = "Word";

  assert(strequal(s1, s2));
  printf("Test 1 Passed: Both strings are equal\n");
}

void test_compare_unequal() {
  const char s1[] = "Equal";
  const char s2[] = "Unequal";

  assert(!strequal(s1, s2));
  printf("Test 2 Passed: Both strings are unequal\n");
}

void test_compare_empty() {
  const char s1[] = "";
  const char s2[] = "";

  assert(strequal(s1, s2));
  printf("Test 3 Passed: Both empty strings are equal\n");
}

void test_compare_case_sensitive() {
  const char s1[] = "word";
  const char s2[] = "WORD";

  assert(!strequal(s1, s2));
  printf("Test 4 Passed: Case sensitive comparison works.\n");
}

void test_compare_pointer_aliasing() {
  const char sentence[] = "same sentence";

  assert(strequal(sentence, sentence));
  printf("Test 5 Passed: Pointer aliasing works.\n");
}

void test_compare_long_strings() {
  char s1[1001], s2[1001];

  memset(s1, 'A', 1000);
  memset(s2, 'A', 999);

  s1[1000] = '\0';
  s2[999] = '\0';

  assert(!strequal(s1, s2));
  printf("Test 6 Passed: Long string stress test passed.\n");
}

void run_all_tests() {
  test_compare_equal();
  test_compare_unequal();
  test_compare_empty();
  test_compare_case_sensitive();
  test_compare_pointer_aliasing();
  test_compare_long_strings();
}

int main() {
  run_all_tests();

  return 0;
}
