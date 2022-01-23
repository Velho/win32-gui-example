#include "Control.h"

HRESULT Control::Create(const CREATESTRUCT& create_struct)
{
	HWND hwnd = CreateWindowEx(
		create_struct.dwExStyle, create_struct.lpszClass, create_struct.lpszName, create_struct.style | WS_CHILD | WS_VISIBLE, create_struct.x, create_struct.y, create_struct.cx, create_struct.cy, create_struct.hwndParent, create_struct.hMenu, create_struct.hInstance, create_struct.lpCreateParams
	);

	if (hwnd == 0)
	{
		return 0;
	}

	SetHwnd(hwnd);
	return S_OK;	
}
