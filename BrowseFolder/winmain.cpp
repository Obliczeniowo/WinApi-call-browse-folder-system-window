#include <windows.h>
#include <shlobj.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE,LPSTR, int){

	wchar_t buffer[MAX_PATH];

	BROWSEINFO bi; // struktura potrzebna do wywo³ania okna dialogowego przegl¹dania folderów
	bi.hwndOwner = NULL; // uchwyt okna
	bi.pidlRoot = 0; //pidlRoot;
	bi.pszDisplayName = buffer; // wskaŸnik do bufora pamiêci, gdzie bêdzie przechowywana nazwa wybranego folderu
	bi.lpszTitle = L"Wska¿ folder"; // tekst informacji, która wyœwietli siê w oknie
	bi.ulFlags = 0; // tutaj mo¿na wstawiaæ dodatkowe flagi wp³ywaj¹ce na sposób wyœwietlania okna
	bi.lpfn = NULL; // wskaŸnik funckji zdefiniowanej przez programistê, któr¹ okno dialogowe wywo³a przy okreœlonym zdarzeniu (ja ustawi³em na NULL, czyli brak funkcji)
	bi.lParam = NULL; // dodatkowe parametry do przekazania dla funkcji bi.lpfn
	bi.iImage = 0; // zmienna zawieraj¹ca index do systemowej ikony folderu

	ITEMIDLIST *pidl = SHBrowseForFolder(&bi); // wywo³anie okna Przegl¹danie w poszukiwaniu folderu

	if(pidl){ // je¿eli pidl nie równe NULL to
		wchar_t p[MAX_PATH]; // bufor pamiêci
		SHGetPathFromIDList(pidl, p); // pobieram œcie¿kê do folderu z pidl
		MessageBox(NULL, p, L"Wybra³eœ folder!",MB_OK); // i wyœwietlam w message box-sie
	}

	return 0;
}