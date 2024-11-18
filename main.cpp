#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::to_string;

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
            switch (selected) {
                case 1:
                {
                    int number;
                    int remaining_number;

                    cout << "Enter a six-digit number: ";
                    cin >> number;

                    if (number >= 100000 && number <= 999999)
                    {
                        int first_digit = number % 10;
                        remaining_number = number / 10;
                        int second_digit = remaining_number % 10;
                        remaining_number = remaining_number / 10;
                        int third_digit = remaining_number % 10;
                        remaining_number = remaining_number / 10;

                        int first_number = first_digit + second_digit + third_digit;

                        first_digit = remaining_number % 10;
                        remaining_number = remaining_number / 10;
                        second_digit = remaining_number % 10;
                        remaining_number = remaining_number / 10;
                        third_digit = remaining_number % 10;

                        cout << "The number is " << (first_number == (first_digit + second_digit + third_digit) ? "happy" : "not happy") << endl;
                    }
                    else
                    {
                        cout << "A number not in six digits" << endl;
                    }
                } break;

                case 2:
                {
                    int number;
                    int remaining_number;

                    cout << "Enter a four-digit number: ";
                    cin >> number;

                    if (number >= 1000 && number <= 9999)
                    {
                        int fourth_number = number % 10;
                        remaining_number = number / 10;
                        int third_number = remaining_number % 10;
                        remaining_number = remaining_number / 10;
                        int second_number = remaining_number % 10;
                        remaining_number = remaining_number / 10;
                        int first_number = remaining_number % 10;

                        string result = to_string(second_number) + to_string(first_number) + to_string(fourth_number) + to_string(third_number);

                        cout << "Result: " << result << endl;
                    }
                    else
                    {
                        cout << "A number not in four digits" << endl;
                    }

                    // OR

                    string number_line = to_string(number);

                    if (number_line.length() != 4) {
                        cout << "A number not in four digits" << endl;
                        break;
                    }
                    
                    cout << "Result: " << number_line[1] << number_line[0] << number_line[3] << number_line[2] << endl;
                } break;

                case 3:
                {
                    int numbers[7];

                    std::cout << "Enter the first number: ";
                    std::cin >> numbers[0];
                    std::cout << "Enter the second number: ";
                    std::cin >> numbers[1];
                    std::cout << "Enter the third number: ";
                    std::cin >> numbers[2];
                    std::cout << "Enter the fourth number: ";
                    std::cin >> numbers[3];
                    std::cout << "Enter the fifth number: ";
                    std::cin >> numbers[4];
                    std::cout << "Enter the sixth number: ";
                    std::cin >> numbers[5];
                    std::cout << "Enter the seventh number: ";
                    std::cin >> numbers[6];

                    cout << "Maximum number out of seven: " << max(numbers[0], numbers[6]) << endl;
                } break;

                case 4:
                {
                    short int fuel_capacity = 300;
                    short int max_fuel = 600;
                    short int min_fuel;
                    int need_fuel;

                    short int distance_A_to_B;
                    short int distance_B_to_C;
                    short int weight;

                    cout << "Enter the distance between point A and B: ";
                    cin >> distance_A_to_B;
                    cout << "Enter the distance between point B and C: ";
                    cin >> distance_B_to_C;
                    cout << "Enter the weight of cargo: ";
                    cin >> weight;

                    if (weight >= 2000)
                    {
                        cout << "The weight of the cargo is too much for the flight!" << endl;
                        break;
                    }
                    else if (weight <= 500) {
                        need_fuel = (distance_A_to_B * 1) + (distance_B_to_C * 1);
                    }
                    else if (weight <= 1000) {
                        need_fuel = (distance_A_to_B * 4) + (distance_B_to_C * 4);
                    }
                    else if (weight <= 1500) {
                        need_fuel = (distance_A_to_B * 7) + (distance_B_to_C * 7);
                    }
                    else {
                        need_fuel = (distance_A_to_B * 9) + (distance_B_to_C * 9);
                    }
                    
                    if (need_fuel >= max_fuel)
                    {
                        cout << "The distance is too far!" << endl;
                        break;
                    }

                    min_fuel = need_fuel - fuel_capacity;

                    if (min_fuel <= 0)
                    {
                        cout << "You do not need to refuel at point B" << endl;
                        break;
                    }

                    cout << "The minimum amount of fuel required to fly from point A to point B: " << min_fuel << "liters" << endl;
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