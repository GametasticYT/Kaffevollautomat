#include <iostream>
#include <thread>
#include <chrono>

#include "myClass.hpp"
// #include "globalObj.h"


void bohneNachfuellen();
void wasserNachfuellen();
void makeKaffe();
void makeCappucino();
short settings();

cl_KaffeVollautomat objKva(500, 300);

int main()
{
    system("clear");
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
        makeKaffe();
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
    int temp;
    int usrIn;
    system("clear");
    std::cout << "\033[1;34;4mEinstellung:\033[0m\n\n";
    std::cout << "\033[1;37m[\033[31m1\033[37m] Wasser nachfüllen\033[0m\n";
    std::cout << "\033[1;37m[\033[31m2\033[37m] Bohnen nachfüllen\033[0m\n";
    std::cout << "\033[1;37m[\033[31m3\033[37m] Wasserstand anzeigen\033[0m\n";
    std::cout << "\033[1;37m[\033[31m4\033[37m] BohnenStand anzeigen\033[0m\n";
    std::cout << "\033[1;37m[\033[31m5\033[37m] Zurück\033[0m\n\n";
    

    std::cout << "> ";
    std::cin >> usrIn;
    if (usrIn < 1 || usrIn > 5)
    {
        std::cout << "Nicht unterstützte Funktion!\n";
        return 3;
    }
    switch (usrIn)
    {
        case 1:
            wasserNachfuellen();
            break;
        case 2:
            bohneNachfuellen();
            break;
        case 3:
            std::cout << "\033[1;37mLiter:\033[0m " << objKva.getWasserstand() << "\n\n";
            for (int i = 5; i > 0; i--)
            {
                std::cout << "\r" << i;
                fflush(stdout);
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            settings();
            break;
        case 4:
            std::cout << "\033[1;37mBohnen im Behälter:\033[0m " << objKva.getBohnenMenge() << std::endl;
            for (int i = 5; i > 0; i--)
            {
                std::cout << "\r" << i;
                fflush(stdout);
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            settings();
            break;
        case 5:
            system("clear");
            main();
            break;
        default:
            break;
    }
    return usrIn;
}

void wasserNachfuellen()
{
    int in_wasser;
    std::cout << "\033[1;34;4mWie viele Liter Wasser sollen nachgefüllt werden?\033[0m\n\n";
    std::cout << "> ";
    std::cin >> in_wasser;

    if (in_wasser < 0)
    {
        std::cout << "\n\nGarnicht gut! Du kannst nicht einfach Wasser aus dem Fach heraus holen!";
        system("clear");
        main();
    } else {
        objKva.wasserNachfuellen(in_wasser);
        settings();
    }
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
        objKva.bohnenNachfuelle(in_bohnen);
        settings();
    }
}

void makeKaffe()
{
    //cl_KaffeVollautomat objKva(500, 300);
    std::cout << "\033[1m[\033[31mIhr Kaffe wird jetzt zubereitet, bitte Warten!\033[0m]\n\n";
    for (int i = 47; i > 0; i--)
    {
        int randd = rand() % 500;
        std::cout << "-";
        fflush(stdout);
        
        
        std::this_thread::sleep_for(std::chrono::milliseconds(randd));
    }
    objKva.machEinKaffe(rand() % 300, rand() % 100);
    std::cout << ">";
    std::cout << "\n\n";
    main();    
}

void makeCapuccino()
{
    std::cout << "\033[1m[\033[31mIhr Kaffe wird jetzt zubereitet, bitte Warten!\033[0m]\n\n";
    for (int i = 47; i > 0; i--)
    {
        int randd = rand() % 500;
        std::cout << "-";
        fflush(stdout);
        std::this_thread::sleep_for(std::chrono::milliseconds(randd));
    }
    objKva.machEinCapuccino(rand() % 300, rand() % 180);
    std::cout << ">";
    std::cout << "\n\n";
    main();
}
