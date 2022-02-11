#include "Button.h"

HRESULT Button::CreateText(HWND parent, const PCWSTR caption, int id, const Rect& bounds)
{
	CREATESTRUCT create = { 0 };
	
	//CREATESTRUCT create;
	//ZeroMemory(&create, sizeof(CREATESTRUCT));

	create.x = bounds.left;
	create.y = bounds.top;
	create.cx = bounds.right - create.x;	// Width
	create.cy = bounds.bottom - create.y;	// Height

	create.hwndParent = parent;
	create.lpszName = caption;
	create.hMenu = reinterpret_cast<HMENU>(static_cast<INT_PTR>(id));
	create.lpszClass = L"BUTTON";
	create.style = BS_PUSHBUTTON | BS_FLAT;

	return Control::Create(create);
}
