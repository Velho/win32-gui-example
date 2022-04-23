#pragma once

#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <commctrl.h>

template <class T> class BaseWindow
{
public:
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam,
                                     LPARAM lParam)
    {
        BaseWindow *p_win = nullptr;

        if (msg == WM_NCCREATE)
        {
            CREATESTRUCT *create_struct = reinterpret_cast<CREATESTRUCT *>(lParam);
            p_win = reinterpret_cast<BaseWindow *>(create_struct->lpCreateParams);
            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(p_win));

            p_win->m_hwnd = hwnd;
        }
        else
        {
            p_win = reinterpret_cast<BaseWindow *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
        }

        if (p_win) 
        {
            return p_win->HandleMessage(msg, wParam, lParam);
        }
        else
        {
            return DefWindowProc(hwnd, msg, wParam, lParam);
        }
    }

    BaseWindow() : m_hwnd{nullptr} {};

    BOOL Create(PCWSTR window_name, DWORD dw_style, DWORD dw_exstyle = 0, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int width = CW_USEDEFAULT, int height = CW_USEDEFAULT, HWND hwnd_parent = 0, HMENU menu = 0)
    {
        INITCOMMONCONTROLSEX icex;
        WNDCLASS wc = { 0 };

        // TODO : Initialize the accelerator and initcommoncontrolsex.
        icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
        icex.dwICC = ICC_WIN95_CLASSES;

        InitCommonControlsEx(&icex);

        wc.lpfnWndProc = T::WindowProc;
        wc.hInstance = GetModuleHandle(nullptr);
        wc.lpszClassName = ClassName();

        RegisterClass(&wc);

        m_hwnd = CreateWindowEx(dw_exstyle, ClassName(), window_name, dw_style, x, y, width, height, hwnd_parent, menu, GetModuleHandle(nullptr), this);

        return (m_hwnd ? TRUE : FALSE);
    }

    HWND GetHwnd() const { return m_hwnd; }

protected:
    HWND m_hwnd;

    virtual LRESULT HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam) = 0;
    virtual PCWSTR ClassName() const = 0;
};