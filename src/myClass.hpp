#include <iostream>

class cl_KaffeVollautomat
{
public:
    cl_KaffeVollautomat(int in_wasserstand, int in_bohnenMenge)
    {
        this->wasserstand = in_wasserstand;
        this->bohnenMenge = in_bohnenMenge;
        this->lang        = "en";
    }

    void machEinKaffe(int wassermenge, int bohnenmenge)
    {
        this->wasserstand = this->wasserstand - wassermenge;
        this->bohnenMenge = this->bohnenMenge - bohnenmenge;
    }

    void machEinCapuccino(int wassermenge, int bohnenmenge)
    {
        this->wasserstand = this->wasserstand - wassermenge;
        this->bohnenMenge = this->bohnenMenge - bohnenmenge;
    }

    void changeLanguage(std::string usrLang)
    {
        this->lang = usrLang;
    }

    void wasserNachfuellen(int in_wasserstand)
    {
        if ((in_wasserstand + this->wasserstand) <= this->max_wasserstand)
        {
            this->wasserstand = this->wasserstand + in_wasserstand;
        }
        else
        {
            if(this->lang == "de")
            {
                std::cout << "Zu viel Wasser, na toll, jetzt ist alles ausgelaufen\n" << std::endl;
            } else if (this->lang == "en")
            {
                std::cout << "Too much water, now the thing overflowed and everything fell out\n" << std::endl;
            }
            
            for (int i = 5; i > 0; i--)
            {
                std::cout << "\r" << i;
                fflush(stdout);
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            this->wasserstand = 0;
        }
        
    }
    void bohnenNachfuelle(int in_bohnenMenge)
    {
        if ((in_bohnenMenge + this->bohnenMenge) <= this->max_bohnenMenge)
        {
            this->bohnenMenge = this->bohnenMenge + in_bohnenMenge;
        }
        else
        {
            if(this->lang == "de")
            {
                std::cout << "Zu viele Bohnen, na toll, jetzt sind alle rausgefallen!\n" << std::endl;
            } else if (this->lang == "en")
            {
                std::cout << "Too many Beanz, now the box overflowed and everything fell out!\n" << std::endl;
            }
            
            for (int i = 5; i > 0; i--)
            {
                std::cout << "\r" << i;
                fflush(stdout);
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            this->bohnenMenge = 0;
        }
        
    }


    int getWasserstand()
    {
        return this->wasserstand;
    }
    int getBohnenMenge()
    {
        return this->bohnenMenge;
    }
    std::string getLang()
    {
        return this->lang;
    }

protected:
private:
    int bohnenMenge;
    const int max_bohnenMenge = 700;

    int wasserstand;
    const int max_wasserstand = 1000;

    std::string lang;
};