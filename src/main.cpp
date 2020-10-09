#include <iostream>
#include "myClass.hpp"

void makeKaffe(short groesse);
void makeCappucino(short groesse);
short settings();


int main()
{
    cl_KaffeVollautomat objKva(500, 300);
    short userSelection;

    std::cout << "\033[1;34;4mWillkommen bei dem Kaffevollautomaten!\033[0m\n\n";
    std::cout << "\033[31mWas würden sie gerne tun?\033[0m\n\n";

    std::cout << "\033[1m[\033[31m1\033[37m] Kaffe\n";
    std::cout << "\033[1m[\033[31m2\033[37m] Cappucino\n";
    std::cout << "\033[1m[\033[31m3\033[37m] Einstellungen\n\n";
    std::cout << "\033[0m> ";
    std::cin >> userSelection;
    system("clear");
    if(userSelection > 3 || userSelection < 1)
    {
        std::cout << "Nicht unterstützte Eingabe, bitte erneut versuchen!";
        return 2;
    }

    switch (userSelection)
    {
    case 1:
        std::cout << "Kaffe wird ausgegeben!\n";
        break;
    case 2:
        std::cout << "Cappucino wird ausgegeben!\n";
        break;
    case 3:
        settings();
        break;
    default:
        break;
    }
}

short settings()
{
    int usrIn;
    std::cout << "\033[1;34;4mEinstellung:\033[0m\n\n";
    std::cout << "\033[1m[\033[31m1\033[37m] Wasser nachfüllen\033[0m\n";
    std::cout << "\033[1m[\033[31m2\033[37m] Bohnen nachfüllen\033[0m\n\n";
    std::cout << "> ";
    std::cin >> usrIn;
    if (usrIn < 1 || usrIn > 2)
    {
        std::cout << "Nicht unterstützte Funktion!\n";
        return 3;
    }
    return usrIn;
    

}