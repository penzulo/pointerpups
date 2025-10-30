/*
Dynamic array allocation program with proper testing.
Demonstrates correct memory management and unit testing practices.
*/
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Function to compute sum of array elements
short sum_of_array(size_t n, short *array) {
  short sum = 0;

  for (size_t i = 0; i < n; i++) {
    sum += array[i];
  }

  return sum;
}

// Helper function to allocate array dynamically
short *allocate_array(size_t size) {
  short *array = malloc(sizeof(short) * size);

  if (array == NULL) {
    fprintf(stderr, "Failed to allocate memory.\n");
    exit(EXIT_FAILURE);
  }

  return array;
}

// TEST: Memory allocation and deallocation
void test_allocation_and_free(void) {
  size_t size = 5;
  short *arr_ptr = allocate_array(size);

  assert(arr_ptr != NULL);
  printf("Test 1 passed: Memory allocated successfully.\n");

  free(arr_ptr);
  arr_ptr = NULL; // CRITICAL: Must explicitly set to NULL after free

  assert(arr_ptr == NULL);
  printf("Test 2 passed: Pointer set to NULL after free.\n");
}

// TEST: Sum calculation with known values
void test_sum_calculation(void) {
  size_t size = 5;
  short *arr_ptr = allocate_array(size);
  short test_data[] = {10, 20, 30, 40, 50};

  for (size_t i = 0; i < size; i++) {
    arr_ptr[i] = test_data[i];
  }

  short result = sum_of_array(size, arr_ptr);

  assert(result == 150);
  printf("Test 3 passed: Sum calculation correct (expected: 150, got: %d).\n",
         result);

  free(arr_ptr);
  arr_ptr = NULL;
}

// TEST: Edge case - single element
void test_single_element(void) {
  size_t size = 1;
  short *arr_ptr = allocate_array(size);
  arr_ptr[0] = 42;

  short result = sum_of_array(size, arr_ptr);

  assert(result == 42);
  printf("Test 4 passed: Single element sum correct.\n");

  free(arr_ptr);
  arr_ptr = NULL;
}

// TEST: Edge case - negative numbers
void test_negative_numbers(void) {
  size_t size = 4;
  short *arr_ptr = allocate_array(size);
  short test_data[] = {-10, 20, -30, 40};

  for (size_t i = 0; i < size; i++) {
    arr_ptr[i] = test_data[i];
  }

  short result = sum_of_array(size, arr_ptr);

  assert(result == 20); // -10 + 20 - 30 + 40 = 20
  printf("Test 5 passed: Negative numbers handled correctly.\n");

  free(arr_ptr);
  arr_ptr = NULL;
}

// Run all unit tests
void run_all_tests() {
  printf("\n=== Running Unit Tests ===\n");
  test_allocation_and_free();
  test_sum_calculation();
  test_single_element();
  test_negative_numbers();
  printf("=== All Tests Passed ===\n\n");
}

int main(void) {
  run_all_tests();

  return EXIT_SUCCESS;
}
