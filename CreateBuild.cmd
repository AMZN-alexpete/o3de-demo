REM copies all necessary files to the build folder

REM copy all binaries
robocopy %~dp0\demo-project\build\windows_vs2019\bin\profile  %~dp0\demo-project\bin /purge /s /xf *.pdb *.log *.lock *.pyd
