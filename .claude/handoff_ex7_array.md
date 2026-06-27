# Handoff: ex7 — Array.h is next

## Situation
Working on C++ Assignment 3 (ex7) — a shapes system. Branch: `ex7-tomer-1`.
All source lives in `ex7/solution/`. Full spec is in CLAUDE.md under `## ex7`.

## What just happened
Tomer implemented `OrthogonalTriangle.cpp` this session. It is **complete and correct**.
Concepts covered: initializer list calling base constructor, nested loops for `draw()` staircase, `(int)` cast for floor behavior, `invalid_argument` for validation, calling `setSide()` from the parameterized constructor (not bypassing validation in initializer list).
All four shape classes (Shape, Circle, Square, OrthogonalTriangle) compile clean with zero errors.

## Teaching contract (critical — do not break this)
- Tomer is here to **learn**, not get code handed to him
- **Never write code unless Tomer explicitly asks**
- Teach concepts in plain language first, then let Tomer write, then review
- Point out bugs by explaining the concept — don't fix them directly
- Ask Tomer questions to make him think before giving answers

## Patterns established (all .cpp files done — Array.h must follow same)

### Exception pattern
- Validation errors throw `std::invalid_argument` (NOT `out_of_range`)
- `#include <stdexcept>` required wherever exceptions are thrown

### Constructor pattern
- Parameterized constructors call setters in the body (not bypassing validation in initializer list)
- Default constructors use initializer list to set safe values

### Memory management
- `color` is `char*` in Shape — handled by Shape's virtual destructor
- Derived class destructors are empty `{}`

## Array.h — what needs to be done next

### File to implement
`ex7/solution/Array.h` — currently declared only, no implementation.
**Template classes must be fully implemented in the `.h` file** — this is the key new concept.

### Why implementation lives in .h (explain this to Tomer before he writes)
Templates are not compiled into object code when the compiler first sees them.
The compiler generates code only when it sees `Array<Shape*>` or `Array<int>` used somewhere.
At that point it needs the full implementation — not just the declaration.
If the implementation were in a `.cpp`, it wouldn't be visible at instantiation time → linker error.
This is different from regular classes where `.h` declares, `.cpp` defines.

### What Array<T> needs (from CLAUDE.md spec)
```cpp
// Array<T> is a hand-rolled dynamic array — no vector allowed
template <typename T>
class Array {
private:
    T* data;       // pointer to heap-allocated array
    int size;      // current number of elements
public:
    Array();                    // size=0, data=nullptr
    ~Array();                   // delete[] data
    void add(T element);        // resize by 1, append element
    void remove(int index);     // remove at index, shift left, resize by 1
    T& operator[](int index);   // bounds-check, throw if out of range
    int getSize() const;
};
```

### Key concepts to teach for each method
- `add()`: allocate new array of size+1, copy old elements, append new one, `delete[]` old, update pointer and size
- `remove()`: similar — allocate new array of size-1, copy skipping the removed index, `delete[]` old
- `operator[]`: check `index < 0 || index >= size`, throw `std::out_of_range` if so (this IS the right exception — it's an index bounds check)
- Destructor: `delete[] data` (not `delete data` — it's an array)

### New concept: `out_of_range` vs `invalid_argument`
- `invalid_argument` → bad value for a parameter (negative side, invalid color)
- `out_of_range` → index exceeds valid range (accessing element 5 of a 3-element array)
- `operator[]` is the ONE place in this assignment where `out_of_range` is correct

### Template syntax reminder
```cpp
template <typename T>
void Array<T>::add(T element) { ... }
```
Every method definition needs `template <typename T>` above it and `Array<T>::` as the class qualifier.

### How Array is used in main.cpp
- `Array<Shape*>` — stores pointers to heap-allocated shapes
- `dynamic_cast<Square*>(arr[i])` to check if element is a Square and call `draw()`
- Bounds-check throw from `operator[]` caught in main's try/catch

## After Array.h: what comes next
`main.cpp` — menu implementation using `Array<Shape*>`, `dynamic_cast` (RTTI), `try/catch` for input retrying

## How to compile when done
```powershell
$env:PATH = "C:\Program Files\JetBrains\CLion 2026.1.1\bin\mingw\bin;" + $env:PATH
g++ ex7/solution/Shape.cpp ex7/solution/Circle.cpp ex7/solution/Square.cpp ex7/solution/OrthogonalTriangle.cpp ex7/solution/main.cpp -I ex7/solution -o ex7.exe -std=c++17
```
(main.cpp linker errors expected until both Array.h AND main.cpp TODOs are filled in)
