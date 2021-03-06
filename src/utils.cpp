#include "Menus.h"


void clearScreen(){
	system("cls");
}

void pauseScreen(){
	getchar();
}

void upCase(string &str) {
	size_t i = 0;

	while (i < str.length()) {
		str.at(i) = tolower(str.at(i));
		i++;
	}

	if (str == "de" || str == "do" || str == "da" || str == "das" || str == "dos" || str == "e") return;

	str.at(0) = toupper(str.at(0));
}

void normalize(string &str)
{
	istringstream iss(str);
	string final_str;

	while (iss >> str) {
		upCase(str);
		final_str = final_str + " " + str;
	}

	final_str.erase(0, 1);

	str = final_str;
}

void trim(string &str)
{
	int i = 0;
	int spacesBegin = 0;
	while (' ' == str[i++])
	{
		spacesBegin++;
	}

	i = str.length();
	int spacesEnd = 0;

	while (' ' == str[--i])
	{
		spacesEnd++;
	}

	int strLength;

	strLength = str.length() - spacesBegin - spacesEnd;

	str = str.substr(spacesBegin, strLength);
}


int showOptions(int first, int last) 
{
	
	string option_str;
	int option_int;

	try {

		cout << endl << TAB << "Op��o: ";

		getline(cin, option_str);
		
		if (cin.eof()) throw InvalidInput();

		option_int = stoi(option_str);

		if (option_int < first || option_int > last) throw WrongOption(1, 5);

		return option_int;
	}
	catch (WrongOption wp) {
		cout << endl << wp;
		return showOptions(first, last);
	}
	catch (InvalidInput ii) {
		cout << endl << ii;
		cin.clear();
		return showOptions(first, last);
	}catch (invalid_argument) {
		cout << endl << TAB << "Erro na introdu��o dos dados." << endl;
		cout << TAB << "Deve introduzir um n�mero." << endl;
		return showOptions(first, last);
	}
	
	
}