#!/bin/bash

# Print all information on console
set -x  # Enable debugging output

# Save start directory
START_DIR=$(pwd)

# Set default exit strategy (AfterLastCommand or none)
EXIT_STRATEGY="AfterLastCommand"

# Set build type (Release or Debug)
BUILD_TYPE="Release"

# Set build directory
BUILD_DIR="project"

# Run cmake build for library
CMAKE_PRE_BUILD_COMMAND="cmake -DCMAKE_BUILD_TYPE=${BUILD_TYPE} ../../"
CMAKE_BUILD_COMMAND="cmake --build . --config ${BUILD_TYPE}"
CORE_OLD_LIB_NAME="libuser-monitoring-core.so"
CORE_LIB_NAME="user-monitoring-core.so"

# Check for the first argument
if [ -z "\$1" ]; then
    echo "Exit strategy is default = ${EXIT_STRATEGY}"
else
    EXIT_STRATEGY="\$1"
fi

# Create build directory
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR" || exit 1

# Execute cmake commands
eval "$CMAKE_PRE_BUILD_COMMAND"
eval "$CMAKE_BUILD_COMMAND"

# Rename library
mv "$CORE_OLD_LIB_NAME" "$CORE_LIB_NAME"

# Check if the core library exists and handle accordingly
if [ -e "$CORE_LIB_NAME" ]; then
    cp "$CORE_LIB_NAME" "$START_DIR"

    if [ "$EXIT_STRATEGY" == "AfterLastCommand" ]; then
        exit 0
    fi
else
    echo "Core library not exist"
    exit 1
fi
