cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

add_definitions(-std=c++14)

set(CXX_FLAGS "-Wall" "-pedantic")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(Mathematics-for-Robotics)

find_package(Eigen3 3.4 REQUIRED)

include_directories(${EIGEN_INCLUDE_DIRS})
link_directories(${Eigen_INCLUDE_DIRS})

# Executables
add_executable (Cholesky LinearAlgebra/CholeskyDecomposition.cpp)
#target_link_libraries (test ${EIGEN_LIBRARIES})
target_link_libraries (Cholesky Eigen3::Eigen)

add_executable (rank LinearAlgebra/MatrixRank.cpp)
target_link_libraries (rank Eigen3::Eigen)

add_executable (LU LinearAlgebra/LUDecomposition.cpp)
target_link_libraries (LU Eigen3::Eigen)