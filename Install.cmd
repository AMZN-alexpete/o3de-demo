@echo off
if exist %~dp0\o3de (
    echo Registering engine in o3de
    CALL o3de\scripts\o3de.bat register --this-engine --force
    if %ERRORLEVEL%==1 (
        echo Getting python
        CALL o3de\python\get_python.bat REM needs cmake
        CALL o3de\scripts\o3de.bat register --this-engine --force
    )
) else (
    echo Registering engine in o3de-sdk
    CALL o3de-sdk\scripts\o3de.bat register --this-engine --force
    if %ERRORLEVEL%==1 (
        echo Getting python
        CALL o3de-sdk\python\get_python.bat REM needs cmake
        CALL o3de-sdk\scripts\o3de.bat register --this-engine --force
    )
)
echo Done

