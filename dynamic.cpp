#include <windows.h>
#include <iostream>

using namespace std;
typedef void(*LibraryFunction)(char*, char*, char*);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char inpStr[256];
	char inpChar;
	char outStr[256];
	HINSTANCE hLib;							
	LibraryFunction  f;						

	hLib = LoadLibrary(TEXT("DLL2.dll"));	
	if (hLib == NULL) 						
	{
		printf("Невозможно загрузить библиотеку 'DLL2.dll'!\n");
		return;
	}

	cout << "Динамическое подключение библиотеки" << endl;
	cout << "Введите строку: ";
	cin.getline(inpStr, 256);
	cout << "Введите букву: ";
	cin >> inpChar;
	f = (LibraryFunction)GetProcAddress(hLib, "LastSymb");
	if (!f)												
		printf("Невозможно найти функцию 'LastSymb'!\n\n");
	else
	{
		f(inpStr, outStr, &inpChar);
		cout << "Новая строка: ";
		cout << outStr << endl;
	}

	system("pause");

	FreeLibrary(hLib);									
}
