#!/bin/bash

mkdir project
cd project || exit

CMAKE_PRE_BUILD_COMMAND="cmake ../../"
CMAKE_BUILD_COMMAND="cmake --build ."
CORE_LIB_NAME="user-monitoring-core.so"

ls
eval $CMAKE_PRE_BUILD_COMMAND
eval $CMAKE_BUILD_COMMAND

cd Debug || exit

if [ -f "$CORE_LIB_NAME" ]; then
    echo "Core library exists"
else
    cp "$CORE_LIB_NAME" ../../
fi
