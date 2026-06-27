# Handoff: ex7 — Circle.cpp is next

## Situation
Working on C++ Assignment 3 (ex7) — a shapes system. Branch: `ex7-tomer-1`.
All source lives in `ex7/solution/`. Full spec is in CLAUDE.md under `## ex7`.

## What just happened
Tomer implemented `Shape.cpp` from scratch this session. It is **complete and correct**.

## Teaching contract (critical — do not break this)
- Tomer is here to **learn**, not get code handed to him
- **Never write code unless Tomer explicitly asks**
- Teach concepts in plain language first, then let Tomer write, then review
- Point out bugs by explaining the concept — don't fix them directly
- Ask Tomer questions to make him think before giving answers

## Shape.cpp — what was established (Circle must follow same patterns)

### Memory management for `char*`
- `color` is `char*` — dynamically allocated, not `std::string`
- Constructor: `new char[strlen(s) + 1]` then `strcpy`
- Destructor: `delete[] color`
- `setColor` order: **validate first → delete old → allocate new → strcpy**
- Always initialize `color = nullptr` before calling `setColor` (even in parameterized constructor)
  so that `delete[] nullptr` (which is safe) is what fires, not `delete[]` on garbage

### Validation pattern
- Use `strcmp` (not `==`) to compare C-strings
- Check `nullptr` before calling `strcmp` — it crashes on null
- Throw `std::invalid_argument("message")` — never bare `throw;`
- Validate **before** mutating state
- `#include <stdexcept>` required

## Circle.cpp — what needs to be done next

### File to implement
`ex7/solution/Circle.cpp` — currently all stubs returning 0.

### The one new concept: initializer list
Circle's parameterized constructor must call Shape's parameterized constructor.
You **cannot** call a base constructor inside the function body in C++.
It must go in the **initializer list**:

```
Circle::Circle(const char* color, int width, int radius)
    : Shape(color, width), radius(radius) { }
```

This is the main teaching point for Circle. Explain why the initializer list exists
before Tomer writes the constructor.

### What Circle needs to implement
- Default constructor (call Shape default or initialize safely)
- Parameterized constructor (initializer list calling `Shape(color, width)`)
- Destructor (Shape handles `color` via virtual destructor — Circle just needs `{}`)
- `getRadius()` — trivial getter
- `setRadius(int)` — validate > 0, throw if not
- `getPerimeter()` — `2 * M_PI * radius` (need `#include <cmath>` for `M_PI`)
- `getArea()` — `M_PI * radius * radius`

### Math
- Perimeter: 2πr
- Area: πr²
- `M_PI` from `<cmath>`, or define `const double PI = 3.14159265358979`

### What Circle does NOT need
- No `char*` memory management — Shape's destructor handles `color`
- No `draw()` method — Circle has no draw (only Square and OrthogonalTriangle do)
- No `operator<<` — printing is handled in main via getters

## After Circle: what comes next
Square.cpp → OrthogonalTriangle.cpp → Array.h (templates) → main.cpp (RTTI + exceptions)

## How to compile when Circle is done
```powershell
$env:PATH = "C:\Program Files\JetBrains\CLion 2026.1.1\bin\mingw\bin;" + $env:PATH
g++ ex7/solution/Shape.cpp ex7/solution/Circle.cpp ex7/solution/Square.cpp ex7/solution/OrthogonalTriangle.cpp ex7/solution/main.cpp -I ex7/solution -o ex7.exe -std=c++17
```
(Square and OrthogonalTriangle will compile even with stub bodies for now)
