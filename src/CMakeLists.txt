set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")

# find all source files
file(GLOB SRC_FILES *.c)
add_executable(CochlearRewards ${SRC_FILES})

