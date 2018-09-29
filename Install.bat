@ECHO OFF

SET DESTINATION_PATH=C:\local\arduino-mock

SET XCOPY_OPTIONS=/D /Y

XCOPY "%~dp0build\include\arduino_mock\*.h" "%DESTINATION_PATH%\include" %XCOPY_OPTIONS%
XCOPY "%~dp0build\dist\lib\Debug\arduino_mock.lib" "%DESTINATION_PATH%\lib\vs12\debug" %XCOPY_OPTIONS%
XCOPY "%~dp0build\dist\lib\Release\arduino_mock.lib" "%DESTINATION_PATH%\lib\vs12\release" %XCOPY_OPTIONS%
XCOPY "%~dp0build\dist\lib\MinSizeRel\arduino_mock.lib" "%DESTINATION_PATH%\lib\vs12\release-min-size" %XCOPY_OPTIONS%
XCOPY "%~dp0build\dist\lib\RelWithDebInfo\arduino_mock.lib" "%DESTINATION_PATH%\lib\vs12\release-with-debug-info" %XCOPY_OPTIONS%