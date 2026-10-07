# Systems Programming — BGU ECE

Coursework from *Introduction to Systems Programming* (20937), Ben-Gurion University of the Negev.
The course covers C, C++, and Linux, progressing from procedural C to object-oriented C++ with templates and RTTI.

---

## Exercises

### ex1–ex2 · UNIX fundamentals
Shell, file system, processes, and signals. Submitted as written assignments; no compiled source in this repo.

### ex3 · Stock Management — C
Menu-driven CLI for managing a portfolio of stocks. Demonstrates modular C design: shared header (`stock.h`), separate translation units per feature (add, print, update, validate).

```bash
cd ex3/our_solution
gcc *.c -o stocks && ./stocks
```

### ex4 · C data manipulation
Pointer arithmetic, dynamic memory, and string operations.

### ex5 · Stack & Queue — C++
Integer `Stack` built on a singly linked list of `StackNode`s, implementing the Rule of Three (deep-copying copy constructor, self-assignment-safe assignment operator, destructor) plus overloaded `+`, `+=`, `==` and `<<`. Integer `MyQueue` is a fixed-capacity ring buffer: the front index wraps around the buffer instead of shifting elements, so enqueue, dequeue and peek are all O(1). Interactive `Menu` class drives user input.

```bash
cd ex5/solution
mkdir build && cd build
cmake .. && make
./ex5_solution
```

### ex6 · Shopping System — C++ OOP (Assignment 2)
Polymorphic customer model:

| Class | Key features |
|---|---|
| `Customer` | Base class · `ShoppingCart` member · `virtual add_to_cart` |
| `BusinessCustomer` | Derived · overrides `add_to_cart` with bulk-discount logic |
| `ShoppingCart` | `operator<<`, `operator+=`, `operator==` · `std::vector<Product>` |
| `Product` | Value type with price, quantity, name |
| `Supplier` | Manages stock and price updates |

```bash
cd ex6/solution
mkdir build && cd build
cmake .. && make
./ex6_solution
./test_business   # standalone checks: business discount, cart clear, supplier profit
```

### ex7 · Shapes Hierarchy — C++ OOP (Assignment 3)
Abstract base class with pure-virtual interface, RTTI dispatch, and a hand-rolled generic container:

| Class / Template | Key features |
|---|---|
| `Shape` (abstract) | Dynamic `char* color` with deep-copying (protected) copy constructor and assignment · virtual destructor · `getPerimeter()` / `getArea()` pure-virtual |
| `Circle` | `M_PI`-based area and perimeter |
| `Square` | Side-length geometry |
| `OrthogonalTriangle` | Pythagorean hypotenuse |
| `Array<T>` | Manual `new[]`/`delete[]` · deep-copying copy constructor · copy-and-swap assignment operator · bounds-checked `operator[]` |

`dynamic_cast` is used for RTTI-based type identification at runtime.

```bash
cd ex7/solution
mkdir build && cd build
cmake .. && make
./solution
```

---

## C++ concepts covered

- Rule of Three (copy constructor, copy-assignment, destructor)
- Operator overloading (`==`, `<<`, `+=`)
- Polymorphic inheritance and `virtual` dispatch
- Abstract base classes with pure-virtual interfaces
- RTTI — `dynamic_cast` for runtime type identification
- Hand-rolled generic containers (`Array<T>`) with manual memory management
- Exception-based input validation

---

## Build requirements

- GCC / G++ with C++17 support
- CMake ≥ 3.10 (for ex5–ex7; each `solution/` folder has its own `CMakeLists.txt`)
- Linux or WSL recommended; CLion/MinGW also works on Windows
