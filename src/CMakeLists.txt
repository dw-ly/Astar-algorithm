cmake_minimum_required(VERSION 3.16)
include_directories(${PROJECT_SOURCE_DIR}/lib)

# add_subdirectory(net)

# file(GLOB_RECURSE APP_SRC true *.cpp) #添加当前目录所有cpp文件到APP_SRC变量中
set(APP_SRC main.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(A_Star ${APP_SRC})
target_link_libraries(A_Star libAStar)
#debug
# SET(CMAKE_BUILD_TYPE "Debug")
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
# SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")