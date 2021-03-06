@echo off
call cls

rem // -----------------------
rem // Determine the build configuration needed, set to 'release' by default, (should this change?)
rem // ------------------------

set BuildMode="release"
if "%1" == "debug" (
  set BuildMode="debug"
)

set BuildMode=%BuildMode:"=%
echo Building: %BuildMode%

rem // -----------------------
rem // Set the include and library directories for project dependencies
rem // ------------------------

set IncludeDirectory="C:\Users\Dandy\Desktop\Projects\game-dev\sfml\SFML-2.3.2\include\"
set LibraryDirectory="C:\Users\Dandy\Desktop\Projects\game-dev\sfml\SFML-2.3.2\lib\"

rem // -----------------------
rem // Create the build directories
rem // ------------------------

if not exist build\%BuildMode% mkdir build\%BuildMode%

rem // -----------------------
rem // Set compiler and linker options, source code input files and library dependecies based on desired build mode
rem // ------------------------

set CompilerOptions="/I %IncludeDirectory% /EHsc /O2"
set PreprocessorDefinitions=""
set LinkedLibraries="user32.lib sfml-main.lib sfml-graphics.lib sfml-system.lib sfml-window.lib"
set LinkerOptions="/link /LIBPATH:%LibraryDirectory% /out:sfml-dev.exe"

if "%BuildMode%" == "release" (
  rem (TODO: David): Concatenate the new options to the end of the default linker options
  set "LinkerOptions="/link /LIBPATH:%LibraryDirectory% /out:sfml-dev.exe /subsystem:windows /entry:mainCRTStartup"
)

if "%BuildMode%" == "debug" (
  set PreprocessorDefinitions="/DSFML_GAMEDEV_DEBUG"
  set CompilerOptions="-Zi /I %IncludeDirectory% /EHsc /O2"
  set LinkedLibraries="user32.lib sfml-main.lib sfml-graphics.lib sfml-system.lib sfml-window.lib"
)

rem // -----------------------
rem // Create an array of all the filenames in the path 'source\' of all the .c and .cpp files.
rem // -----------------------
setlocal EnableDelayedExpansion
set SourceDirectory="source\"
set SourceCodeFiles="..\..\"
for %%F in (%SourceDirectory%*.cpp) do (
  set "SourceCodeFiles=!SourceCodeFiles!..\..\%%F"
  set "SourceCodeFiles=!SourceCodeFiles! "
)
set SourceCodeFiles=!SourceCodeFiles:~8!

rem // -----------------------
rem // Removes double quotes from configuration strings during varaible expansion when calling the compiler
rem // ------------------------

set CompilerOptions=%CompilerOptions:"=%
set PreprocessorDefinitions=%PreprocessorDefinitions:"=%
set SourceCodeFile=%SourceCodeFile:"=%
set LinkedLibraries=%LinkedLibraries:"=%
set LinkerOptions=%LinkerOptions:"=%

echo.
echo CompilerOptions: %CompilerOptions%
echo PreprocessorDefinitions: %PreprocessorDefinitions%
echo SourceCodeFiles: %SourceCodeFiles%
echo LinkerOptions: %LinkerOptions%
echo.

rem // -----------------------
rem // Call the compiler with the configuration settings, and clean the directory of all .obj files generated by the compiler
rem // ------------------------

pushd build\%BuildMode%
  cl %CompilerOptions% %PreprocessorDefinitions% %SourceCodeFiles% %LinkedLibraries% %LinkerOptions%
  echo.
  del *.obj
  echo Finished!
popd
