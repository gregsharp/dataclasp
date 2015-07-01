##-----------------------------------------------------------------------------
##  Welcome to the Dataclasp CMakeLists.txt file
##-----------------------------------------------------------------------------
##  See COPYRIGHT.TXT and LICENSE.TXT for copyright and license information
##-----------------------------------------------------------------------------
project (dataclasp)

set (DCL_VERSION_MAJOR "0")
set (DCL_VERSION_MINOR "0")
set (DCL_VERSION_PATCH "1")

cmake_minimum_required (VERSION 2.8.0)
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package (LibYAML)

add_subdirectory (src)

message (STATUS ">> ${CMAKE_BINARY_DIR}")

enable_testing ()
add_subdirectory (testing)
