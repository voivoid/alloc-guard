cmake_minimum_required(VERSION 3.13)
project(AllocGuard LANGUAGES CXX)

include(cmake/catch.cmake)

add_library(AllocGuard INTERFACE)
target_sources(AllocGuard INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc/alloc_guard/alloc_guard.h)
target_include_directories(AllocGuard INTERFACE inc)

add_subdirectory(tests)