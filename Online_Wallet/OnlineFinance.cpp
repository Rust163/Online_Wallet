#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "OnlineFinance.h"
#include "Menu.h"
std::string sumbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string pathReg = "userPasLog.txt";

int RegisteringANewUser::keyCode(char s) {
	for (int i = 0; i < sumbols.length(); i++) {
		if (s == sumbols[i]) {
			return i;
		}
	}
}

std::string RegisteringANewUser::cryptUserLogin(std::string _login, std::string _codeWord) {
	std::string cryptLogin;
	for (int i = 0; i < cryptLogin.length(); i++) {
		cryptLogin += sumbols[(keyCode(_login[i]) + keyCode(_codeWord[i % _codeWord.length()])) % sumbols.length()];
	}
	return cryptLogin;
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
	}
	else {
		std::cout << "Passwords not match. Try again!" << std::endl;
	}
}

void RegisteringANewUser::signupUser() {
	std::string _firstName; std::string _lastName; std::string _login; std::string _password;
	std::ofstream out;
	out.open(pathReg, std::ios::binary);
	std::cout << "You are logged in to the registration system, enter your data\n\t\t\t\t\t\t  (first name, last name), create a login and password!!" << std::endl;
	if (!out) {
		std::cout << "File opening error!" << std::endl;
	}
	else {
		std::cout << "\t\t\t\t\t\t  Enter your name: ";
		out.write((char*)&_firstName, sizeof(_firstName));
		std::cin >> _firstName;
		std::cout << std::endl;
		std::cout << "\t\t\t\t\t\t  Enter your last name: ";
		out.write((char*)&_lastName, sizeof(_lastName));
		std::cin >> _lastName;
		std::cout << std::endl;
		std::cout << "\t\t\t\t\t\t  Enter login: ";
		out.write((char*)&_login, sizeof(_login));
		std::cin >> _login;
		std::cout << std::endl;
		std::cout << "\t\t\t\t\t\t  Enter password: ";
		checkingAndHidingThePassword(_password);
		out.write((char*)&_password, sizeof(_password));
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
	std::cout << "\t\t\t\t\t\t  Enter your login: ";
	std::cin >> log;
	std::cout << "\t\t\t\t\t\t  Enter your password: ";
	std::cin >> pass;
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
	
}

void RegisteringANewUser::showInfoUser(std::string firstName, std::string lastName, std::string login, std::string password) {

}
