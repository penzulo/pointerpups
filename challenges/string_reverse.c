/*
Reverse a string (in-place).
Write:
  `void reverse(char *str);`
Use pointers only (no array indexing).
BONUS: try reversing only words, not the whole string.
*/
#include <stdio.h>

// NOTE: This is a very clever way to swap characters,
// but the problem here is that if the two input
// characters add up to an int outside the char
// data type's range, then it would cause an overflow
// which is classified as Undefined Behaviour.
void _swap(char *character1, char *character2) {
  *character1 = *character1 + *character2;
  *character2 = *character1 - *character2;
  *character1 = *character1 - *character2;
}

void _swap_safe(char *char1, char *char2) {
  char temp = *char1;
  *char1 = *char2;
  *char2 = temp;
}

void reverse(char *start_ptr) {
  char *end_ptr = start_ptr;
  for (; *(end_ptr + 1); end_ptr++)
    ;

  while (start_ptr != end_ptr) {
    _swap_safe(start_ptr, end_ptr);
    start_ptr++;
    end_ptr--;
  }
}

void test_reverse_name() {
  // WARN: `char *name = "Bhargav"` and `char name[] = "Bhargav"`
  // are not the same! The former creates a string literal and
  // the latter creates a string.
  char name[] = "Bhargav";
  reverse(name);

  printf("Reversed string: %s, Expected: %s\n", name, "vagrahB");
}

void test_reverse_sentence() {
  char sentence[] = "This is a sentence.";
  char *start = &sentence[0];
  reverse(start);

  printf("Reversed string: %s, Expected: %s\n", sentence,
         ".ecnetnes a si sihT.");
}

void run_all_tests() {
  test_reverse_name();
  test_reverse_sentence();
}

int main() {
  run_all_tests();

  return 0;
}
