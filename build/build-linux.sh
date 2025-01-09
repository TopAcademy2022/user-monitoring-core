#!/bin/bash

mkdir project
cd project || exit

CMAKE_PRE_BUILD_COMMAND="cmake ../../"
CMAKE_BUILD_COMMAND="cmake --build ."
CORE_OLD_LIB_NAME="libuser-monitoring-core.so"
CORE_LIB_NAME="user-monitoring-core.so"

eval $CMAKE_PRE_BUILD_COMMAND
eval $CMAKE_BUILD_COMMAND
mv $CORE_OLD_LIB_NAME $CORE_LIB_NAME

if [ -f "$CORE_LIB_NAME" ]; then
    cp "$CORE_LIB_NAME" ../../
else
    echo "Core library exists"
    exit 1
fi
