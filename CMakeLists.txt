cmake_minimum_required(VERSION 3.5)

project(Compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

# add_subdirectory(mini-llvm)
# add_subdirectory(mystl)
# set(ANTLR_JAR ${CMAKE_CURRENT_SOURCE_DIR}/deps/antlr-4.13.1-complete.jar)
# include_directories(deps/minilog/)
# include_directories(deps/cxxopts/)
# include_directories(deps/antlr-runtime/)

include_directories(deps/antlr4-runtime/)
include_directories(grammar)
include_directories(src)


FILE(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "grammar/*.cpp")

FILE(GLOB_RECURSE ANTLR_LIB_FILES "deps/antlr4-runtime/*.cpp")

add_definitions(-w -g)
add_library(antlr STATIC ${ANTLR_LIB_FILES})
add_executable(compiler ${SOURCE_FILES})
find_package(Threads REQUIRED)
target_link_libraries(compiler antlr Threads::Threads)

add_definitions(-DANTLR4CPP_STATIC)