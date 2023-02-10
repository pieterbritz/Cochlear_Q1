cmake_minimum_required(VERSION 3.10)
project(Rewards VERSION 1.0)

file(COPY docs DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

file(COPY docs DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Rewards-${Rewards_VERSION}")

install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/Rewards-${Rewards_VERSION}" TYPE DATA)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")

add_subdirectory (src)
