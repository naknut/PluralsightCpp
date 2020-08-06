cmake_minimum_required(VERSION 3.0.0)
project(Lambdas VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(Resource Resource.cpp)
add_executable(Captures Lambdas.cpp)
target_link_libraries(Captures PUBLIC Resource)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
