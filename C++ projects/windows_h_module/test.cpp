/*
    https://learn.microsoft.com/en-us/windows/win32/api/
    https://learn.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-shellexecutea
*/

#include <windows.h>
#include <wrl.h>
#include <wil/com.h>
#include "WebView2.h"

using namespace Microsoft::WRL;

HWND g_hwnd;
wil::com_ptr<ICoreWebView2> webview;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_DESTROY) {
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void InitWebView(HWND hwnd) {
    CreateCoreWebView2EnvironmentWithDetails(nullptr, nullptr, nullptr,
        Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>(
            [hwnd](HRESULT hr, ICoreWebView2Environment* env) -> HRESULT {
                env->CreateCoreWebView2Controller(hwnd,
                    Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
                        [hwnd](HRESULT hr, ICoreWebView2Controller* controller) -> HRESULT {
                            wil::com_ptr<ICoreWebView2Controller> webviewController = controller;
                            webviewController->get_CoreWebView2(&webview);

                            RECT bounds;
                            GetClientRect(hwnd, &bounds);
                            webviewController->put_Bounds(bounds);

                            // HIDE the window (furtive)
                            ShowWindow(hwnd, SW_HIDE); // << stealth mode

                            // Navigate to Rewards
                            webview->Navigate(L"https://rewards.bing.com/?redref=ohp_gn");

                            // OPTIONAL: Simulate click using JavaScript
                            webview->ExecuteScript(
                                LR"(
                                    // Simulate JS click or log message
                                    console.log("WebView2 loaded!");
                                    // Example: Click a tab if it exists
                                    let gagnerTab = document.querySelector('[data-bi-name="earn"]');
                                    if (gagnerTab) gagnerTab.click();
                                )",
                                nullptr
                            );
                            return S_OK;
                        }).Get());
                return S_OK;
            }).Get());
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    // Create a stealthy window
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"StealthBrowserWindow";
    RegisterClass(&wc);

    g_hwnd = CreateWindowW(wc.lpszClassName, L"Invisible Browser", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);

    InitWebView(g_hwnd);

    // Windows message loop
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
