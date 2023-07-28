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
    std::string T[] = { "Log in to the program", "Registration in the program", "Exit" };//Объявляем массив сток содержащий пункты меню
    char aT = 1;// переменная для хранения выбранного пункта меню
    char c; // переменная для хранения кода нажатой клавиши.
    while (true) { //Запускаем бесконечный цикл
        char x = 50, y = 12; // координаты вывода консоли
        d(x, y);// вызываем функцию которая устанавливает позицию курсора на консоли с помощью заданных координат
        for (char i = 0; i < size(T); i++) { // перебираем и индексируем элементы массива строк
            if (i == aT) {
                SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //проверяем равна ли переменная i значению aT и если равна, то устанавливается цвет текста с помощью функции SetConsoleTextAttribute()
            }
            else {
                SetConsoleTextAttribute(h, FOREGROUND_BLUE); // если не равно то ставим другой цвет
            }
            d(x, y++);// функция устанавливает позицию курсора на следующую строку и выводит строку T[i] на консоль.
            std::cout << T[i] << std::endl;
        }
        c = _getch();// Считывается нажатая клавиша с помощью функции _getch(), tсли считана клавиша -32 то считывается следующий байт клавиши.
        if (c == -32) {
            c = _getch();
        }
        switch (c) {
        case ESC:
            exit(0);
        case UP: //Если считана клавиша UP, и значение aT больше 0, то уменьшается значение aT на 1
            if (aT > 0)
                --aT;
            break;
        case DOWN: //Если считана клавиша DOWN, и значение aT меньше размера массива T - 1, то увеличивается значение aT на 1
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
                std::cout << "Ознакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 1:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                regUser.signupUser();
                std::cout << "Ознакомлен \"" << T[aT] << "\"";
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
                std::cout << "Ознакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 1:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "Ознакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 2:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "Ознакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 3:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "Ознакомлен \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 4:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "Ознакомлен \"" << T[aT] << "\"";
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
    
