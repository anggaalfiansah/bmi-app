#include "server.h"
#include "webview.h"
#include "resource.h"
#include <windows.h>
#include <thread>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int main()
{
    // Jalankan server Crow di thread terpisah
    std::thread server_thread(StartServer);

    // Buat Window untuk WebView2
    HINSTANCE hInstance = GetModuleHandle(nullptr);
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"WebView2Window";
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

    RegisterClass(&wc);
    HWND hWnd = CreateWindowEx(0, L"WebView2Window", L"ScaleUp",
                               WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 800,
                               nullptr, nullptr, hInstance, nullptr);

    ShowWindow(hWnd, SW_SHOWMAXIMIZED);
    CreateWebView(hWnd); // Panggil fungsi dari webview.cpp

    MSG msg = {0};
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    server_thread.join();
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_SIZE:
        ResizeWebView(hWnd); // Fungsi dari webview.h
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}