/*
 * Program: Dyanamic String Sorter
 * 1. Reads arbitrary strings from stdin
 * 2. Stores them in a dynamically allocated array (char **)
 * 2.1 (BONUS) Sort them lexicographically.
 * 3. Frees all allocated memory.
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
  char **strings = NULL;    // Pointer to array which holds pointers to strings.
  char buffer[BUFFER_SIZE]; // Temporary storage for input.
  size_t count = 0;         // Current number of strings.

  puts("Enter strings (empty line to stop):\n");

  while (1) {
    // Read line from `stdin`. Break on EOF or error.
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
      break;

    // Here, 0 and `\0` are exactly the same.
    // `0` is an int literal with value zero.
    // `\0` is a character literal that also has the value zero.
    // Assigning either on to a `char` produces the same byte
    // value: the null terminator
    buffer[strcspn(buffer, "\n")] = 0;

    if (strlen(buffer) == 0)
      break;

    // `realloc` returns a pointer and one must store (or check) it
    // because it may move the memory block.
    // This pattern prevents losing the original pointer if
    // the allocation fails.
    char **temp = realloc(strings, (count + 1) * sizeof(char *));

    if (temp == NULL) {
      perror("Failed to allocate memory.");
      break;
    }

    // If the reallocation is successful, then only we change
    // the original pointer's value.
    strings = temp;

    // We store the pointer returned by `malloc` in the
    // `strings` array for later use.
    strings[count] = malloc(strlen(buffer) + 1);

    if (strings[count] == NULL) {
      perror("Failed to allocate memory for string.");
      break;
    }

    // We then copy the content inside the buffer into
    // the address pointed by the pointer.
    strcpy(strings[count], buffer);
    count++;
  }

  puts("\nYou entered:\n");
  for (size_t i = 0; i < count; i++) {
    printf("%s\n", strings[i]);
    free(strings[i]); // free each string
  }

  free(strings);
  return 0;
}
