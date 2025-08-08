#include "window.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            // Draw a blue rectangle
            HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
            RECT rect = {100, 100, 300, 200};
            FillRect(hdc, &rect, brush);
            DeleteObject(brush);
            EndPaint(hwnd, &ps);
            return 0;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

class Window {
public:
    HWND hwnd;

    bool create(HINSTANCE hInstance, int nCmdShow) {

        WNDCLASS wc = {};
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = hInstance;
        wc.lpszClassName = L"MyWindowClass";

        if (!RegisterClass(&wc)) {
            return false;
        }

        //  создаю окно епт
        hwnd = CreateWindowEx(
            0,
            L"MyWindowClass",
            L"Win32 Window",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
            NULL, NULL, hInstance, NULL
        );

        if (!hwnd) {
            return false;
        }

        ShowWindow(hwnd, nCmdShow);
        UpdateWindow(hwnd);
        return true;
    }

    void messageLoop() {
        MSG msg = {};
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
};
