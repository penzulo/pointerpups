#ifndef MYLIB_MEMORY_H
#define MYLIB_MEMORY_H

#if defined(__cplusplus)
#define restrict __restrict
#elif !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L
#if defined(__GNUC__) || defined(__clang__) || defined(_MSC_VER)
#define restrict __restrict
#else
#define restrict // Delete it for old compilers
#endif
#endif

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Copies a block of memory from source to destination.
 *
 * A simplified implementation of the standard `memcpy`. It
 * copies data byte-by-byte to ensure safety across all architectures,
 * ignoring potential CPU word-alignment optimizations for stability.
 *
 * @param[in]  src  The place to copy raw bytes from.
 * @param[out] dest The place to paste raw bytes to.
 * @param[in]  n    The number of bytes to copy.
 *
 * @return Pointer to the destination (@p dest).
 *
 * @note Performance Trade-off:
 * This implementation uses a byte-by-byte copy loop (`uint8_t`).
 * While less efficient than copying by the CPU's native word size
 * (e.g., `size_t` on 64-bit systems), it is strictly robust against
 * memory misalignment issues (SIGBUS errors on ARM/RISC) and requires
 * no complex preamble/postamble logic.
 */
void *memcopy(const void *restrict src, void *restrict dest, size_t nbytes);

/**
 * @brief Swaps the contents of two arbitrary memory blocks.
 *
 * Exchanges `size` bytes between `a` and `b`. Instead of allocating
 * a temporary buffer on the heap (which is slow and non-deterministic),
 * this function uses a small, fixed-size stack buffer and swaps the
 * memory in chunks.
 *
 * @param[in, out] a    Pointer to the first memory block
 * @param[in, out] b    Pointer to the second memory block
 * @param[in]      size Total size of the data to swap in bytes.
 *
 * @note Systems Programming Context:
 * - **Heap Avoidance:** `malloc` introduces non-deterministic latency.
 *   In high-performance contexts (like Kernels or HFT), using the stack
 *   ensures a predictable execution time.
 * - **Chunking:** Large objects are broken down into `CHUNK_SIZE` pieces
 *   to fit into the stack buffer, ensuring we don't blow the stack frame
 *   when swapping massive structures.
 */
void swap(void *a, void *b, size_t nbytes);

#endif
