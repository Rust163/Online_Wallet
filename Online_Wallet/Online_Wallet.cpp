#include <iostream>
#include <windows.h>
#include <conio.h>
#include "OnlineFinance.h"
#include "Menu.h"


int main() {
    RegisteringANewUser regUser;
    ConsoleCursorVisible(50, false);
    showGreeting();
    //registrationAndLoginMenu(regUser);
    //regUser.showInfoUser();
    //regUser.signupUser();
    //regUser.addUserCardInfo();
    mainMenu(regUser);
    //regUser.changeBankName();
}