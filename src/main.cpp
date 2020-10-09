#include <iostream>
#include <thread>
#include <chrono>

#include "myClass.hpp"

void bohneNachfuellen();
void wasserNachfuellen();
void makeKaffe(short groesse, int bohnenBehaelter, int wasserBehaelter);
void makeCappucino(short groesse, int bohnenBehaelter, int wasserBehaelter);
short settings();


int main()
{
    // cl_KaffeVollautomat objKva(500, 300);
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
        makeKaffe(1, 500, 300);
        break;
    case 2:
        std::cout << "Cappucino wird ausgegeben!\n\n";
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
    switch (usrIn)
    {
        case 1:
            bohneNachfuellen();
        default:
            break;
    }
    return usrIn;
}

void bohneNachfuellen()
{
    int in_bohnen;
    std::cout << "\033[1;34;4mWie viele Bohnen sollen nachgefüllt werden?\033[0m\n\n";
    std::cout << "> ";
    std::cin >> in_bohnen;

    if (in_bohnen < 0)
    {
        std::cout << "\n\nGarnicht gut! Du kannst nicht in das Bohnenfach greifen und welche Rausholen!\n";
        system("clear");
        main();
    } else
    {
        
    }
    
    
}

void makeKaffe(short groesse, int bohnenBehaelter, int wasserBehaelter)
{
    cl_KaffeVollautomat objKva(500, 300);
    std::cout << "\033[1m[\033[31mIhr Kaffe wird jetzt zubereitet, bitte Warten!\033[0m]\n\n";
    for (int i = 100; i > 0; i--)
    {
        //int randd = rand() % 100;
        //std::cout << ". ";

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << "\n\n";    
}