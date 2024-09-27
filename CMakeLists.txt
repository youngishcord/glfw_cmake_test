cmake_minimum_required(VERSION 3.10)
project(my_project C)

set(CMAKE_C_STANDARD 99)

# Укажите путь к установленной GLFW через MSYS2
set(GLFW3_DIR "C:/msys64/mingw64/include")
find_package(GLFW3 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(deps)

# Укажите директорию исходного кода
add_executable(my_project main.c)

# Свяжите библиотеку GLFW с вашим проектом
target_link_libraries(my_project PRIVATE glfw OpenGL::GL)