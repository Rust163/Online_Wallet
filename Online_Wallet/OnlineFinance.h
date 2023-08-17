#pragma once
#include <iostream>
#include <string>



enum class Banks { // перечисления наименований банков
	Sberbank,
	AlfaBank,
	OTPBank
};

class RegisteringANewUser {
public:
	std::string _firstName;
	std::string _lastName;
private:
	std::string _login;
	std::string _cryptLogin;
	std::string _password;
	std::string _codeWord;
public:
	RegisteringANewUser() {};
	RegisteringANewUser(std::string firstName, std::string lastName, std::string login, std::string cryptLogin, std::string password, std::string codeWord) {
		this->_firstName = firstName;
		this->_lastName = lastName;
		this->_login = login;
		this->_cryptLogin = cryptLogin;
		this->_password = password;
		this->_codeWord = codeWord;
	}
	int keyCode(char s);
	std::string cryptUserLogin(std::string _login, std::string codeWord, std::string _cryptLogin);
	std::string cryptUserPassword(std::string _password, std::string codeWord);
	std::string decryptUserLogin(std::string _login, std::string codeWord);
	std::string decryptUserPassword(std::string _password, std::string codeWord);
	void checkingAndHidingThePassword(std::string _password);
	Banks changeBankName();
	void signupUser();
	void entranceUser();
	void addUserCardInfo();
	void showInfoUser();
	void costReport();
};

class OnlineFinance : public RegisteringANewUser {
public:
	Banks  _nameBank; //поле с названием банка
	int _replenish{0}; // пополнение кошелька или карты
	int _transferToAnotherCard{0}; // перевод с кошелька или карты
	double _interestRate{0}; // процентная ставка для кредитной карты
	bool _closeAccount{false}; // закрыть кошелек или карту

	OnlineFinance() {};

	OnlineFinance(Banks nameBank,
		int replenish,
		int transferToAnotherCard,
		double interestRate,
		bool closeAccount) 
	{
		this->_nameBank = nameBank;
		this->_replenish = replenish;
		this->_transferToAnotherCard = transferToAnotherCard;
		this->_interestRate = interestRate;
		this->_closeAccount = closeAccount;
	}
};

class Wallet : public OnlineFinance {
public:
	std::string _nameWallet; // имя кошелька
	int _paymentAccountWallet; // номер счета кошелька
	Wallet() {};
	Wallet(std::string nameWallet, int paymentAccountWallet){
		this->_nameWallet = nameWallet;
		this->_paymentAccountWallet = paymentAccountWallet;
	}

	void SetNameWallet(std::string nameWallet) {
		this->_nameWallet = nameWallet;
	}

	std::string GetNameWallet() {
		return _nameWallet;
	}
};

class Card : public OnlineFinance {
private:
	std::string _nameCard; //имя дебетовой карты
	int _paymentAccountCard; // номер счета дебетовой карты
};

class CreditCard : public OnlineFinance {
private:
	std::string _nameCreditCard; // имя кредитки
	int _paymentAccountCreditCard; // номер счета кредитки
};

