#include "MainWindow.h"

#define BUTTON_ONE 200

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE /*prevInstance*/,
                    PWSTR cmdline, int cmdshow) {
  MainWindow window;

  if (!window.Create(L"Main Window", WS_OVERLAPPEDWINDOW)) {
    return 0;
  }

  window.InitializeControls();

  ShowWindow(window.GetHwnd(), cmdshow);

  // Event loop.

  MSG msg = {};
  while (GetMessage(&msg, nullptr, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return 0;
}

MainWindow::MainWindow() {}

LRESULT MainWindow::HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam) {
  int wmId, wmEvent;

  switch (msg) {
  case WM_COMMAND:
    wmId = LOWORD(wParam);
    wmEvent = HIWORD(wParam);

    switch (wmId) {
    case BUTTON_ONE:
      if (wmEvent == BN_CLICKED) {
        MessageBox(m_hwnd, L"Button was clicked!", L"Caption", MB_OK);
      }
      break;
    default:
      return DefWindowProc(m_hwnd, msg, wParam, lParam);
    }

    break;

  case WM_DESTROY:
    PostQuitMessage(0);
    return 0;

  case WM_PAINT: {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(m_hwnd, &ps);
    FillRect(hdc, &ps.rcPaint, reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1));
    EndPaint(m_hwnd, &ps);
  }

    return 0;
  default:
    return DefWindowProc(m_hwnd, msg, wParam, lParam);
  }

  return TRUE;
}

void MainWindow::InitializeControls() {
  m_button.CreateText(m_hwnd, L"This is Button", BUTTON_ONE,
                      Rect(50, 50, 250, 250));
}
