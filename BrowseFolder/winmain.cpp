#include <windows.h>
#include <shlobj.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE,LPSTR, int){

	wchar_t buffer[MAX_PATH];

	BROWSEINFO bi; // struktura potrzebna do wywo�ania okna dialogowego przegl�dania folder�w
	bi.hwndOwner = NULL; // uchwyt okna
	bi.pidlRoot = 0; //pidlRoot;
	bi.pszDisplayName = buffer; // wska�nik do bufora pami�ci, gdzie b�dzie przechowywana nazwa wybranego folderu
	bi.lpszTitle = L"Wska� folder"; // tekst informacji, kt�ra wy�wietli si� w oknie
	bi.ulFlags = 0; // tutaj mo�na wstawia� dodatkowe flagi wp�ywaj�ce na spos�b wy�wietlania okna
	bi.lpfn = NULL; // wska�nik funckji zdefiniowanej przez programist�, kt�r� okno dialogowe wywo�a przy okre�lonym zdarzeniu (ja ustawi�em na NULL, czyli brak funkcji)
	bi.lParam = NULL; // dodatkowe parametry do przekazania dla funkcji bi.lpfn
	bi.iImage = 0; // zmienna zawieraj�ca index do systemowej ikony folderu

	ITEMIDLIST *pidl = SHBrowseForFolder(&bi); // wywo�anie okna Przegl�danie w poszukiwaniu folderu

	if(pidl){ // je�eli pidl nie r�wne NULL to
		wchar_t p[MAX_PATH]; // bufor pami�ci
		SHGetPathFromIDList(pidl, p); // pobieram �cie�k� do folderu z pidl
		MessageBox(NULL, p, L"Wybra�e� folder!",MB_OK); // i wy�wietlam w message box-sie
	}

	return 0;
}