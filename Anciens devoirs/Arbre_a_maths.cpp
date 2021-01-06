#include <windows.h>
#include "wtypes.h"
#include <iostream>
#include <string>
#include <math.h>   
#include "Arbre_a_maths.h"

#define ErrorMessageBox(a,b) MessageBox(a,b,"Error:",MB_ICONWARNING);
using namespace std;

HDC hdc = GetDC(NULL);

int horizontal = 0;
int vertical = 0;
int nbre_noeuds = 0;
int symbols[3] = { 111, 222, 333 };

void ecrire(char carac, int x, int y) {
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
}

int ** calculer(string expr, int taille, int x, int y) {
	int emplacement = expr.find("+");
	int emplacement2 = expr.find("/");
	int emplacement3 = expr.find("*");
	int* result[3];
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
	if (emplacement != string::npos) {
		result[0] = &symbols[0];
		ecrire('+', x, y);
		result[1] = *calculer(expr.substr(0, emplacement), emplacement, x-150, y+150);
		result[2] = *calculer(expr.substr(emplacement+1, taille), taille-emplacement-1, x+150, y+150);
		nbre_noeuds = nbre_noeuds + 1;
	}
	else if (emplacement2 != string::npos) {
		result[0] = &symbols[1];
		ecrire('/', x, y);
		result[1] = *calculer(expr.substr(0, emplacement2), emplacement2, x - 150, y + 150);
		result[2] = *calculer(expr.substr(emplacement2 + 1, taille), taille - emplacement2 - 1, x + 150, y + 150);
		nbre_noeuds = nbre_noeuds + 1;
	}
	else if (emplacement3 != string::npos) {
		result[0] = &symbols[2];
		ecrire('*', x, y);
		result[1] = *calculer(expr.substr(0, emplacement3), emplacement3, x - 150, y + 150);
		result[2] = *calculer(expr.substr(emplacement3 + 1, taille), taille - emplacement3 - 1, x + 150, y + 150);
		nbre_noeuds = nbre_noeuds + 1;
	}
	else {
		int noeud[3] = { stoi(expr), 0, 0 };
		for (int i = 0; i < taille; i++) {
			char carac = expr[i];
			ecrire(carac, x+15*i, y);
		}
		int* ptr = noeud;
		nbre_noeuds = nbre_noeuds + 1;
		return (&ptr);
	}
	return result;
}

// Get the horizontal and vertical screen sizes in pixel
void GetDesktopResolution(int& horizontal, int& vertical)
{
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	horizontal = desktop.right;
	vertical = desktop.bottom;
}

int main() {
	GetDesktopResolution(horizontal, vertical);
	cout << "Entrez votre expression: " << endl;
	string expr;
	cin >> expr;
	cout << "Votre expression est: " << expr << endl;
	int taille = expr.length();

	calculer(expr, taille, horizontal/2, 100);
	
	cout << "Entrez n'importe quoi puis appuyez sur Entrée pour fermer." << endl;
	char test;
	cin >> test;
	ReleaseDC(NULL, hdc);
	return 0;
}
