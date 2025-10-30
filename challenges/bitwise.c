#include <stdint.h>
#include <stdio.h>

/*
 Bitwise AND (&) compares bits of two operands.

 Each bit in result is 1 only if both bits are 1:
   1 & 1 → 1

   1 & 0 → 0

   0 & 1 → 0

   0 & 0 → 0


 Example (8-bit):
   5  = 00000101

   3  = 00000011

   ------------

   &  = 00000001 → 1
*/
uint8_t bitwise_and(uint8_t operand1, uint8_t operand2) {
  return operand1 & operand2;
}

// A function to apply bitwise OR on two operands
uint8_t bitwise_or(uint8_t operand1, uint8_t operand2) {
  return operand1 | operand2;
}

// A function to apply bitwise XOR on two operands
uint8_t bitwise_xor(uint8_t operand1, uint8_t operand2) {
  return operand1 ^ operand2;
}

/*
 Bitwise NOT (~) flips all bits.

 For `uint8_t` (unsigned 8-bit):
   `~x = 255 - x`  → wraps around (0–255 range)

   e.g.  `~5 = 250`,  `~4 = 251`

 For int8_t (signed 8-bit, two’s complement):
   same bits interpreted as negatives

   e.g.  `11111010 = -6`,  `11111011 = -5`

 Printing tip:
   use `%u` for unsigned, `%d` for signed.
*/
uint8_t bitwise_not(uint8_t operand) { return ~operand; }

// A function to apply left shit << on one operand
uint8_t bitwise_left_shift(uint8_t operand, uint8_t pow) {
  return operand << pow;
}

// A function to apply left shit << on one operand
short bitwise_right_shift(short operand, short pow) { return operand << pow; }

int main() {
  const uint8_t num1 = 5;
  const uint8_t num2 = 4;

  printf("%u AND %u = %u.\n", num1, num2, bitwise_and(num1, num2));
  printf("%u OR %u = %u.\n", num1, num2, bitwise_or(num1, num2));
  printf("%u XOR %u = %u.\n", num1, num2, bitwise_xor(num1, num2));
  printf("NOT %u = %u.\nNOT %u = %u.\n", num1, bitwise_not(num1), num2,
         bitwise_not(num2));
  printf("%u << %u = %u.\n", num1, num2, bitwise_left_shift(num1, num2));

  return 0;
}
