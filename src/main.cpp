#include <iostream>
#include <thread>
#include <chrono>

#include "myClass.hpp"

void bohneNachfuellen();
void wasserNachfuellen();
void makeKaffe();
void makeCappuccino();
short settings();

cl_KaffeVollautomat objKva(500, 300);

int main()
{
    system("clear");
    // cl_KaffeVollautomat objKva(500, 300);
    short userSelection;

    if (objKva.getLang() == "de")
    {
        std::cout << "\033[1;34;4mWillkommen bei dem Kaffevollautomaten!\033[0m\n\n";
        std::cout << "\033[31mWas würden sie gerne tun?\033[0m\n\n";

        std::cout << "\033[1m[\033[31m1\033[37m] Kaffe\n";
        std::cout << "\033[1m[\033[31m2\033[37m] Cappucino\n";
        std::cout << "\033[1m[\033[31m3\033[37m] Einstellungen\n";
        std::cout << "\033[1m[\033[31m4\033[37m] Exit\n\n";
    }
    else if (objKva.getLang() == "en")
    {
        std::cout << "\033[1;34;4mWelcome to the coffe machine!\033[0m\n\n";
        std::cout << "\033[31mWhat would you like to do?\033[0m\n\n";

        std::cout << "\033[1m[\033[31m1\033[37m] Coffee\n";
        std::cout << "\033[1m[\033[31m2\033[37m] Cappucino\n";
        std::cout << "\033[1m[\033[31m3\033[37m] Settings\n";
        std::cout << "\033[1m[\033[31m4\033[37m] Exit\n\n";
    }

    std::cout << "\033[0m> ";
    std::cin >> userSelection;
    system("clear");
    if (userSelection > 4 || userSelection < 1)
    {
        if (objKva.getLang() == "de")
        {
            std::cout << "Nicht unterstützte Eingabe, bitte erneut versuchen!";
        }
        else if (objKva.getLang() == "en")
        {
            std::cout << "Your input is not supported!";
        }

        return 2;
    }

    switch (userSelection)
    {
    case 1:
        makeKaffe();
        break;
    case 2:
        makeCappuccino();
        break;
    case 3:
        settings();
        break;
    case 4:
        return 5;
    default:
        break;
    }
}

