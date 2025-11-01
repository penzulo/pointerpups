/*
  Bitwise utilities in C
  ----------------------
  This module demonstrates how to:
  - Check if a number is even or odd
  - Get, set, clear, and toggle specific bits
  using only bitwise operations.
*/

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/*
  Returns `true` if the given number is even, else `false`.

  Logic:
    - The least significant bit (LSB) of any even number is 0.
    - The LSB of any odd number is 1.
    - Performing `num & 1` isolates the LSB.
*/
bool is_even(uint32_t num) { return (num & 1) == 0; }

/*
  Returns `true` if the bit at position `index` is set (1), else `false`.

  Logic:
    - Right-shift `num` by `index` bits, moving the target bit to position 0.
    - AND the result with 1 to isolate it.
*/
bool get_bit(uint32_t num, uint8_t index) { return ((num >> index) & 1U) == 1; }

/*
  Sets (turns ON) the bit at position `index` in `num`.

  Logic:
    - Create a mask `1 << index` which has a 1 only at the target bit.
    - Bitwise OR (`|`) sets that bit to 1 without affecting others.
*/
uint32_t set_bit(uint32_t num, uint8_t index) { return num | (1U << index); }

/*
  Clears (turns OFF) the bit at position `index` in `num`.

  Logic:
    - Create a mask `1 << index` that isolates the target bit.
    - Invert it (`~`) so that only that position becomes 0.
    - Bitwise AND (`&`) clears that bit while preserving others.
*/
uint32_t clear_bit(uint32_t num, uint8_t index) { return num & ~(1U << index); }

/*
  Toggles (flips) the bit at position `index` in `num`.

  Logic:
    - Create a mask `1 << index`.
    - Bitwise XOR (`^`) flips that bit:
        - If bit = 0 → becomes 1
        - If bit = 1 → becomes 0
*/
uint32_t toggle_bit(uint32_t num, uint8_t index) { return num ^ (1U << index); }

void test_is_even() {
  assert(is_even(0) == true);
  assert(is_even(1) == false);
  assert(is_even(2) == true);
  assert(is_even(255) == false);
  assert(is_even(1024) == true);
  printf("test_is_even passed.\n");
}

void test_get_bit() {
  assert(get_bit(0b1010, 1) == 1); // bit 1 is set
  assert(get_bit(0b1010, 0) == 0);
  assert(get_bit(0b1111, 3) == 1);
  assert(get_bit(0b0100, 2) == 1);
  assert(get_bit(0b0100, 3) == 0);
  printf("test_get_bit passed.\n");
}

void test_set_bit() {
  assert(set_bit(0b0000, 1) == 0b0010);
  assert(set_bit(0b0010, 1) == 0b0010); // already set
  assert(set_bit(0b0100, 0) == 0b0101);
  printf("test_set_bit passed.\n");
}

void test_clear_bit() {
  assert(clear_bit(0b1111, 2) == 0b1011);
  assert(clear_bit(0b0100, 2) == 0b0000);
  assert(clear_bit(0b0000, 3) == 0b0000); // already clear
  printf("test_clear_bit passed.\n");
}

void test_toggle_bit() {
  assert(toggle_bit(0b0001, 0) == 0b0000); // flip 1→0
  assert(toggle_bit(0b0000, 0) == 0b0001); // flip 0→1
  assert(toggle_bit(0b1010, 1) == 0b1000); // flip bit 1
  assert(toggle_bit(0b1010, 3) == 0b0010); // flip bit 3
  printf("test_toggle_bit passed.\n");
}

void run_all_tests() {
  test_is_even();
  test_get_bit();
  test_set_bit();
  test_clear_bit();
  test_toggle_bit();
  printf("\nAll bitwise tests passed successfully.\n");
}

int main() {
  run_all_tests();
  return 0;
}
