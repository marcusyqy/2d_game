#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

#include "base.h"

#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#undef max

#include <glad/gl.h>

typedef struct {
  DWORD dwExStyle;
  LPCWSTR lpClassName;
  LPCWSTR lpWindowName;
  DWORD dwStyle;
  int x;
  int y;
  int nWidth;
  int nHeight;
  HWND hWndParent;
  HMENU hMenu;
  HINSTANCE hInstance;
  LPVOID lpParam;
} WindowParam;

enum  {
  WindowMessages_CreateWindow  = WM_USER + 0x1337,
  WindowMessages_DestroyWindow = WM_USER + 0x1338,
};

typedef s32 WindowMessages;

int main(int argument_count, const char *arguments[]) {
  fprintf(stdout, "Hello world\n");
}


#include <glad/gl.c>
#include "base.c"

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "opengl32.lib")

