@echo off
REM first make sure the engine is registered
echo registering engine
CALL o3de-sdk\scripts\o3de.bat register --this-engine
if %ERRORLEVEL%==1 (
    echo getting python for first time use
    CALL o3de-sdk\python\get_python.bat REM needs cmake
    CALL o3de-sdk\scripts\o3de.bat register --this-engine
)

