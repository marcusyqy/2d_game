@echo off
setlocal
pushd %~dp0

for %%a in (%*) do set "%%a=1"

if not exist .build mkdir .build

if "%run%"=="1" set RUN=1

set NAME=2d_game
set CCFLAGS=-external:W0
REM -nologo -MP -FC -Zi  -wd4530 -utf-8 -WX -W3 -EHsc

REM https://github.com/glfw/glfw/issues/1981#issuecomment-954047199
set glfw_lib=..\external\GLFW\glfw3_mt.lib

pushd .build

echo --[[COMPILING]]--
cl ..\src\main.c %CCFLAGS% -Fe:%NAME%.exe -I..\src -external:I..\external -link %glfw_lib%

if not %ERRORLEVEL% == 0 (
  if exist %NAME%.exe (
    del %NAME%.exe
  )
)

if exist %NAME%.exe (
if "%RUN%" == "1" (
  echo --[[RUN]]--
  %NAME%.exe
)
)
popd

popd
