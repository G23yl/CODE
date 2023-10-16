cmake_minimum_required(VERSION 3.26)
project(OpenCVTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(OpenCVTest main.cpp
        OpenCVCapturePictures.cpp
        OpenCVCapturePictures.h)
set(OpenCV_DIR D:\\opencv\\mingw_build\\install)
find_package(OpenCV REQUIRED)
target_link_libraries(OpenCVTest ${OpenCV_LIBS})
