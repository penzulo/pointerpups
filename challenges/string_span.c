/**
 * Program: Custom `strspan` function
 * ----------------------------------
 * Create a `strspn` function which is similar to the
 * standard libraries `strspn` function. Optimization
 * is optional for now.
 */
#define size_t unsigned long
#define MODE_SET 0
#define MODE_CHECK 1
#define BITS (8 * sizeof(size_t))

/* NOTE: This is the exact opposite of optimization as it
 * makes use of auxillary variables like index, offset and mask.
 * But using this function makes the bitwise operations much
 * clearer to understand.
 */
int bitop(size_t *bitmap, unsigned char c, unsigned short mode) {
  size_t index = c / BITS;
  size_t offset = c % BITS;
  size_t mask = (size_t)1 << offset;

  if (mode == MODE_SET) {
    bitmap[index] |= mask;
    return 1;
  }

  /* NOTE: `!!` is supposed to normalize the return
   * value of the bitwise operation between 0 and 1.
   */
  return !!(bitmap[index] & mask);
}

size_t strspan(const char *accept, const char *space) {
  size_t bitmap[32 / sizeof(size_t)] = {0};
  const char *counter = space;

  for (; *accept && bitop(bitmap, *accept, MODE_SET); accept++) {};
  for (; *counter && bitop(bitmap, *counter, MODE_CHECK); counter++) {};

  return space - counter;
}
