cmake_minimum_required(VERSION 3.10)
project(ex6_solution CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# shared classes, compiled once and linked into both programs
add_library(shop STATIC
    Customer.cpp
    Menu.cpp
    Product.cpp
    ShoppingCart.cpp
    Supplier.cpp
)
target_compile_options(shop PRIVATE -Wall -Wextra)

add_executable(ex6_solution assignment2.cpp)
target_link_libraries(ex6_solution PRIVATE shop)

# standalone checks for BusinessCustomer: discount math, cart clear, supplier profit
add_executable(test_business test_business.cpp)
target_link_libraries(test_business PRIVATE shop)
