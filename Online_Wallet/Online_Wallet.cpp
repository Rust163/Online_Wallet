#include <iostream>
#include <windows.h>
#include <conio.h>
#include "OnlineFinance.h"
#include "Menu.h"


int main() {
    ShowCursor(FALSE);
    RegisteringANewUser regUser;
    showGreeting();
    registrationAndLoginMenu(regUser);
    mainMenu(regUser);
    
	
}