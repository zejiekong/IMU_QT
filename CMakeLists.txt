cmake_minimum_required(VERSION 3.16)
project(imu_qt VERSION 0.1
                DESCRIPTION "QT Application for IMU"
                LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

enable_testing(true)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets Gui Core Test SerialPort REQUIRED)
include_directories(include)
add_executable(imu_qt src/main.cpp src/window.cpp src/imu.cpp include/window.h include/imu.h)
add_executable(imu_test src/imu_test.cpp src/imu.cpp include/imu.h)
add_test(NAME imu_test COMMAND imu_test)
target_link_libraries(imu_qt Qt5::Widgets Qt5::Core Qt5::Gui Qt5::SerialPort)
target_link_libraries(imu_test PRIVATE Qt5::Widgets Qt5::SerialPort Qt5::Test)
add_custom_command(TARGET imu_test POST_BUILD COMMAND ctest  -V --output-on-failure)