#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include "OnlineFinance.h"
#include "Menu.h"

HANDLE q = GetStdHandle(STD_OUTPUT_HANDLE);
void u(short x, short y) {
	SetConsoleCursorPosition(q, { x, y });
}
void ConsoleCursorVis(short size, bool show) {
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(q, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(q, &structCursorInfo);
}

std::string sumbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string pathReg = "userPasLog.txt";
std::string pathSber = "Sberbank.txt";
std::string pathAlfa = "AlfaBank.txt";
std::string pathTin = "TinkoffBank.txt";

int RegisteringANewUser::keyCode(char l) {
	for (int i = 0; i < sumbols.length(); i++) {
		if (l == sumbols[i]) {
			return i;
		}
	}
}

std::string RegisteringANewUser::cryptUserLogin(std::string _login, std::string _codeWord, std::string _cryptLogin) {
	RegisteringANewUser regUser[20];
	std::ofstream out;
	out.open(pathReg, std::fstream::in | std::fstream::out | std::fstream::app);
	
	std::cout << "Input login: ";
	std::cin >> _login;
	std::cout << "Input code word: ";
	std::cin >> _codeWord;
	for (int i = 0; i < _cryptLogin.length(); i++) {
		_cryptLogin += sumbols[(keyCode(_login[i]) + keyCode(_codeWord[i % _codeWord.length()])) % sumbols.length()];
		out.write((char*)&regUser[i]._cryptLogin, sizeof(regUser[i]._cryptLogin));
	}
	return _cryptLogin;
	
	out.close();
}

std::string RegisteringANewUser::cryptUserPassword(std::string _password, std::string _codeWord) {
	std::string cryptPassword;
	for (int i = 0; i < cryptPassword.length(); i++) {
		cryptPassword += sumbols[(keyCode(_login[i]) + keyCode(_codeWord[i % _codeWord.length()])) % sumbols.length()];
	}
	return cryptPassword;
}

std::string RegisteringANewUser::decryptUserLogin(std::string _login, std::string _codeWord) {
	std::string decryptLogin;
	for (int i = 0; i < decryptLogin.length(); i++) {
		decryptLogin += sumbols[(keyCode(_login[i]) - keyCode(_codeWord[i % _codeWord.length()]) + sumbols.length()) % sumbols.length()];
	}
	return decryptLogin;
}

std::string RegisteringANewUser::decryptUserPassword(std::string _password, std::string _codeWord) {
	std::string decryptPassword;
	for (int i = 0; i < decryptPassword.length(); i++) {
		decryptPassword += sumbols[(keyCode(_login[i]) - keyCode(_codeWord[i % _codeWord.length()]) + sumbols.length()) % sumbols.length()];
	}
	return decryptPassword;
}

void RegisteringANewUser::checkingAndHidingThePassword(std::string _password) {
	RegisteringANewUser regUser;
	std::ofstream out;
	out.open(pathReg, std::fstream::in | std::fstream::out | std::fstream::app);
	int ch = 0;
	while (true) {
		ch = _getch();
		if (ch == 13) {
			break;
		}
		else if (ch == 8) {
			std::cout << (char)8 << ' ' << (char)8;
			_password.erase(_password.length() - 1);
		}
		else {
			std::cout << '*';
			_password = _password + (char)ch;
		}
	}
	out.write((char*)&_password, sizeof(_password));
	std::cout << std::endl;
	
	std::cout << "\t\t\t\t\t\t  Repeat the password: ";
	std::string passwordVerification;
	while (true) {
		ch = _getch();
		if (ch == 13) {
			break;
		}
		else if (ch == 8) {
			std::cout << (char)8 << ' ' << (char)8;
			passwordVerification.erase(passwordVerification.length() - 1);
		}
		else {
			std::cout << '*';
			passwordVerification = passwordVerification + (char)ch;
		}
	}
	std::cout << std::endl;
	if (_password == passwordVerification) {
		std::cout << "Passwords match!" << std::endl;
		system("cls");
		mainMenu(regUser);
		
	}
	else {
		std::cout << "Passwords not match. Try again!" << std::endl;
	}
}

Banks RegisteringANewUser::changeBankName() {
	RegisteringANewUser regUser;
	std::string B[] = { "Sberbank", "Alfa Bank", "OTPBank" };//Объявляем массив сток содержащий пункты меню
	char aB = 1;// переменная для хранения выбранного пункта меню
	char m; // переменная для хранения кода нажатой клавиши.
	while (true) { //Запускаем бесконечный цикл
		char x = 50, y = 12; // координаты вывода консоли
		u(x, y);// вызываем функцию которая устанавливает позицию курсора на консоли с помощью заданных координат
		for (char i = 0; i < size(B); i++) { // перебираем и индексируем элементы массива строк
			if (i == aB) {
				SetConsoleTextAttribute(q, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //проверяем равна ли переменная i значению aT и если равна, то устанавливается цвет текста с помощью функции SetConsoleTextAttribute()
			}
			else {
				SetConsoleTextAttribute(q, FOREGROUND_GREEN); // если не равно то ставим другой цвет
			}
			u(x, y++);// функция устанавливает позицию курсора на следующую строку и выводит строку T[i] на консоль.
			std::cout << B[i] << std::endl;
		}
		m = _getch();// Считывается нажатая клавиша с помощью функции _getch(), tсли считана клавиша -32 то считывается следующий байт клавиши.
		if (m == -32) {
			m = _getch();
		}
		switch (m) {
		case ESC:
			exit(0);
		case UP: //Если считана клавиша UP, и значение aT больше 0, то уменьшается значение aT на 1
			if (aB > 0)
				--aB;
			break;
		case DOWN: //Если считана клавиша DOWN, и значение aT меньше размера массива T - 1, то увеличивается значение aT на 1
			if (aB < size(B) - 1)
				++aB;
			break;
		case ENTER:
			switch (aB) {
			case 0:
			{
				system("CLS");
				u(x, y);
				SetConsoleTextAttribute(q, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::string sber = "Sberbank";
				if (sber == "Sberbank") {
					std::ofstream fileSberO;
					fileSberO.open(pathSber, std::ofstream::app);
					OnlineFinance infoUser;
					Banks _nameBank{};
					Card userCard;
					CreditCard userCred;
					Wallet userWallet;
					if (!fileSberO) {
						std::cout << "Error opening file!" << std::endl;
					}
					else {
						while (!feof) {
							std::cout << "Input your first name: ";
							fileSberO.write((char*)&infoUser._firstName, 20);
							std::cin >> infoUser._firstName;
							std::cout << "Input your last name: ";
							fileSberO.write((char*)&infoUser._lastName, 20);
							std::cin >> infoUser._lastName;
							std::cout << "Input name your wallet: ";
							fileSberO.write((char*)&userWallet._nameWallet, 20);
							std::cin >> userWallet._nameWallet;
							std::cout << "Input payment account wallet: ";
							std::cin >> userWallet._paymentAccountWallet;
						}
					}
					fileSberO.close();
				}
				system("CLS");
				break;
			}
			case 1:
			{

				system("CLS");
				u(x, y);
				SetConsoleTextAttribute(q, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::string alfa = "AlfaBank";
				if (alfa == "AlfaBank") {
					std::ofstream fileAlfaO;
					fileAlfaO.open(pathAlfa, std::ofstream::app);
					OnlineFinance infoUser;
					Banks _nameBank{};
					Card userCard;
					CreditCard userCred;
					Wallet userWallet;
					if (!fileAlfaO) {
						std::cout << "Error opening file!" << std::endl;
					}
					else {
						while (!feof) {
							std::cout << "Input your first name: ";
							fileAlfaO.write((char*)&infoUser._firstName, 20);
							std::cin >> infoUser._firstName;
							std::cout << "Input your last name: ";
							fileAlfaO.write((char*)&infoUser._lastName, 20);
							std::cin >> infoUser._lastName;
							std::cout << "Input name your wallet: ";
							fileAlfaO.write((char*)&userWallet._nameWallet, 20);
							std::cin >> userWallet._nameWallet;
							std::cout << "Input payment account wallet: ";
							std::cin >> userWallet._paymentAccountWallet;
						}
					}
					fileAlfaO.close();
				}
				system("CLS");
				break;
			}
			case 2:
			{
				system("CLS");
				u(x, y);
				SetConsoleTextAttribute(q, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::string tinkoff = "Tinkoff";
				if (tinkoff == "Tinkoff") {
					std::ofstream fileTinkoffO;
					fileTinkoffO.open(pathTin, std::ofstream::app);
					OnlineFinance infoUser;
					Banks _nameBank{};
					Card userCard;
					CreditCard userCred;
					Wallet userWallet;
					if (!fileTinkoffO) {
						std::cout << "Error opening file!" << std::endl;
					}
					else {
						while (!feof) {
							std::cout << "Input your first name: ";
							fileTinkoffO.write((char*)&infoUser._firstName, 20);
							std::cin >> infoUser._firstName;
							std::cout << "Input your last name: ";
							fileTinkoffO.write((char*)&infoUser._lastName, 20);
							std::cin >> infoUser._lastName;
							std::cout << "Input name your wallet: ";
							fileTinkoffO.write((char*)&userWallet._nameWallet, 20);
							std::cin >> userWallet._nameWallet;
							std::cout << "Input payment account wallet: ";
							std::cin >> userWallet._paymentAccountWallet;
						}
					}
					fileTinkoffO.close();
				}
				system("CLS");
				break;
			}
			default:
				std::cout << "" << (char)m << std::endl;
			}
		}
	}
}


void RegisteringANewUser::signupUser() {
	RegisteringANewUser regUser;
	std::string _firstName; std::string _lastName; std::string _login; std::string _password;
	std::ofstream out;
	out.open(pathReg, std::fstream::in | std::fstream::out | std::fstream::app);
	std::cout << "You are logged in to the registration system, enter your data\n\t\t\t\t\t\t  (first name, last name), create a login and password!!" << std::endl;
	if (!out.is_open()) {

		std::cout << "File opening error!" << std::endl;
	}
	else {
		std::cout << "\t\t\t\t\t\t  Enter your name: ";
		std::cin >> regUser._firstName;
		out.write((char*)&regUser._firstName, sizeof(regUser._firstName));
		std::cout << std::endl;
		std::cout << "\t\t\t\t\t\t  Enter your last name: ";
		std::cin >> regUser._lastName;
		out.write((char*)&regUser._lastName, sizeof(regUser._lastName));
		std::cout << std::endl;
		RegisteringANewUser::cryptUserLogin( _login, _codeWord, _cryptLogin);
		//std::cout << "\t\t\t\t\t\t  Enter login: ";
		//std::cin >> regUser._login;
		
		std::cout << std::endl;
		std::cout << "\t\t\t\t\t\t  Enter password: ";
		checkingAndHidingThePassword(_password);
		
	}
	
}

void RegisteringANewUser::entranceUser() {
	RegisteringANewUser regUser;
	std::ifstream in;
	in.open(pathReg, std::ios::binary);
	std::string _login;
	std::string _password;
	std::string log;
	std::string pass;
	std::string B[] = { "Sberbank", "Alfa Bank", "OTPBank" };
	char aB = 1;
	char x = 50, y = 12;
	std::cout << "  Enter your login: "; 
	
	
	std::cout << "\t\t\t\t\t\t  Enter your password: ";
	int ch = 0;
	while (true) {
		ch = _getch();
		if (ch == 13) {
			break;
		}
		else if (ch == 8) {
			std::cout << (char)8 << ' ' << (char)8;
			pass.erase(pass.length() - 1);
		}
		else {
			std::cout << '*';
			pass = pass + (char)ch;
		}
	}
	std::cout << std::endl;
	if (log != _login || pass != _password ) {
		std::cout << "The username or password was entered incorrectly. Try again." << std::endl;
	}
	else {
		std::cout << "You have successfully logged in" << std::endl;
		mainMenu(regUser);
	}
	in.close();
}

void RegisteringANewUser::addUserCardInfo() {
	std::ofstream fileOut;
	fileOut.open(pathReg, std::ofstream::app);
	OnlineFinance infoUser;
	Banks _nameBank{};
	Card userCard;
	CreditCard userCred;
	Wallet userWallet;
	if (!fileOut) {
		std::cout << "Error opening file!" << std::endl;
	}
	else {
		for (int i = 0; i < sizeof(OnlineFinance); i++) {
			std::cout << "Input your first name: ";
			fileOut.write((char*)&infoUser._firstName, 20);
			std::cin >> infoUser._firstName;
			std::cout << "Input your last name: ";
			fileOut.write((char*)&infoUser._lastName, 20);
			std::cin >> infoUser._lastName;
			std::cout << "Input your name bank: ";
			//changeBankName(_nameBank);
			std::string _nameWallet;
			int _paymentAccountWallet;
			std::cout << "Input name your wallet: ";
			fileOut.write((char*)&userWallet._nameWallet, 20);
			std::cin >> userWallet._nameWallet;
			std::cout << "Input payment account wallet: ";
			std::cin >> userWallet._paymentAccountWallet;
		}
	}
	fileOut.close();
}

void RegisteringANewUser::showInfoUser() {
	std::ifstream fileIn;
	fileIn.open(pathReg, std::ifstream::app);
	OnlineFinance infoUser;
	Banks _nameBank{};
	Card userCard;
	CreditCard userCred;
	Wallet userWallet;
	if (!fileIn) {
		std::cout << "Error opening file!" << std::endl;
	}
	else {
		OnlineFinance of;
		Wallet uw;
		while (fileIn.read((char*)&of, sizeof(OnlineFinance)) && fileIn.read((char*)&uw, sizeof(Wallet))) {
				//fileIn.read((char*)&of._firstName, sizeof(OnlineFinance));
				std::cout << "First name: " << std::endl;
				//fileIn.read((char*)&of._lastName, sizeof(OnlineFinance));
				std::cout << "Last name: " << std::endl;
				//changeBankName(_nameBank);
				std::cout << "Name bank: " << std::endl;
				//std::string _nameWallet;
				//int _paymentAccountWallet;
				//fileIn.read((char*)&uw._nameWallet, sizeof(Wallet));
				std::cout << "Name wallet: " << std::endl;
				//fileIn.read((char*)&uw._paymentAccountWallet, sizeof(Wallet));
				std::cout << "Account wallet: " << std::endl;
		}
	}
	fileIn.close();
}

void RegisteringANewUser::costReport() {
	std::cout << "Here will be your cost report by category" << std::endl;
}