short settings()
{
    int temp;
    int usrIn;
    system("clear");

    if (objKva.getLang() == "de")
    {
        std::cout << "\033[1;34;4mEinstellung:\033[0m\n\n";
        std::cout << "\033[1;37m[\033[31m1\033[37m] Wasser nachfüllen\033[0m\n";
        std::cout << "\033[1;37m[\033[31m2\033[37m] Bohnen nachfüllen\033[0m\n";
        std::cout << "\033[1;37m[\033[31m3\033[37m] Wasserstand anzeigen\033[0m\n";
        std::cout << "\033[1;37m[\033[31m4\033[37m] Bohnenstand anzeigen\033[0m\n";
        std::cout << "\033[1;37m[\033[31m5\033[37m] Sprache Ändern\033[0m\n";
        std::cout << "\033[1;37m[\033[31m6\033[37m] Zurück\033[0m\n\n";
    }
    else if (objKva.getLang() == "en")
    {
        std::cout << "\033[1;34;4mSettings:\033[0m\n\n";
        std::cout << "\033[1;37m[\033[31m1\033[37m] Refill Water\033[0m\n";
        std::cout << "\033[1;37m[\033[31m2\033[37m] Refill Beanz\033[0m\n";
        std::cout << "\033[1;37m[\033[31m3\033[37m] Show water volume\033[0m\n";
        std::cout << "\033[1;37m[\033[31m4\033[37m] Show bean volume\033[0m\n";
        std::cout << "\033[1;37m[\033[31m5\033[37m] Change language\033[0m\n";
        std::cout << "\033[1;37m[\033[31m6\033[37m] Back\033[0m\n\n";
    }

    std::cout << "> ";
    std::cin >> usrIn;
    if (usrIn < 1 || usrIn > 6)
    {
        if (objKva.getLang() == "de")
        {
            std::cout << "Nicht unterstützte Funktion!\n";
        }
        else if (objKva.getLang() == "en")
        {
            std::cout << "Unsupported function!\n";
        }

        return 3;
    }
    std::string usrLang;
    switch (usrIn)
    {
    case 1:
        wasserNachfuellen();
        break;
    case 2:
        bohneNachfuellen();
        break;
    case 3:
        if (objKva.getLang() == "de")
        {
            std::cout << "\033[1;37mLiter:\033[0m " << objKva.getWasserstand() << "\n\n";
        }
        else if (objKva.getLang() == "en")
        {
            std::cout << "\033[1;37mLitres:\033[0m " << objKva.getWasserstand() << "\n\n";
        }

        for (int i = 5; i > 0; i--)
        {
            std::cout << "\r" << i;
            fflush(stdout);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        settings();
        break;
    case 4:
        if (objKva.getLang() == "de")
        {
            std::cout << "\033[1;37mBohnen im Behälter:\033[0m " << objKva.getBohnenMenge() << std::endl;
        }
        else if (objKva.getLang() == "en")
        {
            std::cout << "\033[1;37mBeanz in the box:\033[0m " << objKva.getBohnenMenge() << std::endl;
        }

        for (int i = 5; i > 0; i--)
        {
            std::cout << "\r" << i;
            fflush(stdout);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        settings();
        break;
    case 5:
        if (objKva.getLang() == "de")
        {
            std::cout << "\033[1;37mBitte Länder-code eingeben (2 Buchstaben)\n\033[0m";
            std::cout << "[1;37m[\033[31men\033[37m]\n";
            std::cout << "[1;37m[\033[31mde\033[37m]\n\n";
        }
        else if (objKva.getLang() == "en")
        {
            std::cout << "\033[1;37mPlease input your language code (2 character)\n\033[0m";
            std::cout << "\033[1;37m[\033[31men\033[37m]\n";
            std::cout << "\033[1;37m[\033[31mde\033[37m]\n\n";
        }

        std::cout << "> ";
        std::cin >> usrLang;
        objKva.changeLanguage(usrLang);
        settings();
        break;
    case 6:
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
    system("clear");
    int in_wasser;
    if (objKva.getLang() == "de")
    {
        std::cout << "\033[1;34;4mWie viele Liter Wasser sollen nachgefüllt werden?\033[0m\n\n";
    }
    else if (objKva.getLang() == "en")
    {
        std::cout << "\033[1;34;4mHow many litres of Water should be refilled?\033[0m\n\n";
    }

    std::cout << "> ";
    std::cin >> in_wasser;

    if (in_wasser < 0)
    {
        system("clear");
        if (objKva.getLang() == "de")
        {
            std::cout << "\n\nGarnicht gut! Du kannst nicht einfach Wasser aus dem Fach heraus holen!\n\n";
        }
        else if (objKva.getLang() == "en")
        {
            std::cout << "\n\nThat doesnt work, you cant just grab water out of the box!\n\n";
        }

        for (int i = 5; i > 0; i--)
        {
            std::cout << "\r" << i;
            fflush(stdout);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        system("clear");
        settings();
    }
    else
    {
        objKva.wasserNachfuellen(in_wasser);
        settings();
    }
}

void bohneNachfuellen()
{
    system("clear");
    int in_bohnen;
    if (objKva.getLang() == "de")
    {
        std::cout << "\033[1;34;4mWie viele Bohnen sollen nachgefüllt werden?\033[0m\n\n";
    }
    else if (objKva.getLang() == "en")
    {
        std::cout << "\033[1;34;4mHow many Beanz should be refilled?\033[0m\n\n";
    }
    std::cout << "> ";
    std::cin >> in_bohnen;

    if (in_bohnen < 0)
    {
        system("clear");
        if (objKva.getLang() == "de")
        {
            std::cout << "\n\nGarnicht gut! Du kannst nicht in das Bohnenfach greifen und welche Rausholen!\n\n";
        }
        else if (objKva.getLang() == "en")
        {
            std::cout << "\n\nThat does'nt work, you cant just grab beanz out of the box!\n\n";
        }

        for (int i = 5; i > 0; i--)
        {
            std::cout << "\r" << i;
            fflush(stdout);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        system("clear");
        settings();
    }
    else
    {
        objKva.bohnenNachfuelle(in_bohnen);
        settings();
    }
}

void makeKaffe()
{
    //cl_KaffeVollautomat objKva(500, 300);
    if (objKva.getLang() == "de")
    {
        std::cout << "\033[1m[\033[31mIhr Kaffe wird jetzt zubereitet, bitte Warten!\033[0m]\n\n";
    }
    else if (objKva.getLang() == "en")
    {
        std::cout << "\033[1m[\033[31mYour coffee is being prepared, please wait!\033[0m]\n\n";
    }

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

void makeCappuccino()
{
    if (objKva.getLang() == "de")
    {
        std::cout << "\033[1m[\033[31mIhr Cappuccino wird jetzt zubereitet, bitte Warten!\033[0m]\n\n";
    }
    else if (objKva.getLang() == "en")
    {
        std::cout << "\033[1m[\033[31mYour cappuccino is being prepared, please wait!\033[0m]\n\n";
    }

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
