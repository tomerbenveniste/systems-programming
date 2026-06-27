# Handoff: ex7 — OrthogonalTriangle.cpp is next

## Situation
Working on C++ Assignment 3 (ex7) — a shapes system. Branch: `ex7-tomer-1`.
All source lives in `ex7/solution/`. Full spec is in CLAUDE.md under `## ex7`.

## What just happened
Tomer implemented `Square.cpp` this session. It is **complete and correct**.
Concepts covered: initializer list calling base constructor, nested loops for `draw()`, `(int)` cast for floor behavior.
Also fixed: `Circle.cpp` needed `#define _USE_MATH_DEFINES` before `<cmath>` for `M_PI` on Windows/MinGW.

## Teaching contract (critical — do not break this)
- Tomer is here to **learn**, not get code handed to him
- **Never write code unless Tomer explicitly asks**
- Teach concepts in plain language first, then let Tomer write, then review
- Point out bugs by explaining the concept — don't fix them directly
- Ask Tomer questions to make him think before giving answers

## Patterns established (Shape.cpp + Circle.cpp + Square.cpp — OrthogonalTriangle must follow same)

### Memory management
- `color` is `char*` — `new char[]` / `delete[]` manually (Shape handles this)
- Circle/Square/OrthogonalTriangle destructors are empty `{}` — Shape's virtual destructor covers `color`

### Constructor pattern
- Always use initializer list to call base constructor:
  `OrthogonalTriangle::OrthogonalTriangle(const char* color, int width, double side) : Shape(color, width), side(side) {}`
- Default constructor initializes own member to safe value via initializer list:
  `OrthogonalTriangle::OrthogonalTriangle() : side(1.0) {}`

### Validation pattern
- Validate `<= 0`, throw `std::invalid_argument("message")`
- Validate **before** mutating state
- `#include <stdexcept>` required

### Include pattern
- `#include <cmath>` for math functions — on Windows/MinGW also needs `#define _USE_MATH_DEFINES` BEFORE the include

## OrthogonalTriangle.cpp — what needs to be done next

### File to implement
`ex7/solution/OrthogonalTriangle.cpp` — currently all stubs.

### What OrthogonalTriangle needs to implement
- Default constructor (initializer list, safe side value of 1.0)
- Parameterized constructor (initializer list calling `Shape(color, width)`)
- Destructor (empty `{}`)
- `getSide()` — trivial getter
- `setSide(double)` — validate > 0, throw if not
- `getPerimeter()` — `side * (2 + sqrt(2))`
- `getArea()` — `side * side / 2`
- `draw()` — staircase of `*` characters

### The new concept: draw() staircase pattern
`draw()` prints a right-triangle staircase. Row `i` (1-indexed) prints `i` asterisks.
Since `side` is a `double`, use `(int)side` to get the integer row count.

```
// For side = 3.0, output is:
*
**
***
```

One outer loop (rows 1 to `(int)side`), one inner loop (cols 1 to current row number).
Print `*` each inner iteration, `\n` after each outer iteration.

### Math
- Perimeter: `side * (2 + sqrt(2))` — needs `<cmath>` and `_USE_MATH_DEFINES`
- Area: `side * side / 2`

### What OrthogonalTriangle does NOT need
- No `char*` memory management — Shape's destructor handles `color`

## After OrthogonalTriangle: what comes next
Array.h (templates) → main.cpp (RTTI + exceptions)

## How to compile when done
```powershell
$env:PATH = "C:\Program Files\JetBrains\CLion 2026.1.1\bin\mingw\bin;" + $env:PATH
g++ ex7/solution/Shape.cpp ex7/solution/Circle.cpp ex7/solution/Square.cpp ex7/solution/OrthogonalTriangle.cpp ex7/solution/main.cpp -I ex7/solution -o ex7.exe -std=c++17
```
(Array linker errors from main.cpp are expected until Array.h is implemented)
