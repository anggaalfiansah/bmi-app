#ifndef WEBVIEW_HANDLER_H
#define WEBVIEW_HANDLER_H

#include <windows.h>

/**
 * @brief Membuat dan menginisialisasi WebView2 di dalam window yang diberikan.
 * 
 * Fungsi ini akan:
 * - Membuat lingkungan WebView2.
 * - Membuat controller WebView2.
 * - Mengambil instance WebView dari controller.
 * - Menyesuaikan ukuran WebView dengan window.
 * - Menavigasi ke halaman awal aplikasi (http://localhost:5000/).
 * 
 * @param hWnd Handle ke window utama aplikasi.
 */
void CreateWebView(HWND hWnd);

/**
 * @brief Menyesuaikan ukuran WebView ketika ukuran window aplikasi berubah.
 * 
 * Fungsi ini dipanggil saat event `WM_SIZE` terjadi agar WebView selalu menyesuaikan dengan ukuran window utama.
 * 
 * @param hWnd Handle ke window utama aplikasi.
 */
void ResizeWebView(HWND hWnd);

#endif // WEBVIEW_HANDLER_H
