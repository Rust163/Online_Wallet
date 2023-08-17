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
    std::cout << "\t\t\t\t\*******************************************************\n";
    std::cout << "\t\t\t\t\*                                                     *\n";
    std::cout << "\t\t\t\t\*       Welcome to online wallet and debet card!      *\n";
    std::cout << "\t\t\t\t\*                                                     *\n";
    std::cout << "\t\t\t\t\*******************************************************\n";
}

void registrationAndLoginMenu(RegisteringANewUser regUser) {
    std::string T[] = { "Log in to the program", "Registration in the program", "Exit" };//ќбъ€вл€ем массив сток содержащий пункты меню
    char aT = 1;// переменна€ дл€ хранени€ выбранного пункта меню
    char c; // переменна€ дл€ хранени€ кода нажатой клавиши.
    while (true) { //«апускаем бесконечный цикл
        char x = 50, y = 12; // координаты вывода консоли
        d(x, y);// вызываем функцию котора€ устанавливает позицию курсора на консоли с помощью заданных координат
        for (char i = 0; i < size(T); i++) { // перебираем и индексируем элементы массива строк
            if (i == aT) {
                SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //провер€ем равна ли переменна€ i значению aT и если равна, то устанавливаетс€ цвет текста с помощью функции SetConsoleTextAttribute()
            }
            else {
                SetConsoleTextAttribute(h, FOREGROUND_GREEN); // если не равно то ставим другой цвет
            }
            d(x, y++);// функци€ устанавливает позицию курсора на следующую строку и выводит строку T[i] на консоль.
            std::cout << T[i] << std::endl;
        }
        c = _getch();// —читываетс€ нажата€ клавиша с помощью функции _getch(), tсли считана клавиша -32 то считываетс€ следующий байт клавиши.
        if (c == -32) {
            c = _getch();
        }
        switch (c) {
        case ESC:
            exit(0);
        case UP: //≈сли считана клавиша UP, и значение aT больше 0, то уменьшаетс€ значение aT на 1
            if (aT > 0) {
                --aT;
            }
            break;
        case DOWN: //≈сли считана клавиша DOWN, и значение aT меньше размера массива T - 1, то увеличиваетс€ значение aT на 1
            if (aT < size(T) - 1) {
                ++aT;
            }
            break;
        case ENTER:
            switch (aT) {
            case 0:
            {
                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                regUser.entranceUser();
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 1:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                regUser.signupUser();
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
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
    std::string T[] = { "1) Show card balance", "2) Show the balance of the accumulative wallet", "3) Show creditcard balance", "4) Show cost report", "5) Money transfer", "6) View card details", "7) Add user", "8) Exit" };
    char aT = 0;
    char c;
    while (true) {
        char x = 50, y = 12;
        d(x, y);
        for (char i = 0; i < size(T); i++) {
            if (i == aT) {
                SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(h, FOREGROUND_RED);
            }
            d(x, y++);
            std::cout << T[i] << std::endl;
        }
        c = _getch();
        if (c == -32) {
            c = _getch();
        }
        switch (c) {
        case ESC:
            exit(0);
        case UP:
            if (aT > 0) {
                --aT;
            }
            break;
        case DOWN:
            if (aT < size(T) - 1) {
                ++aT;
            }
            break;
        case ENTER:
            switch (aT) {
            case 0:
            {
                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 1:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 2:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 3:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                menuOfReports();
                //system("CLS");
                break;
            }
            case 4:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 5:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                //regUser.addUserCardInfo();
                regUser.changeBankName();
                system("CLS");
                break;
            }
            case 6:
            {
                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 7:
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

void menuOfReports() {
    RegisteringANewUser regUser;
    std::string T[] = { "1) Daily reports", "2) Weekly reports", "3) Monthly reports", "4) Back menu"  };
    char aT = 0;
    char c;
    while (true) {
        char x = 50, y = 12;
        d(x, y);
        for (char i = 0; i < size(T); i++) {
            if (i == aT) {
                SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(h, FOREGROUND_RED);
            }
            d(x, y++);
            std::cout << T[i] << std::endl;
        }
        c = _getch();
        if (c == -32) {
            c = _getch();
        }
        switch (c) {
        case ESC:
            exit(0);
        case UP:
            if (aT > 0) {
                --aT;
            }
            break;
        case DOWN:
            if (aT < size(T) - 1) {
                ++aT;
            }
            break;
        case ENTER:
            switch (aT) {
            case 0:
            {
                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                menuOfReportsDaily();
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 1:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                menuOfReportsWeekly();
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 2:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                menuOfReportsMonthly();
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 3:
            {
                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                mainMenu(regUser);
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            default:
                std::cout << "" << (char)c << std::endl;
            }
        }
    }
}

void menuOfReportsDaily() {
    std::string T[] = { "1) Daily cost reports", "2) Daily category reports", "3) Back menu"};
    char aT = 0;
    char c;
    while (true) {
        char x = 50, y = 12;
        d(x, y);
        for (char i = 0; i < size(T); i++) {
            if (i == aT) {
                SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(h, FOREGROUND_RED);
            }
            d(x, y++);
            std::cout << T[i] << std::endl;
        }
        c = _getch();
        if (c == -32) {
            c = _getch();
        }
        switch (c) {
        case ESC:
            exit(0);
        case UP:
            if (aT > 0) {
                --aT;
            }
            break;
        case DOWN:
            if (aT < size(T) - 1) {
                ++aT;
            }
            break;
        case ENTER:
            switch (aT) {
            case 0:
            {
                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 1:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 2:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                menuOfReports();
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            default:
                std::cout << "" << (char)c << std::endl;
            }
        }
    }
}

void menuOfReportsWeekly() {
    std::string T[] = { "1) Weekly cost reports", "2) Weekly category reports", "3) Back menu" };
    char aT = 0;
    char c;
    while (true) {
        char x = 50, y = 12;
        d(x, y);
        for (char i = 0; i < size(T); i++) {
            if (i == aT) {
                SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(h, FOREGROUND_RED);
            }
            d(x, y++);
            std::cout << T[i] << std::endl;
        }
        c = _getch();
        if (c == -32) {
            c = _getch();
        }
        switch (c) {
        case ESC:
            exit(0);
        case UP:
            if (aT > 0) {
                --aT;
            }
            break;
        case DOWN:
            if (aT < size(T) - 1) {
                ++aT;
            }
            break;
        case ENTER:
            switch (aT) {
            case 0:
            {
                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 1:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 2:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                menuOfReports();
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            default:
                std::cout << "" << (char)c << std::endl;
            }
        }
    }
}

void menuOfReportsMonthly() {
    std::string T[] = { "1) Monthly cost reports", "2) Monthly category reports", "3) Back menu" };
    char aT = 0;
    char c;
    while (true) {
        char x = 50, y = 12;
        d(x, y);
        for (char i = 0; i < size(T); i++) {
            if (i == aT) {
                SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(h, FOREGROUND_RED);
            }
            d(x, y++);
            std::cout << T[i] << std::endl;
        }
        c = _getch();
        if (c == -32) {
            c = _getch();
        }
        switch (c) {
        case ESC:
            exit(0);
        case UP:
            if (aT > 0) {
                --aT;
            }
            break;
        case DOWN:
            if (aT < size(T) - 1) {
                ++aT;
            }
            break;
        case ENTER:
            switch (aT) {
            case 0:
            {
                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 1:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 2:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                menuOfReports();
                std::cout << "ќзнакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }

            default:
                std::cout << "" << (char)c << std::endl;
            }
        }
    }
}
    
