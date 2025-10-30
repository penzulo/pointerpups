/*
Implement your own `strlen()` using pointers, not indexing.
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

size_t lenstr(const char *str) {
  size_t len = 0;
  for (; *str; ++str, ++len)
    ;
  // while (*str != '\0') {
  //   len++;
  //   str++;
  // }

  return len;
}

void test_lenstr_empty() {
  const char string[] = "";
  const char *p_string = &string[0];

  const size_t length = lenstr(p_string);
  assert(length == 0);
  printf("Test 1 passed: Empty string length (expected %d, got %zu)\n", 0,
         length);
}

void test_lenstr_non_empty() {
  const char string[] = "Nepal is beautiful.";
  const char *p_string = &string[0];

  const size_t length = lenstr(p_string);
  assert(length == 19);
  printf("Test 2 passed: Non-empty string length (expected, %d, "
         "got %zu)\n",
         19, length);
}

void test_lenstr_special_character() {
  const char string[] = "\nbut bhutan is better.\n";
  const char *p_string = &string[0];

  const size_t length = lenstr(p_string);
  assert(length == 23);
  printf("Test 2 passed: Non-empty string length (expected, %d, "
         "got %zu)\n",
         23, length);
}

void run_all_tests() {
  test_lenstr_empty();
  test_lenstr_non_empty();
  test_lenstr_special_character();
}

int main() {
  run_all_tests();

  return EXIT_SUCCESS;
}
