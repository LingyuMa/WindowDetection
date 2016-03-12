project(tracking-test)
cmake_minimum_required(VERSION 2.8)
find_package(VISP REQUIRED)
find_package( OpenCV REQUIRED )
include_directories(${VISP_INCLUDE_DIRS})
add_executable(tracking_test SquareDetector.cpp Tracker.cpp main.cpp)
target_link_libraries(tracking_test ${VISP_LIBRARIES})
target_link_libraries( tracking_test ${OpenCV_LIBS} )
add_definitions(-std=c++11)


