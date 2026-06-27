# Handoff: ex7 — Square.cpp is next

## Situation
Working on C++ Assignment 3 (ex7) — a shapes system. Branch: `ex7-tomer-1`.
All source lives in `ex7/solution/`. Full spec is in CLAUDE.md under `## ex7`.

## What just happened
Tomer implemented `Circle.cpp` this session. It is **complete and correct**.
Concepts covered: initializer list for calling base constructor, `M_PI` from `<cmath>`.

## Teaching contract (critical — do not break this)
- Tomer is here to **learn**, not get code handed to him
- **Never write code unless Tomer explicitly asks**
- Teach concepts in plain language first, then let Tomer write, then review
- Point out bugs by explaining the concept — don't fix them directly
- Ask Tomer questions to make him think before giving answers

## Patterns established (Shape.cpp + Circle.cpp — Square must follow same)

### Memory management
- `color` is `char*` — `new char[]` / `delete[]` manually (Shape handles this)
- Circle/Square destructors are empty `{}` — Shape's virtual destructor covers `color`

### Constructor pattern
- Always use initializer list to call base constructor:
  `Square::Square(const char* color, int width, double side) : Shape(color, width), side(side) {}`
- Default constructor initializes own member to a safe value via initializer list
  `Square::Square() : side(1.0) {}`

### Validation pattern
- Validate `<= 0`, throw `std::invalid_argument("message")`
- Validate **before** mutating state
- `#include <stdexcept>` required

## Square.cpp — what needs to be done next

### File to implement
`ex7/solution/Square.cpp` — currently all stubs.

### What Square needs to implement
- Default constructor (initializer list, safe side value)
- Parameterized constructor (initializer list calling `Shape(color, width)`)
- Destructor (empty `{}`)
- `getSide()` — trivial getter
- `setSide(double)` — validate > 0, throw if not
- `getPerimeter()` — `4 * side`
- `getArea()` — `side * side`
- `draw()` — prints a grid of `*` characters, `(int)side` rows × `(int)side` columns

### The one new concept: draw() with nested loops
`draw()` prints a filled square of asterisks based on `side`.
Since `side` is a `double`, use `(int)side` to get the integer dimension (floor behavior).

```
// For side = 3.0, output is:
***
***
***
```

Two nested `for` loops: outer = rows (0 to (int)side), inner = columns (0 to (int)side).
Print `*` each inner iteration, `\n` after each outer iteration.

### Math
- Perimeter: 4 * side
- Area: side * side
- No `<cmath>` needed — no π involved

### What Square does NOT need
- No `char*` memory management — Shape's destructor handles `color`
- No `M_PI` — Square math is pure arithmetic

## After Square: what comes next
OrthogonalTriangle.cpp → Array.h (templates) → main.cpp (RTTI + exceptions)

## How to compile when Square is done
```powershell
$env:PATH = "C:\Program Files\JetBrains\CLion 2026.1.1\bin\mingw\bin;" + $env:PATH
g++ ex7/solution/Shape.cpp ex7/solution/Circle.cpp ex7/solution/Square.cpp ex7/solution/OrthogonalTriangle.cpp ex7/solution/main.cpp -I ex7/solution -o ex7.exe -std=c++17
```
(OrthogonalTriangle will compile with stub bodies)
