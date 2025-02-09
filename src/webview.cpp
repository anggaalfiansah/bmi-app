#include "webview.h"
#include <wrl.h>
#include <WebView2.h>
#include <windows.h>

#pragma comment(lib, "WebView2Loader.dll.lib")

using namespace Microsoft::WRL;

// Objek untuk menyimpan controller dan WebView agar tetap ada selama aplikasi berjalan
ComPtr<ICoreWebView2Controller> webViewController;
ComPtr<ICoreWebView2> webView;

/**
 * @brief Membuat dan menginisialisasi WebView2 di dalam window yang diberikan.
 * 
 * Fungsi ini akan:
 * 1. Membuat lingkungan WebView2.
 * 2. Membuat controller WebView2.
 * 3. Mengambil instance WebView dari controller.
 * 4. Menyesuaikan ukuran WebView dengan window.
 * 5. Menavigasi ke halaman awal aplikasi (http://localhost:5000/).
 * 
 * @param hWnd Handle ke window utama aplikasi.
 */
void CreateWebView(HWND hWnd) {
    CreateCoreWebView2EnvironmentWithOptions(nullptr, nullptr, nullptr,
        Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>(
            [hWnd](HRESULT result, ICoreWebView2Environment* env) -> HRESULT {
                if (FAILED(result) || !env) {
                    MessageBox(hWnd, L"Failed to create WebView2 environment!", L"Error", MB_OK | MB_ICONERROR);
                    return result;
                }

                // Membuat controller WebView2
                env->CreateCoreWebView2Controller(hWnd,
                    Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
                        [hWnd](HRESULT result, ICoreWebView2Controller* controller) -> HRESULT {
                            if (FAILED(result) || !controller) {
                                MessageBox(hWnd, L"Failed to create WebView2 controller!", L"Error", MB_OK | MB_ICONERROR);
                                return result;
                            }

                            webViewController = controller;

                            // Mengambil instance WebView
                            HRESULT hr = controller->get_CoreWebView2(&webView);
                            if (FAILED(hr) || !webView) {
                                MessageBox(hWnd, L"Failed to get WebView2 instance!", L"Error", MB_OK | MB_ICONERROR);
                                return hr;
                            }

                            // Menyesuaikan ukuran WebView dengan ukuran window aplikasi
                            RECT bounds;
                            GetClientRect(hWnd, &bounds);
                            controller->put_Bounds(bounds);

                            // Navigasi ke halaman awal aplikasi
                            hr = webView->Navigate(L"http://localhost:5000/");
                            if (FAILED(hr)) {
                                MessageBox(hWnd, L"Failed to navigate!", L"Error", MB_OK | MB_ICONERROR);
                                return hr;
                            }

                            return S_OK;
                        }).Get());
                return S_OK;
            }).Get());
}

/**
 * @brief Menyesuaikan ukuran WebView ketika ukuran window aplikasi berubah.
 * 
 * Fungsi ini dipanggil saat event WM_SIZE terjadi agar WebView selalu menyesuaikan dengan window utama.
 * 
 * @param hWnd Handle ke window utama aplikasi.
 */
void ResizeWebView(HWND hWnd) {
    if (webViewController) {
        RECT bounds;
        GetClientRect(hWnd, &bounds);
        webViewController->put_Bounds(bounds);
    }
}
