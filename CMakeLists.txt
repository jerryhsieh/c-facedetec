#cmake need this
cmake_minimum_required(VERSION 3.1)

#Enable C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#Define project name
project(detectface)

#find OpenCV
find_package(OpenCV REQUIRED)

#If package found, several variable will be set
message(STATUS "OpenCV libray status: ")
message(STATUS "   config: ${OpenCV_DIR}")
message(STATUS "   version: ${OenCV_VERSION}")
message(STATUS "   libraries: ${OpenCV_LIBS}")
message(STATUS "   include path: ${OpenCV_INCLUDE_DIRS}")

#declare executable target build from sources
add_executable(facedetect facedetect.cpp)

#link app to OpenCV lib
target_link_libraries(facedetect ${OpenCV_LIBS})
