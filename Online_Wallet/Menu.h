#pragma once
#include "OnlineFinance.h"
//���������� �������� �������� ������� ��� ����������� ������������� � ����������
#define ESC 27
#define UP 72
#define DOWN 80
#define ENTER 13

void ConsoleCursorVisible(short size, bool show);
void showGreeting();
void registrationAndLoginMenu(RegisteringANewUser regUser);
void mainMenu(RegisteringANewUser regUser);
void menuOfReports();
void menuOfReportsDaily();
void menuOfReportsWeekly();
void menuOfReportsMonthly();
