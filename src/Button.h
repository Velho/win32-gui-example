#pragma once

#include "Control.h"

class Button : public Control
{
public:
	HRESULT CreateText(HWND parent, const PCWSTR caption, int id, const Rect& bounds);

	void SetCheck(int nCheck)
	{
		SendMessage(BM_SETCHECK, static_cast<WPARAM>(nCheck), 0L);
	}

	BOOL IsChecked()
	{
		return SendMessage(BM_GETCHECK, 0, 0) == BST_CHECKED;
	}
};