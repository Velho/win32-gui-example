#pragma once

#include <windows.h>

struct Rect : RECT
{
	Rect()
	{
		SetEmpty();
	}
	Rect(LONG left, LONG top, LONG right, LONG bottom)
	{
		this->left = left;
		this->top = top;
		this->right = right;
		this->bottom = bottom;
	}

	BOOL IsEmpty() const { return IsRectEmpty(this); }
	BOOL SetEmpty() { return SetRectEmpty(this); }
	BOOL Set(LONG left, LONG top, LONG right, LONG bottom)
	{
		return SetRect(this, left, top, right, bottom);
	}

	BOOL PointInRect(LONG x, LONG y)
	{
		POINT pt = { x, y };
		return PtInRect(this, pt);
	}


	LONG Width() const { return right - left; }
	LONG Height() const { return bottom - top; }
};

class Control
{
public:
	Control() : m_hwnd { nullptr }
	{}

	LRESULT SendMessage(UINT msg, WPARAM wParam, LPARAM lParam) const
	{
		return ::SendMessage(m_hwnd, msg, wParam, lParam);
	}

	void SetHwnd(HWND hwnd)
	{
		m_hwnd = hwnd;
	}

	HWND GetHwnd() const { return m_hwnd; }

protected:
	HRESULT Create(const CREATESTRUCT& create_struct);
	HWND m_hwnd;
};