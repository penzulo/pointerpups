#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

int main(void) {
  printf("sizeof(char)         = %zu\n", sizeof(char));      // 1 byte
  printf("sizeof(uint8_t)      = %zu\n", sizeof(uint8_t));   // 1 byte
  printf("sizeof(short)        = %zu\n", sizeof(short));     // 2 bytes
  printf("sizeof(int)          = %zu\n", sizeof(int));       // 4 bytes
  printf("sizeof(long)         = %zu\n", sizeof(long));      // 8 bytes
  printf("sizeof(long long)    = %zu\n", sizeof(long long)); // 8 bytes
  printf("sizeof(size_t)       = %zu\n", sizeof(size_t));    // 8 bytes
  printf("sizeof(uintptr_t)    = %zu\n", sizeof(uintptr_t)); // 8 bytes
}
