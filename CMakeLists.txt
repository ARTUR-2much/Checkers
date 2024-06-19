cmake_minimum_required(VERSION 3.0)


project(MyProject)

set(CMAKE_CXX_STANDARD 14)

# Add main.cpp
add_executable(main main.cpp)

# Add tests_main.cpp
add_executable(tests tests.cpp)

# Link SFML libraries (adjust the paths as necessary)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(main sfml-graphics sfml-window sfml-system)
target_link_libraries(tests sfml-graphics sfml-window sfml-system)

# Include Doctest
include(FetchContent)
FetchContent_Declare(
  doctest
  GIT_REPOSITORY https://github.com/doctest/doctest
  GIT_TAG v2.4.9
)
FetchContent_MakeAvailable(doctest)
target_link_libraries(tests doctest::doctest)
