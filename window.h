#pragma once
#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window {
public:
    HWND hwnd;
    bool create(HINSTANCE hInstance, int nCmdShow);
    void messageLoop();
};
