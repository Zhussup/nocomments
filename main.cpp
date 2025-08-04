#include "window.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    Window win;
    if (!win.create(hInstance, nCmdShow)) {
        MessageBox(NULL, L"Window creation failed!", L"Error", MB_ICONERROR);
        return -1;
    }
    win.messageLoop();
    return 0;
}
