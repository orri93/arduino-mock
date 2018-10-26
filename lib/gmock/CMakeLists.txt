cmake_minimum_required(VERSION 2.8.8)
project(gmock_builder C CXX)
include(ExternalProject)

ExternalProject_Add(gmock
    URL https://github.com/paulsapps/gmock-1.7.0/archive/master.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gmock
    INSTALL_COMMAND ""
)

# Specify include dir
ExternalProject_Get_Property(gmock source_dir)
set(GMOCK_INCLUDE_DIRS ${source_dir}/include PARENT_SCOPE)

# Specify MainTest's link libraries
ExternalProject_Get_Property(gmock binary_dir)
set(GMOCK_LIBS_DIR ${binary_dir} PARENT_SCOPE)

if (MSVC)
  set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )
  foreach(CompilerFlag ${CompilerFlags})
    string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
  endforeach()

#  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
#  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

message("CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELEASE is ${CMAKE_CXX_FLAGS_RELEASE}")
