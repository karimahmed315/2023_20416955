cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(calc)


if(BUILD_SHARED_LIBS)
  # if static libs are compiled we need
  # to somehow communicate that to the
  # source code. The definition will be
  # used to determine how MATHSLIB API
  # is defined in adder.h
  add_definitions(-Dmaths_STATIC)
endif()



if(WIN32)
  set(CPACK_GENERATOR "NSIS")
else()
  set(CPACK_GENERATOR "ZIP")
endif()

include(CPack)

add_library(maths adder.cpp)

add_executable(calc calc.cpp)
target_link_libraries(calc maths)

install(TARGETS calc maths
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib/static)
