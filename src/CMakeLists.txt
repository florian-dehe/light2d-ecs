cmake_minimum_required(VERSION 3.10)

set(BINARY ${CMAKE_PROJECT_NAME})
set(SRCS 
  ${PROJECT_SOURCE_DIR}/src/component.hpp 
  ${PROJECT_SOURCE_DIR}/src/ecsdemo.hpp 
  ${PROJECT_SOURCE_DIR}/src/entity.hpp 
  ${PROJECT_SOURCE_DIR}/src/registry.hpp 
  ${PROJECT_SOURCE_DIR}/src/system.hpp
)

add_library(${BINARY} INTERFACE)
target_sources(${BINARY} PUBLIC ${SRCS})
