# CMakeList.txt : CMake project for MatCalc_API_test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

 file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Other/GM02_main_loop.mcs
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Other) 

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Other/GM02_sge_loop.mcs
DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Other) 

file(GLOB INC_TEST "include/*.h")

# Add source to this project's executable.
add_executable (MatCalc_API_test ${INC_TEST} MatCalc_API_test.cpp)
# use with dll_import.h
# target_link_libraries(MatCalc_API_test "C:/Program Files/MatCalc 6/mc_core.lib")

# TODO: Add tests and install targets if needed.
