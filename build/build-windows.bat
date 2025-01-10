:: Remarks Print all information on console
@echo ON

:: Remarks Save start directory
set "START_DIR=%cd%"
:: Remarks Set default exit strategy (AfterLastCommand or none)
set "EXIT_STRATEGY=AfterLastCommand"
:: Remarks Set build type (Release or Debug)
set "BUILD_TYPE=Release"
:: Remarks Set build dir
set "BUILD_DIR=project"

:: Remarks Run cmake build for library
set "CMAKE_PRE_BUILD_COMMAND=cmake -DCMAKE_BUILD_TYPE=%BUILD_TYPE% ../../"
set "CMAKE_BUILD_COMMAND=cmake --build . --config %BUILD_TYPE%"
set "CORE_LIB_NAME=user-monitoring-core.dll"

if "%1"=="" (
    echo Exit strategy is default = %EXIT_STRATEGY%
) else (
    set "EXIT_STRATEGY=%1"
)

mkdir %BUILD_DIR%
cd %BUILD_DIR% || exit 1

powershell -Command "%CMAKE_PRE_BUILD_COMMAND%" || exit 1
powershell -Command "%CMAKE_BUILD_COMMAND%" || exit 1

cd %BUILD_TYPE% || exit 1
if exist "%CORE_LIB_NAME%" (
    copy "%CORE_LIB_NAME%" "%START_DIR%" || exit 1

    if "%EXIT_STRATEGY%"=="AfterLastCommand" (
        exit 0
    )
) else (
    echo Core library not exist && exit 1
)
