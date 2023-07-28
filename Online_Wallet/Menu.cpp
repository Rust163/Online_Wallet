#include <iostream>
#include <windows.h>
#include <conio.h>
#include "OnlineFinance.h"
#include "Menu.h"

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void d(short x, short y) {
    SetConsoleCursorPosition(h, { x,y });
}
void ConsoleCursorVisible(short size, bool show = false) {
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(h, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(h, &structCursorInfo);
}

void showGreeting() {
    ShowCursor(FALSE);
    std::cout << "\t\t\t\t\*******************************************************\n";
    std::cout << "\t\t\t\t\*                                                     *\n";
    std::cout << "\t\t\t\t\*       Welcome to online wallet and debet card!      *\n";
    std::cout << "\t\t\t\t\*                                                     *\n";
    std::cout << "\t\t\t\t\*******************************************************\n";
}

void registrationAndLoginMenu(RegisteringANewUser regUser) {
    ShowCursor(FALSE);
    std::string T[] = { "Log in to the program", "Registration in the program", "Exit" };//��������� ������ ���� ���������� ������ ����
    char aT = 1;// ���������� ��� �������� ���������� ������ ����
    char c; // ���������� ��� �������� ���� ������� �������.
    while (true) { //��������� ����������� ����
        char x = 50, y = 12; // ���������� ������ �������
        d(x, y);// �������� ������� ������� ������������� ������� ������� �� ������� � ������� �������� ���������
        for (char i = 0; i < size(T); i++) { // ���������� � ����������� �������� ������� �����
            if (i == aT) {
                SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //��������� ����� �� ���������� i �������� aT � ���� �����, �� ��������������� ���� ������ � ������� ������� SetConsoleTextAttribute()
            }
            else {
                SetConsoleTextAttribute(h, FOREGROUND_BLUE); // ���� �� ����� �� ������ ������ ����
            }
            d(x, y++);// ������� ������������� ������� ������� �� ��������� ������ � ������� ������ T[i] �� �������.
            std::cout << T[i] << std::endl;
        }
        c = _getch();// ����������� ������� ������� � ������� ������� _getch(), t��� ������� ������� -32 �� ����������� ��������� ���� �������.
        if (c == -32) {
            c = _getch();
        }
        switch (c) {
        case ESC:
            exit(0);
        case UP: //���� ������� ������� UP, � �������� aT ������ 0, �� ����������� �������� aT �� 1
            if (aT > 0)
                --aT;
            break;
        case DOWN: //���� ������� ������� DOWN, � �������� aT ������ ������� ������� T - 1, �� ������������� �������� aT �� 1
            if (aT < size(T) - 1)
                ++aT;
            break;
        case ENTER:
            switch (aT) {
            case 0:
            {
                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                regUser.entranceUser();
                std::cout << "���������� \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 1:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                regUser.signupUser();
                std::cout << "���������� \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 2:
            {
                exit(0);
                break;
            }
            default:
                std::cout << "" << (char)c << std::endl;
            }
        }
    }
}

void mainMenu(RegisteringANewUser regUser) {
    ShowCursor(FALSE);
    std::string T[] = { "Show card balance", "Show the balance of the accumulative wallet", "Show creditcard balance", "Money transfer", "View card details", "Exit" };
    char aT = 0;
    char c;
    while (true) {
        char x = 50, y = 12;
        d(x, y);
        for (char i = 0; i < size(T); i++) {
            if (i == aT) SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            else SetConsoleTextAttribute(h, FOREGROUND_RED);
            d(x, y++);
            std::cout << T[i] << std::endl;
        }
        c = _getch();
        if (c == -32) c = _getch();
        switch (c) {
        case ESC:
            exit(0);
        case UP:
            if (aT > 0)
                --aT;
            break;
        case DOWN:
            if (aT < size(T) - 1)
                ++aT;
            break;
        case ENTER:
            switch (aT) {
            case 0:
            {
                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "���������� \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 1:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "���������� \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 2:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "���������� \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 3:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "���������� \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 4:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "���������� \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 5:
            {
                exit(0);
                break;
            }
            default:
                std::cout << "" << (char)c << std::endl;
            }
        }
    }
}
    
