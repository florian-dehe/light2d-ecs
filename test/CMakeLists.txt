cmake_minimum_required(VERSION 3.10)

set(BINARY ${CMAKE_PROJECT_NAME}_test)

set(SRCS main.cpp 
  entity.cpp

  component.cpp 
  test_component.hpp

  system.cpp
)

add_executable(${BINARY} ${SRCS})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC gtest)
target_include_directories(${BINARY} PUBLIC ${PROJECT_SOURCE_DIR}/src)
