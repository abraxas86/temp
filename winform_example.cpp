#include <windows.h>

// Global variables
HWND g_hLabel;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_CLOSE:
            PostQuitMessage(0);
            break;
        case WM_CREATE:
            // Create a label control when the window is created
            g_hLabel = CreateWindow("STATIC", "BOOP", WS_CHILD | WS_VISIBLE,
                100, 100, 100, 20, hWnd, NULL, NULL, NULL);
            if (g_hLabel == NULL) {
                MessageBox(NULL, "Label creation failed!", "Error", MB_ICONERROR);
            }
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWindowClass"; // Use wide-character string

    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "Window class registration failed!", "Error", MB_ICONERROR);
        return 1;
    }

    HWND hWnd = CreateWindow("MyWindowClass", "My Win32 Window", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, NULL, NULL, hInstance, NULL);

    if (hWnd == NULL) {
        MessageBox(NULL, "Window creation failed!", "Error", MB_ICONERROR);
        return 1;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
}
