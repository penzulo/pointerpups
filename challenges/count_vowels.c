/*
Write a function:
  `size_t count_vowels(const char *s);`
It should return how many vowels are in the string.
Don't use indexing `s[i]`; use pointer arithmetic `*s++`;
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

size_t count_vowels(const char *str) {
  size_t total = 0;

  for (; *str != '\0'; str++) {
    // A better way to do this would be to use a HashMap.
    // HashMaps are excluded here as the are out of this
    // code's scope.
    switch (*str) {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      total += 1;
    }
  }

  return total;
}

void test_count_vowels_all_uppercase() {
  const char string[] = "BHARGAV";
  const char *p_string = &string[0];

  assert(count_vowels(p_string) == 2);
  printf("Test 1 passed: [uppercase] Vowels counted successfully.\n");
}

void test_count_vowels_all_lowercase() {
  const char string[] = "bhargav";
  const char *p_string = &string[0];

  assert(count_vowels(p_string) == 2);
  printf("Test 2 passed: [lowercase] Vowels counted successfully.\n");
}

void test_count_vowels_mixed_case() {
  const char string[] = "AkAnkShA";
  const char *p_string = &string[0];

  assert(count_vowels(p_string) == 3);
  printf("Test 2 passed: [mixedcase] Vowels counted successfully.\n");
}

void test_count_vowels_empty() {
  const char string[] = "";
  const char *p_string = &string[0];

  assert(count_vowels(p_string) == 0);
  printf("Test 2 passed: [mixedcase] Vowels counted successfully.\n");
}

void run_all_tests() {
  printf("\n=== Running Unit Tests ===\n");
  test_count_vowels_all_uppercase();
  test_count_vowels_all_lowercase();
  test_count_vowels_mixed_case();
  test_count_vowels_all_uppercase();
  printf("=== All Tests Passed ===\n\n");
}

int main() {
  run_all_tests();

  return EXIT_SUCCESS;
}
