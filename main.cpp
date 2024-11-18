#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using std::cout;
using std::endl;
using std::cin;

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(output, pos);
}

void setcolor(unsigned short color) {
    HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(con, color);
}

void set_background_color(unsigned short color) {
    HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(con, (color << 4) | 0x0F);
}

void display_menu(int selected) {
    int y_coord = 2;

    system("cls");

    cout << "#>-------<MENU>-------<#" << endl;
    cout << "|                      |" << endl;
    cout << "|      First Task      |" << endl;
    cout << "|      Second Task     |" << endl;
    cout << "|      Third Task      |" << endl;
    cout << "|      Fourth Task     |" << endl;
    cout << "|      Exit            |" << endl;
    cout << "|                      |" << endl;
    cout << "#>--------------------<#" << endl;

    for (int i = 1; i <= 5; ++i) {
        gotoxy(7, y_coord);

        if (i == selected) {
            set_background_color(0x0A);
        }
        else {
            setcolor(7);
        }

        switch (i) {
            case 1: cout << "First Task"; break;
            case 2: cout << "Second Task"; break;
            case 3: cout << "Third Task"; break;
            case 4: cout << "Fourth Task"; break;
            case 5: cout << "Exit"; break;
        }

        y_coord++;
    }

    setcolor(7);
}

int main() {
    int selected = 1;
    display_menu(selected);

    while (true) {
        char choice = _getch();

        if (choice == -32) { // Arrow keys
            choice = _getch();

            switch (choice) {
                case 72: // Up arrow
                    if (selected > 1) selected--;
                    break;

                case 80: // Down arrow
                    if (selected < 5) selected++;
                    break;
            }
            display_menu(selected);
        }
        else if (choice == 13) { // Enter key
            system("cls");
            int first_number;
            int second_number;
            
            switch (selected) {
                case 1:
                {
                    cout << "Enter the number: ";
                    cin >> first_number;

                    cout << "The number is " << ((first_number % 2 == 0) ? "even" : "odd") << endl;
                } break;

                case 2:
                {
                    cout << "Enter the first number: ";
                    cin >> first_number;
                    cout << "Enter the second number: ";
                    cin >> second_number;

                    cout << "The " << ((first_number < second_number) ? first_number : second_number) << " is smaller" << endl;
                } break;

                case 3:
                {
                    cout << "Enter the number: ";
                    cin >> first_number;
                    
                    cout << "The " << first_number << " is ";
                    if (first_number > 0)
                    {
                        cout << "bigger than 0" << endl;
                    }
                    else if (first_number == 0)
                    {
                        cout << "equals than 0" << endl;
                    }
                    else {
                        cout << "smaller than 0" << endl;
                    }
                } break;

                case 4:
                {
                    cout << "Enter the first number: ";
                    cin >> first_number;
                    cout << "Enter the second number: ";
                    cin >> second_number;

                    if (first_number == second_number)
                    {
                        cout << "The numbers are equal to each other" << endl;
                    }
                    else if (first_number > second_number)
                    {
                        cout << "The " << first_number << " is bigger than " << second_number << endl;
                    }
                    else
                    {
                        cout << "The " << second_number << " is bigger than " << first_number << endl;
                    }
                } break;

                case 5:
                {
                    return 0;
                } break;
            }

            cout << endl << endl;
            system("pause");
            display_menu(selected);
        }
    }

    return 0;
}