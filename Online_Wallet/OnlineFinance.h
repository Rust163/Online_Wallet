#pragma once
#include <string>



enum class Banks { // перечисления наименований банков
	Sberbank = 1,
	AlfaBank = 2,
	OTPBank = 3
};

class RegisteringANewUser {
private:
	std::string _firstName;
	std::string _lastName;
	std::string _login;
	std::string _password;
	std::string _codeWord;
public:
	RegisteringANewUser() {};
	RegisteringANewUser(std::string firstName, std::string lastName, std::string login, std::string password, std::string codeWord) {
		this->_firstName = firstName;
		this->_lastName = lastName;
		this->_login = login;
		this->_password = password;
		this->_codeWord = codeWord;
	}
	int keyCode(char s);
	std::string cryptUserLogin(std::string _login, std::string codeWord);
	std::string cryptUserPassword(std::string _password, std::string codeWord);
	std::string decryptUserLogin(std::string _login, std::string codeWord);
	std::string decryptUserPassword(std::string _password, std::string codeWord);
	void checkingAndHidingThePassword(std::string _password);
	void signupUser();
	void entranceUser();
	void showInfoUser(std::string firstName, std::string lastName, std::string login, std::string password);
};

class OnlineFinance : public RegisteringANewUser {
public:
	Banks _nameBank; //поле с названием банка
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

