@ECHO OFF

SET INCLUDE_PATH=%~dp0include\arduino-mock
SET LIB_PATH=%~dp0build\dist\lib
SET DESTINATION_PATH=C:\local\arduino-mock

SET XCOPY_OPTIONS=/D /Y

XCOPY "%INCLUDE_PATH%\*.h" "%DESTINATION_PATH%\include" %XCOPY_OPTIONS%
XCOPY "%LIB_PATH%\Debug\arduino_mock.lib" "%DESTINATION_PATH%\lib\vs12\debug" %XCOPY_OPTIONS%
XCOPY "%LIB_PATH%\Release\arduino_mock.lib" "%DESTINATION_PATH%\lib\vs12\release" %XCOPY_OPTIONS%
XCOPY "%LIB_PATH%\MinSizeRel\arduino_mock.lib" "%DESTINATION_PATH%\lib\vs12\release-min-size" %XCOPY_OPTIONS%
XCOPY "%LIB_PATH%\RelWithDebInfo\arduino_mock.lib" "%DESTINATION_PATH%\lib\vs12\release-with-debug-info" %XCOPY_OPTIONS%