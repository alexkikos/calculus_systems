#include "ShowFromFileConsole.h"

using namespace std;


int main()
{
	char a = ' ';
	string file;
	ShowFromFileConsole* f = nullptr;
	while (a != '6')
	{
		switch (a)
		{
		case '1':
			cout << "\nEnter file name like (\"my.dat\"): ";
			cin >> file;
			if (file.size() < 0) cout << "\nWrong filename: ";
			else
				if (f) {
					delete f;
					f = nullptr;
				}
			f = new ShowFromFileConsole(file);
			f->Display();
			break;

		case '2':
			cout << "\nEnter file name like (\"my.dat\"): ";
			cin >> file;
			if (file.size() < 0) cout << "\nWrong filename: ";
			else
				if (f) {
					delete f;
					f = nullptr;
				}
			f = new ShowFromFileConsoleToBinary(file); f->Display();
			break;
		case '3':
			cout << "\nEnter file name like (\"my.dat\"): ";
			cin >> file;
			if (file.size() < 0) cout << "\nWrong filename: ";
			else
				if (f) {
					delete f;
					f = nullptr;
				}
			f = new ShowFromFileConsole_x8(file); f->Display();
			break;
		case '4':
			cout << "\nEnter file name like (\"my.dat\"): ";
			cin >> file;
			if (file.size() < 0) cout << "\nWrong filename: ";
			else
				if (f) {
					delete f;
					f = nullptr;
				}
			f = new ShowFromFileConsoleTo_x16(file); 
			f->Display();
			break;
		case '5':
			cout << "\nEnter file name like (\"my.dat\"): ";
			cin >> file;
			if (file.size() < 0) cout << "\nWrong filename: ";
			else
				if (f) {
					delete f;
					f = nullptr;
				}
			f = new ShowFromFileConsoleAsCii(file);
			f->Display();
			break;
		default:
			break;
		}
		cout << "\n1. Load from files";
		cout << "\n2. Load from files in finary format";
		cout << "\n3. Load from files in 8x format";
		cout << "\n4. Load from files in 16x format: ";
		cout << "\n5. Load from files in ASCII format: ";
		cout << "\n6. Exit\nYour choice: ";
		cin >> a;
	}

	if (f)
	{
		delete f;
		f = nullptr;
	}
	system("pause");
	return 0;
}