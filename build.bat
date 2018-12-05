@echo off 

SET BUILD_TYPE=Debug
SET BUILD_DIR=build
SET SHARED_LIB=OFF

echo *** Buiding Simulador x86 in Debug Mode ***

if exist %BUILD_DIR% ( rmdir /s/q %BUILD_DIR% )
mkdir %BUILD_DIR%
cd %BUILD_DIR%

call cmake ..                                          ^
	-DBUILD_SHARED_LIBS:BOOL=%SHARED_LIB%              ^
	-DWIN32:BOOL=ON                                    ^
	-DWINDOWS:BOOL=ON                                  ^
	-G "Visual Studio 15 2017"
	
cmake --build . --config %BUILD_TYPE%

cd ..
