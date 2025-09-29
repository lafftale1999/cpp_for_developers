cmake_minimum_required(VERSION 3.16)
project(cmake_project_template CXX)

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Sources: main.cpp + all cpp files in src/
set(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
file(GLOB SRC_SRC CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
list(APPEND SOURCES ${SRC_SRC})

add_executable(main ${SOURCES})

# Headers from include/
target_include_directories(main PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Warnings (treat-as-errors on GCC/Clang; on MSVC keep warnings but not as errors for beginners)
if(MSVC)
  target_compile_options(main PRIVATE /W4 /Zi /WX- /wd4458)
else()
  target_compile_options(main PRIVATE -g -Wall -Werror)
endif()

# command to run the program
add_custom_target(run
  COMMAND $<TARGET_FILE:main>
  DEPENDS main
)