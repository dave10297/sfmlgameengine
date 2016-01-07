@echo off
call cls

rem // -----------------------
rem // Create an array of all the filenames in the path 'source\' of all the .c and .cpp files.
rem // -----------------------
setlocal EnableDelayedExpansion
set SourceDirectory="source\"
set FileName=""
for %%F in (%SourceDirectory%*.cpp) do (
  set "FileName=!FileName!%%F"
  set "FileName=!FileName! "
)
set FileName=!FileName:~2!
echo %FileName%
endlocal
