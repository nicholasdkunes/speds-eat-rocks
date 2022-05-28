CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(object
main.cpp
iterator.cpp
op.cpp
op_add.cpp
op_subtract.cpp
op_multiply.cpp
op_divide.cpp
op_power.cpp
op_rand.cpp
)

ADD_EXECUTABLE(test
test.cpp
iterator.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
