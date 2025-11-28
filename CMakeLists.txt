cmake_minimum_required(VERSION 3.10)
project(ImageProcessingLib CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ако искаш малко повече предупреждения:
if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Намираме OpenCV
find_package(OpenCV REQUIRED)

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Либратека (ще добавяме source файлове постепенно)
add_library(imgproc
    src/image.cpp
    src/filters.cpp
)

target_link_libraries(imgproc
    ${OpenCV_LIBS}
)

# Примерно демо
add_executable(demo examples/demo.cpp)
target_link_libraries(demo imgproc)
