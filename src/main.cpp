#include "server.h"
#include "webview.h"
#include "resource.h"
#include <windows.h>
#include <thread>

/**
 * @brief Prosedur callback untuk menangani pesan Windows.
 * 
 * Fungsi ini menangani berbagai pesan Windows, termasuk perubahan ukuran jendela
 * dan penghancuran jendela utama.
 * 
 * @param hWnd Handle ke jendela utama.
 * @param uMsg Pesan yang diterima oleh jendela.
 * @param wParam Parameter tambahan untuk pesan.
 * @param lParam Parameter tambahan untuk pesan.
 * @return LRESULT Hasil pemrosesan pesan.
 */
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int main()
{
    // Jalankan server Crow di thread terpisah untuk menangani permintaan HTTP
    std::thread server_thread(StartServer);

    // Dapatkan handle instance aplikasi
    HINSTANCE hInstance = GetModuleHandle(nullptr);

    // Definisi kelas jendela Windows
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;   // Callback untuk menangani pesan Windows
    wc.hInstance = hInstance;
    wc.lpszClassName = L"WebView2Window"; // Nama kelas jendela
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1)); // Load icon dari resource

    // Registrasi kelas jendela
    RegisterClass(&wc);

    // Buat jendela utama untuk WebView2
    HWND hWnd = CreateWindowEx(
        0,
        L"WebView2Window",   // Nama kelas jendela
        L"ScaleUp",          // Judul jendela
        WS_OVERLAPPEDWINDOW, // Gaya jendela standar
        CW_USEDEFAULT, CW_USEDEFAULT, // Posisi default
        800, 800,            // Ukuran awal jendela (lebar x tinggi)
        nullptr, nullptr,    // Tidak memiliki parent atau menu
        hInstance, nullptr   // Handle instance dan parameter tambahan
    );

    // Tampilkan jendela dalam mode fullscreen
    ShowWindow(hWnd, SW_SHOWMAXIMIZED);

    // Inisialisasi WebView dalam jendela utama
    CreateWebView(hWnd); // Fungsi dari webview.cpp

    // Loop utama untuk menangani pesan Windows
    MSG msg = {0};
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Tunggu thread server selesai sebelum keluar
    server_thread.join();
    return 0;
}

/**
 * @brief Callback untuk menangani pesan Windows.
 * 
 * Fungsi ini menangani beberapa event penting, seperti perubahan ukuran jendela
 * dan penutupan aplikasi.
 * 
 * @param hWnd Handle ke jendela.
 * @param uMsg Pesan Windows.
 * @param wParam Parameter tambahan.
 * @param lParam Parameter tambahan.
 * @return LRESULT Hasil pemrosesan pesan.
 */
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_SIZE:
        // Resize WebView jika jendela diubah ukurannya
        ResizeWebView(hWnd); // Fungsi dari webview.h
        break;

    case WM_DESTROY:
        // Keluar dari aplikasi jika jendela ditutup
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}
