#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <iostream>
#include <string>
#include <math.h>

#define WINDOWS_STATICLIB
#include <windows.h>

using namespace std;



#define VERTICAL 0x1
#define HORIZONTALE 0x2


long taille(unsigned char sens){
	RECT desktop_size;
	const HWND hDesktop = GetDesktopWindow();

	if(GetWindowRect(hDesktop, &desktop_size)) {
		switch (sens) {
		case VERTICAL:
			return desktop_size.bottom - desktop_size.top;
			break;

		case HORIZONTALE:
			return desktop_size.right - desktop_size.left;
			break;
		}
	}

	return -1;
}

static PyObject* py_taille(PyObject* self, PyObject* args) // char sens
{
	char* str_sens;
	if( PyArg_ParseTuple(args, "s", &str_sens) ){
		if(strlen(str_sens) == 1){
			switch (str_sens[0]) {
			case 'h':
				return PyLong_FromLong( taille(HORIZONTALE) );
			case 'v':
				return PyLong_FromLong( taille(VERTICAL) );
			}
		}
	}
	
	return PyLong_FromLong( -1 );
}


void ecrire(char carac, long x, long y) {
	HDC hdc = GetDC(NULL);

	switch (carac) {

	case '0':
		for (int ix = x + 4; ix <= x + 6; ix++) {
			SetPixel(hdc, ix, y, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 3, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 10, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 10, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 10, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 9, RGB(0, 0, 0));
		for (int ix = x + 4; ix <= x + 6; ix++) {
			SetPixel(hdc, ix, y + 10, RGB(0, 0, 0));
		}
		break;

	case '1':
		for (int igrec = y; igrec <= y + 10; igrec++) {
			SetPixel(hdc, x + 10, igrec, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 9, y, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 3, RGB(0, 0, 0));
		break;

	case '2':
		for (int ix = x + 4; ix <= x + 6; ix++) {
			SetPixel(hdc, ix, y, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 3, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 5, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 5, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 9, RGB(0, 0, 0));
		for (int ix = x; ix <= x + 10; ix++) {
			SetPixel(hdc, ix, y + 10, RGB(0, 0, 0));
		}
		break;

	case '3':
		for (int ix = x + 4; ix <= x + 6; ix++) {
			SetPixel(hdc, ix, y, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 3, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 4, RGB(0, 0, 0));
		for (int ix = x + 5; ix <= x + 6; ix++) {
			SetPixel(hdc, ix, y + 5, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 6, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 9, RGB(0, 0, 0));
		for (int ix = x + 4; ix <= x + 6; ix++) {
			SetPixel(hdc, ix, y + 10, RGB(0, 0, 0));
		}
		break;

	case '4':
		for (int igrec = y; igrec <= y + 10; igrec++) {
			SetPixel(hdc, x + 10, igrec, RGB(0, 0, 0));
		}
		for (int ix = x + 2; ix <= x + 10; ix++) {
			SetPixel(hdc, ix, y + 7, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 9, y, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 5, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 5, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 6, RGB(0, 0, 0));
		break;

	case '5':
		for (int igrec = y; igrec <= y + 5; igrec++) {
			SetPixel(hdc, x + 2, igrec, RGB(0, 0, 0));
		}
		for (int ix = x + 2; ix <= x + 10; ix++) {
			SetPixel(hdc, ix, y, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 3, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 5, RGB(0, 0, 0));
		for (int ix = x + 3; ix <= x + 7; ix++) {
			SetPixel(hdc, ix, y + 4, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 8, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 10, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 9, RGB(0, 0, 0));
		for (int ix = x + 3; ix <= x + 7; ix++) {
			SetPixel(hdc, ix, y + 10, RGB(0, 0, 0));
		}
		break;

	case '6':
		for (int ix = x + 4; ix <= x + 6; ix++) {
			SetPixel(hdc, ix, y, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 3, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 4, RGB(0, 0, 0));
		for (int ix = x + 2; ix <= x + 5; ix++) {
			SetPixel(hdc, ix, y + 5, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 2, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 9, RGB(0, 0, 0));
		for (int ix = x + 4; ix <= x + 6; ix++) {
			SetPixel(hdc, ix, y + 10, RGB(0, 0, 0));
		}
		break;

	case '7':
		for (int ix = x; ix <= x + 10; ix++) {
			SetPixel(hdc, ix, y, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 10, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 5, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 5, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 10, RGB(0, 0, 0));
		SetPixel(hdc, x, y + 10, RGB(0, 0, 0));
		break;

	case '8':
		for (int ix = x + 4; ix <= x + 6; ix++) {
			SetPixel(hdc, ix, y, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 3, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 4, RGB(0, 0, 0));
		for (int ix = x + 4; ix <= x + 6; ix++) {
			SetPixel(hdc, ix, y + 5, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 3, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 9, RGB(0, 0, 0));
		for (int ix = x + 4; ix <= x + 6; ix++) {
			SetPixel(hdc, ix, y + 10, RGB(0, 0, 0));
		}
		break;

	case '9':
		for (int ix = x + 4; ix <= x + 6; ix++) {
			SetPixel(hdc, ix, y, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 3, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 4, RGB(0, 0, 0));
		for (int ix = x + 4; ix <= x + 8; ix++) {
			SetPixel(hdc, ix, y + 5, RGB(0, 0, 0));
		}
		SetPixel(hdc, x + 7, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 9, RGB(0, 0, 0));
		for (int ix = x + 4; ix <= x + 6; ix++) {
			SetPixel(hdc, ix, y + 10, RGB(0, 0, 0));
		}
		break;

	case '+':
		for (int ix = x; ix <= x + 10; ix++) {
			SetPixel(hdc, ix, y + 5, RGB(0, 0, 0));
		}
		for (int igrec = y; igrec <= y + 10; igrec++) {
			SetPixel(hdc, x + 5, igrec, RGB(0, 0, 0));
		}
		break;

	case '-':
		for (int ix = x; ix <= x + 10; ix++) {
			SetPixel(hdc, ix, y + 5, RGB(0, 0, 0));
		}
		break;

	case '/':
		SetPixel(hdc, x + 10, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 5, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 5, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 10, RGB(0, 0, 0));
		SetPixel(hdc, x, y + 10, RGB(0, 0, 0));
		break;

	case '*':
		SetPixel(hdc, x + 10, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 1, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 2, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 3, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 4, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 5, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 5, RGB(0, 0, 0));
		SetPixel(hdc, x + 5, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 6, RGB(0, 0, 0));
		SetPixel(hdc, x + 4, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 6, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 7, RGB(0, 0, 0));
		SetPixel(hdc, x + 3, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 7, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 8, RGB(0, 0, 0));
		SetPixel(hdc, x + 2, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 8, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 9, RGB(0, 0, 0));
		SetPixel(hdc, x + 1, y + 10, RGB(0, 0, 0));
		SetPixel(hdc, x, y + 10, RGB(0, 0, 0));
		SetPixel(hdc, x + 9, y + 10, RGB(0, 0, 0));
		SetPixel(hdc, x + 10, y + 10, RGB(0, 0, 0));
		break;

	}
	ReleaseDC(NULL, hdc);
}

static PyObject* py_ecrire(PyObject* self, PyObject* args) // char carac, int x, int y 
{
	char* str_carac;
	long x;
	long y;

	if( PyArg_ParseTuple(args, "sll", &str_carac, &x, &y) ){
		if(strlen(str_carac) == 1)
			ecrire(str_carac[0], x, y);
	}

	Py_INCREF(Py_None);
	return Py_None;
}


void cercle(long x, long y, char* titre, char* sous_titre){
	HDC hdc = GetDC(NULL);
	for (int x2 = x - 100; x2 < x + 100; x2++) {
		for (int y2 = y - 100; y2 < y + 100; y2++) {
			int dist = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
			if ((dist <= 100) && (dist >= 90)) {
				SetPixel(hdc, x2, y2, RGB(0, 0, 0));
			}
			else if (dist <= 100) {
				SetPixel(hdc, x2, y2, RGB(255, 255, 255));
			}
		}
	}
	size_t taille = strlen( titre );
	for (size_t i = 0; i < taille; i++) {
		char carac = titre[i];
		ecrire(carac, x + (14 * i) - (7 * taille), y - 7);
	}
	taille = strlen( sous_titre );
	for (size_t i = 0; i < taille; i++) {
		char carac = sous_titre[i];
		ecrire(carac, x + (14 * i) - (7 * taille), y + 7);
	}
	ReleaseDC(NULL, hdc);
}

static PyObject* py_cercle(PyObject* self, PyObject* args) // int x, int y, string titre, string sous_titre
{
	long x;
	long y;
	char* titre;
	char* sous_titre;

	if( PyArg_ParseTuple(args, "llss", &x, &y, &titre, &sous_titre) ) {
		cercle(x, y, titre, sous_titre);
	}

	Py_INCREF(Py_None);
	return Py_None;
}


void trait(long xun, long yun, long xdeux, long ydeux) {
	HDC hdc = GetDC(NULL);
	int xdeb = min(xun, xdeux);
	int xfin = max(xun, xdeux);
	int ydeb = min(yun, ydeux);
	int yfin = max(yun, ydeux);
	for (int x = xdeb; x < xfin; x++) {
		for (int y = yun - 2; y < yun + 2; y++) {
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
	}
	for (int x = xdeux - 2; x < xdeux + 2; x++) {
		for (int y = ydeb; y < yfin; y++) {
			SetPixel(hdc, x, y, RGB(0, 0, 0));
		}
	}
	ReleaseDC(NULL, hdc);
}

static PyObject*
py_trait(PyObject* self, PyObject* args) // int xun, int yun, int xdeux, int ydeux
{
	long xun;
	long yun;
	long xdeux;
	long ydeux;

	if( PyArg_ParseTuple(args, "llll", &xun, &yun, &xdeux, &ydeux) ){
		trait(xun, yun, xdeux, ydeux);
	}

	Py_INCREF(Py_None);
	return Py_None;
}



static PyMethodDef ArbresMethods[] = {
	{"taille",  (PyCFunction)py_taille, METH_VARARGS, "Obtenir une des tailles de l'�cran."},
	{"ecrire",  (PyCFunction)py_ecrire, METH_VARARGS, "Ecrire un chiffre ou un symbole math�matique � l'�cran."},
	{"cercle",  (PyCFunction)py_cercle, METH_VARARGS, "Afficher un noeud."},
	{"trait",   (PyCFunction)py_trait,  METH_VARARGS, "Afficher un lien entre deux noeuds."},
	{NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef arbresmodule = {
	PyModuleDef_HEAD_INIT,
	"arbres",   /* name of module */
	"Procure quelque fonctions pour afficher des arbres", /* module documentation, may be NULL */
	0,       /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
	ArbresMethods
};

PyMODINIT_FUNC PyInit_arbres(void) {
	return PyModule_Create(&arbresmodule);
}