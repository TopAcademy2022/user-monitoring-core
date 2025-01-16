# Specify the minimum version.
cmake_minimum_required(VERSION 3.0)

# Specify the project info.
project(user-monitoring-core VERSION 0.0.1 DESCRIPTION "User monitoring core")

# For creating Dll from Windows
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Set DEFAULT install (README.md points to this line)
set (FIRST_BOOST_INSTALL ON)

# Include default library/boost_1_80_0
include(./library/CMakeLists.txt)

# Only find static libs
set(Boost_USE_STATIC_LIBS ON)

# Ignore debug libs and
set(Boost_USE_DEBUG_LIBS OFF)

# Only find release libs
set(Boost_USE_RELEASE_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

if(WIN32)
	# Switch BOOST_ROOT and BOOST_LIBRARYDIR if FIRST_BOOST_INSTALL != ON
    set (BOOST_ROOT "./lib/boost_1_80_0")
    set (BOOST_LIBRARYDIR "./lib/boost_1_80_0/stage/lib")
endif()

# Hide Windows warning
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

# Declare the library target.
add_library(${PROJECT_NAME} SHARED
    src/main.h
    src/main.cpp
)

# Configure the directories to search for header files.
target_include_directories(${PROJECT_NAME} PRIVATE src)

# Set the version property.
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Set the shared object version property to the project's major version.
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

# Set the public header property to the one with the actual API.
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER src/main.h)

# Enable testing functionality
enable_testing()
set(ENABLE_TESTING ON)

if(ENABLE_TESTING)
    add_subdirectory(./test)
endif()
