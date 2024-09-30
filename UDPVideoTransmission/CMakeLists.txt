cmake_minimum_required(VERSION 3.16)

project(UDPVideoTransmission LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)

# Set the OpenCV_DIR to your OpenCV installation path
set(OpenCV_DIR "C:/opencv/build")  # Adjust this path accordingly

# Find OpenCV
find_package(OpenCV REQUIRED)

add_executable(UDPVideoTransmission
  main.cpp
)

target_link_libraries(UDPVideoTransmission PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(UDPVideoTransmission PRIVATE Qt${QT_VERSION_MAJOR}::Network)

# Link OpenCV libraries
target_link_libraries(UDPVideoTransmission PRIVATE ${OpenCV_LIBS})

# Include OpenCV headers
target_include_directories(UDPVideoTransmission PRIVATE ${OpenCV_INCLUDE_DIRS})

target_include_directories(UDPVideoTransmission PRIVATE .)

include(GNUInstallDirs)
install(TARGETS UDPVideoTransmission
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
