#include <iostream>

class cl_KaffeVollautomat
{
public:
    cl_KaffeVollautomat(int in_wasserstand, int in_bohnenMenge)
    {
        this->wasserstand = in_wasserstand;
        this->bohnenMenge = in_bohnenMenge;
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


    void wasserNachfuellen(int in_wasserstand)
    {
        if ((in_wasserstand + this->wasserstand) <= this->max_wasserstand)
        {
            this->wasserstand = this->wasserstand + in_wasserstand;
        }
        else
        {
            std::cout << "Zu viel Wasser, na toll, jetzt ist alles ausgelaufen" << std::endl;
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
            std::cout << "Zu viele Bohnen, na toll, jetzt sind alle rausgefallen!" << std::endl;
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

protected:
private:
    int bohnenMenge;
    const int max_bohnenMenge = 700;

    int wasserstand;
    const int max_wasserstand = 1000;
};