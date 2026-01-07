#include <iostream>

/*

Mějme informační systém kina, který eviduje prodané lístky.
Každý lístek má svůj film a číslo sedadla.
Pokud si zákazník koupí běžný lístek, cena je vždy 200 korun, je možné ale že se použije slevový kód.
Pokud jde o volňásek, cena i sleva náš systém nezajímá obě jsou 0.
Pro VIP lístky může být cena individuální. U VIP lístků můžeme přenastavit sedadlo i po koupi.
Na kioscích v kinosálech může zákazník zjistit svoje číslo sedadla. V případě nespokojenosti může být dodatečně změněna
sleva a navrátit z ceny zákazníkovi kus ceny.

 */

class Ticket {
public:
    std::string m_film;
    int m_seatNumber;
    float m_price;
    float m_discount;
    bool m_vip;

    // full constructor
    Ticket(std::string film, int seatNumber, float price, float discount, bool vip) {
        // KISS example se setrem
        setDiscount(discount);
        m_film = film;
        m_seatNumber = seatNumber;
        m_price = price;
        m_vip = vip;
    }

    // standard ticket stejná cena moznost slevy
    Ticket(std::string film, int seatNumber, float discount) : Ticket(film, seatNumber, 200.0, discount, false) {}

    // free ticket nezajima nas cena ani sleva
    Ticket(std::string film, int seatNumber) : Ticket(film, seatNumber, 0.0, 0.0, false) {}

    void printInfo() {
        std::string isVip = "Ticket is not VIP";
        if (m_vip) {
            isVip = "Ticket is VIP";
        }

        std::cout << "Ticket for film : " << m_film << "\n"
        << "Seat number: " << m_seatNumber << "\n"
        << "Full original price: " << m_price << "\n"
        << "Discount: " << m_discount << "%; Price after discount: " << m_price * (1 - m_discount / 100) << "\n"
        << isVip << "\n" << std::endl;
    }

    // kontrola spravnosti
    void setDiscount(float discount) {
        if (discount < 0 || discount > 100) {
            m_discount = 0;
            std::cout << "Discount can not be lower than 0% or higher than 100%; automatically set to 0%"  << std::endl;
        } else {
            m_discount = discount;
        }
    }

    // nastavovat sedadlo po tvorbe listku muze jen vip
    void setSeatNumber(int number) {
        if (!m_vip) {
            std::cout << "Seat Number cannot be reset if the ticket is not VIP." << std::endl;
        } else {
            m_seatNumber = number;
            std::cout << "Seat changed to: " << m_seatNumber << std::endl;
        }
    }

    // v pripade napojeni na pomocny kiosek v sale kdyz zakanik zapomene cislo
    int getSeatNumber() {
        return m_seatNumber;
    }
};

int main() {
    Ticket* standardTicket = new Ticket("Crocodile Dundee 3", 34, 10);
    Ticket* freeTicket = new Ticket("Crocodile Dundee 2", 35);
    Ticket* vipTicket = new Ticket("Crocodile Dundee 1", 36, 300, -10.0, true);

    standardTicket->printInfo();
    standardTicket->setSeatNumber(1);

    freeTicket->printInfo();

    vipTicket->printInfo();
    vipTicket->setSeatNumber(2);
    vipTicket->printInfo();

    delete standardTicket;
    delete vipTicket;
    delete freeTicket;
    return 0;
}