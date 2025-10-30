# PointerPups

**PointerPups** is a collection of small, focused C programs and excercises designed to help you learn and master low-level programming the fun way.

This is perfect for anyone who has learned the basic syntax of C but wants to build a more practical intuition for its core concepts, especially **pointers**, **memory management**, and **data structures**.

## Prerequisites

Before you begin, you will need to have a C compiler and `make` installed.

* **Compiler:** `gcc` or `clang`
* **Build Tool:** `make`
* **Version Control:** `git`

## Project Goals
* Learn and practice **modern C (C17)** concepts through small, practical programs.
* Understand **how memory, types, and pointers work** under the hood.
* Create a **future ncurses-based TUI** to browse and run challenges interactively.
* Build confidence writing clean, modular and testable C code.

## Building
Compile all challenges at once:
```bash
make
```
This will produce one executable per `.c` file in `challenges/`, stored in `bin/`.

Build a single program manually:
```bash
make bin/string_length
```

Clean Everything:
```bash
make clean
```

## Running a Program
You can run any compiled program directly:
```bash
./bin/bitwise
```
Or, in the future, launch the upcoming PointerPups TUI to explore them all interactively.


## Testing
Each program is self-contained and includes:
* Assertions (`assert()`) for correctness.
* Printouts to verify behaviour.
* Optional experiments to explore undefined behaviour and safe practices.

## Contributing
Contributions are welcome!

Whether you want to fix a bug, add a new challenge, or improve documentation open a pull request and help more pups learn to chase pointers safely.

## License
MIT License - free to learn, free to share.
