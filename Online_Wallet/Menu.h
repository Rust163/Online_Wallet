#pragma once
#include "OnlineFinance.h"
//определяем числовые значения клавишь для дальнейшего использования в приложении
#define ESC 27
#define UP 72
#define DOWN 80
#define ENTER 13


void showGreeting();
void registrationAndLoginMenu(RegisteringANewUser regUser);
void mainMenu(RegisteringANewUser regUser);