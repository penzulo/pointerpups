/**
 * Program: Custom `strtoken` function to tokenize strings.
 * --------------------------------------------------------
 * Goal: Implement a `strtoken` function similar to the
 * `strtok` function from the standard library which breaks
 * a string into a sequence of zero or more tokens based on
 * a set of delimeters.
 */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MODE_SET 0
#define MODE_CHECK 1
#define BITS (8 * sizeof(size_t))

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
 * of @p space which consists entirely of bytes in @p accept.
 *
 * @param[in] space
 *      String to perform the function on.
 *
 * @param[in] accept
 *      Acceptable array of characters.
 *
 * @return
 * - Difference in index between the first character not in
 *   @p accept and the start of the substring.
 *
 * @note
 * - This function modifies @p accept to point to it's end.
 */
size_t strspan(const char *space, const char *accept) {
  size_t bitmap[32 / sizeof(size_t)] = {0};
  const char *counter = space;

  for (; *accept && bitop(bitmap, *(uint8_t *)accept, MODE_SET); accept++) {};
  for (; *counter && bitop(bitmap, *(uint8_t *)counter, MODE_CHECK);
       counter++) {};

  return counter - space;
}

/**
 * @brief Get length of a substring
 *
 * Calculates the length (in bytes) of the initial segment
 * of @p space which entirely of bytes NOT in @p reject.
 *
 * @param[in] space
 *      String to perform the function on.
 *
 * @param[in] reject
 *      Rejectable array of characters.
 *
 * @return
 * - Difference in index between the first character not in
 *   @p accept and the start of the substring.
 */
size_t strcspan(const char *space, const char *reject) {
  size_t bitmap[32 / sizeof(size_t)] = {0};
  const char *counter = space;

  for (; *reject && bitop(bitmap, *(uint8_t *)reject, MODE_SET); reject++) {};
  for (; *counter && !bitop(bitmap, *(uint8_t *)counter, MODE_CHECK);
       counter++) {};

  return counter - space;
}

char *strtoken(char *str, const char *delim, char **checkpoint) {
  char *current = str ? str : *checkpoint;

  if (!current)
    return NULL;

  // 1. Skip leading delimiters.
  current += strspan(current, delim);

  // 2. Check for end of string
  if (!*current) {
    *checkpoint = NULL;
    return NULL;
  }

  // 3. Find end of token
  *checkpoint = current + strcspan(current, delim);

  // 4. Terminate token and advance checkpoint
  if (**checkpoint) {
    **checkpoint = '\0';
    *checkpoint += 1;
  } else {
    *checkpoint = NULL;
  }

  return current;
}

void test_standard_case() {
  char text[] = "Bhargav;;;20;;Deshpande";
  char *saveptr = NULL;

  char *token = strtoken(text, ";", &saveptr);
  assert(strcmp(token, "Bhargav") == 0);

  token = strtoken(NULL, ";", &saveptr);
  assert(strcmp(token, "20") == 0);

  token = strtoken(NULL, ";", &saveptr);
  assert(strcmp(token, "Deshpande") == 0);

  token = strtoken(NULL, ";", &saveptr);
  assert(token == NULL);

  puts("Test 1 Passed: Standard Case.");
}

void test_leading_delimiter() {
  char text[] = ";;Data";
  char *saveptr = NULL;

  char *token = strtoken(text, ";", &saveptr);
  assert(strcmp(token, "Data") == 0);

  token = strtoken(NULL, ";", &saveptr);
  assert(token == NULL);
  puts("Test 2 Passed: Leading Delimiter.");
}

void test_trailing_delimiter() {
  char text[] = "Data;;";
  char *saveptr = NULL;

  char *token = strtoken(text, ";", &saveptr);
  assert(strcmp(token, "Data") == 0);

  token = strtoken(NULL, ";", &saveptr);
  assert(token == NULL);
  puts("Test 3 Passed: Trailing Delimiter.");
}

void test_no_delimiter() {
  char text[] = "WholeString";
  char *saveptr = NULL;

  char *token = strtoken(text, ";", &saveptr);
  assert(strcmp(token, "WholeString") == 0);

  token = strtoken(NULL, ";", &saveptr);
  assert(token == NULL);
  puts("Test 4 Passed: No Delimiter.");
}

void test_all_delimiter() {
  char text[] = ";;;;;";
  char *saveptr = NULL;

  char *token = strtoken(text, ";", &saveptr);
  assert(token == NULL);
  puts("Test 5 Passed: All Delimiters.");
}

void run_all_tests() {
  test_standard_case();
  test_leading_delimiter();
  test_trailing_delimiter();
  test_no_delimiter();
  test_all_delimiter();
}

int main() {
  run_all_tests();
  return 0;
}
