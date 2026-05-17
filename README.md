# Intro to System Programming

This repository contains an exercise implementation for stock management in C.

## Project structure

- `ex3/our_solution/main.c` - main program and menu flow
- `ex3/our_solution/section1.c` - stock addition and validation functions
- `ex3/our_solution/section2.c` - stock printing function
- `ex3/our_solution/stock.h` - shared type definitions and function prototypes

## Build

From `ex3/our_solution`:

```bash
gcc main.c section1.c section2.c -o main
```

Or compile all C files in the folder:

```bash
gcc *.c -o main
```

## Run

```bash
./main
```

## Notes

- Do not `#include "main.c"` from another source file.
- Use `stock.h` to share the `Stock` type and function declarations.
