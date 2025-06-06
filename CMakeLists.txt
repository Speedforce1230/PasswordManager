cmake_minimum_required(VERSION 3.10)
project(PasswordManager)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "F:\\Qt\\6.9.0\\msvc2022_64")
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/template)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_SOURCE_DIR}/include/*.h)
file(GLOB_RECURSE TEMPLATE_SOURCES ${CMAKE_SOURCE_DIR}/template/*.tpp)
qt_add_executable(PasswordManager ${SOURCES} ${TEMPLATE_SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)

# Set subsystem to WINDOWS for a GUI application
if (WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE ON)
endif()

