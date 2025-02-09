#include "webview.h"
#include <wrl.h>
#include <WebView2.h>
#include <windows.h>

#pragma comment(lib, "WebView2Loader.dll.lib")

using namespace Microsoft::WRL;

// Simpan controller dan WebView agar tetap ada
ComPtr<ICoreWebView2Controller> webViewController;
ComPtr<ICoreWebView2> webView;

void CreateWebView(HWND hWnd) {
    CreateCoreWebView2EnvironmentWithOptions(nullptr, nullptr, nullptr,
        Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>(
            [hWnd](HRESULT result, ICoreWebView2Environment* env) -> HRESULT {
                if (FAILED(result) || !env) {
                    MessageBox(hWnd, L"Failed to create WebView2 environment!", L"Error", MB_OK | MB_ICONERROR);
                    return result;
                }

                env->CreateCoreWebView2Controller(hWnd,
                    Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
                        [hWnd](HRESULT result, ICoreWebView2Controller* controller) -> HRESULT {
                            if (FAILED(result) || !controller) {
                                MessageBox(hWnd, L"Failed to create WebView2 controller!", L"Error", MB_OK | MB_ICONERROR);
                                return result;
                            }

                            webViewController = controller;

                            HRESULT hr = controller->get_CoreWebView2(&webView);
                            if (FAILED(hr) || !webView) {
                                MessageBox(hWnd, L"Failed to get WebView2 instance!", L"Error", MB_OK | MB_ICONERROR);
                                return hr;
                            }

                            RECT bounds;
                            GetClientRect(hWnd, &bounds);
                            controller->put_Bounds(bounds);

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

void ResizeWebView(HWND hWnd) {
    if (webViewController) {
        RECT bounds;
        GetClientRect(hWnd, &bounds);
        webViewController->put_Bounds(bounds);
    }
}
