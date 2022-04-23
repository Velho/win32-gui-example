#pragma once

#include "BaseWindow.h"
#include "Button.h"

class MainWindow : public BaseWindow<MainWindow>
{
public:
	MainWindow();

	PCWSTR ClassName() const { return L"MainWindow"; }
	LRESULT HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam);

	void InitializeControls();

private:
	Button m_button;
	const static HBRUSH COLOR_WINDOW_P1;
};