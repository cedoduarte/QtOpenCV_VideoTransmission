cmake_minimum_required(VERSION 3.16)

project(OpenCVCheckFFmpeg LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the OpenCV_DIR to your OpenCV installation path
set(OpenCV_DIR "C:/opencv/build")  # Adjust this path accordingly

# Find OpenCV
find_package(OpenCV REQUIRED)

add_executable(OpenCVCheckFFmpeg main.cpp)

# Link OpenCV libraries
target_link_libraries(OpenCVCheckFFmpeg PRIVATE ${OpenCV_LIBS})

# Include OpenCV headers
target_include_directories(OpenCVCheckFFmpeg PRIVATE ${OpenCV_INCLUDE_DIRS})
target_include_directories(OpenCVCheckFFmpeg PRIVATE .)

include(GNUInstallDirs)
install(TARGETS OpenCVCheckFFmpeg
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
