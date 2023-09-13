cmake_minimum_required(VERSION 3.21)
project(html-parser-demo-c)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

### Options ###
option(CMAKE_BUILD_TYPE "Build type (Debug, Release, Profiling)" "Release")

### Flags ###
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

if (CMAKE_BUILD_TYPE STREQUAL "Profiling")
    SET(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -pg")
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
    SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")
endif()

list(APPEND SOURCE_FILES
    "src/main.c"
    "src/html-example.c"
    )

set(EXECUTABLE_NAME "${PROJECT_NAME}-${CMAKE_BUILD_TYPE}")

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

# Specify the directory where the external dependencies are located.
# The html-parser library is linked to and included here.
set(LIBRARY_DIR ${CMAKE_SOURCE_DIR}/libs)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${LIBRARY_DIR}/html-parser/build/libhtml-parser-Release.a)

target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${LIBRARY_DIR}/html-parser/include)

target_compile_options(${EXECUTABLE_NAME} PRIVATE
    $<$<CONFIG:Debug>:-O0 -g>
    $<$<CONFIG:Release>:-O3>
    $<$<CONFIG:Profiling>:-O2 -pg>
)

target_compile_definitions(${EXECUTABLE_NAME} PRIVATE
    $<$<CONFIG:Debug>:>
    $<$<CONFIG:Release>:>
    $<$<CONFIG:Profiling>:>
)



