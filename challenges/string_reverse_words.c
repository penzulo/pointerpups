/*
Reverse all words inside a string (in-place)
Write:
  `void reverse_words(char *start);`
Use pointers only (no array indexing)
*/
#include <stdio.h>

void reverse_range(char *start, char *end) {
  while (end > start) {
    char tmp = *start;
    // Swap contents and increment start in one place.
    *start++ = *end;
    // Swap contents and decrement end in one place.
    *end-- = tmp;
  }
}

void reverse(char *start) {
  char *ws = NULL;
  char *cursor = start;

  while (*cursor) {
    if (ws == NULL && *cursor != ' ')
      ws = cursor;

    if (ws && (*(cursor + 1) == ' ' || *(cursor + 1) == '\0')) {
      // NOTE: Apparently the expected behaviour here is that
      // when we pass these pointers to this function, we
      // don't pass the pointers directly, but we pass clones
      // which means that the pointers in this current scope
      // remain unchanged. Hence cursor's position isn't
      // messed with.
      reverse_range(ws, cursor);
      ws = NULL;
    }

    cursor++;
  }
}

void test_reverse_char() {
  char str[] = "a";
  reverse(&str[0]);

  printf("Reversed string: %s, Expected: %s\n", str, "a");
}

void test_reverse_word() {
  char name[] = "Bhargav";
  reverse(&name[0]);

  printf("Reversed string: %s, Expected: %s\n", name, "vagrahB");
}

void test_reverse_sentence() {
  char sentence[] = "This is a sentence.";
  reverse(&sentence[0]);

  printf("Reversed string: %s, Expected: %s\n", sentence,
         "sihT si a .ecnetnes");
}

void test_reverse_untrimmed_sentence() {
  char sentence[] = " word string ";
  reverse(&sentence[0]);

  printf("Reversed string: %s, Expected: %s\n", sentence, " drow gnirts ");
}

void run_all_tests() {
  test_reverse_char();
  test_reverse_word();
  test_reverse_sentence();
  test_reverse_untrimmed_sentence();
}

int main() {
  run_all_tests();

  return 0;
}
