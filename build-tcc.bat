@echo off

rem Build keyrate using Tiny C compiler
rem Get it here: https://bellard.org/tcc/

pushd "%~dp0"

tcc -luser32 "%cd%\keyrate.c" -o "%cd%\keyrate.exe"

popd

exit /b %errorlevel%
