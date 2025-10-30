/*
Write a function `swap(uint8_t *a, uint8_t *b)` that swaps two
integers using pointers. Try both with and without a
`temp` variable.

Test -
```
  uint8_t x = 10, y = 20;
  swap(&x, &y);
  printf("%u %u\n", x, y);
```
*/
#include <assert.h>
#include <stdint.h>
#include <stdio.h>

void swap_with_temp(uint8_t *operand1, uint8_t *operand2) {
  uint8_t temp = *operand1;
  *operand1 = *operand2;
  *operand2 = temp;
}

void swap(uint8_t *operand1, uint8_t *operand2) {
  *operand1 = *operand1 + *operand2;
  *operand2 = *operand1 - *operand2;
  *operand1 = *operand1 - *operand2;
}

void test_swap_with_temp() {
  uint8_t num1 = 10, num2 = 20;
  swap_with_temp(&num1, &num2);
  assert(num1 == 20);
  assert(num2 == 10);
  printf("test_swap_with_temp passed successfully.\n");
}

void test_swap() {
  uint8_t num1 = 10, num2 = 20;
  swap(&num1, &num2);
  assert(num1 == 20);
  assert(num2 == 10);
  printf("test_swap passed successfully.\n");
}

int main() {
  test_swap();
  test_swap_with_temp();

  return 0;
}
