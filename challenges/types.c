#include <stdint.h>
#include <stdio.h>

void get_primitive_types_size() {
  printf("\n=== primitive types ===\n");
  // WARN: Illegal operation
  // printf("void         = %zu\n", sizeof(void));

  // NOTE: Size of the pointer dependes on the architecture
  // of the host. 16-bit -> 2 bytes, 32-bit -> 4 bytes, 64-bit -> 8 bytes.
  printf("char         = %zu\n", sizeof(char));
  printf("short        = %zu\n", sizeof(short));
  printf("int          = %zu\n", sizeof(int));
  printf("long         = %zu\n", sizeof(long));
  printf("long long    = %zu\n", sizeof(long long));
  printf("size_t       = %zu\n", sizeof(size_t));
  printf("=== primitive types ===\n");
}

void get_stdint_types_size() {
  printf("\n=== stdint types ===\n");
  printf("uint8_t      = %zu\n", sizeof(uint8_t));
  printf("uint16_t     = %zu\n", sizeof(uint16_t));
  printf("uint32_t     = %zu\n", sizeof(uint32_t));
  printf("uint64_t     = %zu\n", sizeof(uint64_t));

  printf("int8_t       = %zu\n", sizeof(int8_t));
  printf("int16_t      = %zu\n", sizeof(int16_t));
  printf("int32_t      = %zu\n", sizeof(int32_t));
  printf("int64_t      = %zu\n", sizeof(int64_t));
  printf("=== stdint types ===\n");
}

int main() {
  get_primitive_types_size();
  get_stdint_types_size();

  return 0;
}
