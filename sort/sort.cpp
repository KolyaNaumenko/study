#include <iostream>
#include <string>
#include "array.cpp"
#include "list.cpp""
#include "lib.cpp""
using namespace std;

string M;
void Menu() {
	cout << "    MENU\n"
		<< "(0) Quit\n"
		<< "(1) Array\n"
		<< "(2) List\n"
		<< "(3) Vector\n"
		<< "Your choice: ";
	cin >> M;
};

int main() {

	ArrayList Arlst;
	List<int> lst;
	VectorList Veclst;

	system("pause");
	system("cls");
	Menu();

	while (M != "0") {

		if (M == "1") {
			system("cls");

			Arlst.MainFunc();

			system("pause");
			system("cls");
			Menu();
			system("cls");
		}
		else if (M == "2") {
			system("cls");

			lst.MainFunc();

			system("pause");
			system("cls");
			Menu();
			system("cls");
		}
		else if (M == "3") {
			system("cls");

			Veclst.MainFunc();

			system("pause");
			system("cls");
			Menu();
			system("cls");
		}
		else {
			system("cls");

			cout << "There are not such option. Choose another.\n";

			system("pause");
			system("cls");
			Menu();
			system("cls");
		}
	}
}