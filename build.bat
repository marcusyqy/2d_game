@echo off
setlocal
pushd %~dp0

for %%a in (%*) do set "%%a=1"

if not exist .build mkdir .build

if "%run%"=="1" set RUN=1

set NAME=2d_game
set CCFLAGS=
REM -Werror -Wall -pedantic

pushd .build
if exist %NAME%.exe (
  del %NAME%.exe
)
echo --[[COMPILING]]--
clang ../src/main.c %CCFLAGS% -o %NAME%.exe -I../src

if exist %NAME%.exe (
if "%RUN%" == "1" (
  echo --[[RUN]]--
  %NAME%.exe
)
)
popd

popd
