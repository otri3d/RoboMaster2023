REM Adds the containing directory's "include" and "lib" subdirs to appropriate global environment variables

setlocal
setx CPLUS_INCLUDE_PATH "%~dp0include;%CPLUS_INCLUDE_PATH%"
setx LIBRARY_PATH "%~dp0lib;%LIBRARY_PATH%"
