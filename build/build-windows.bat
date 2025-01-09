mkdir project
cd project

:: Remarks Run cmake build for core library
set CMAKE_PRE_BUILD_COMMAND="cmake ../../"
set CMAKE_BUILD_COMMAND="cmake --build ."
set CORE_LIB_NAME=user-monitoring-core.dll

powershell -Command %CMAKE_PRE_BUILD_COMMAND%
powershell -Command %CMAKE_BUILD_COMMAND%

cd Debug
if exist '%CORE_LIB_NAME%' (
    echo Core library exist
)
else (
    copy %CORE_LIB_NAME% ..\..\
)