#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

/*

Vytvořme informační systém, který bude spravovat zákazníky ve věrnostním programu pro eshop. Každý zákazník má jméno,
unikátní ID, evidujeme jakou má aktuálně slevu a kolik celkem utratil. Jméno se zadává konstruktorem. ID je generováno
automaticky jako pořadové číslo. Sleva je ve výchozím stavu 5 %, ale můžeme ji také zadat jinou v konstruktoru.

Můžeme přidat do součtu nákupů novou útratu. Jméno, ID a aktuální výši slevy jsme schopni vracet.

Každý zákazník také zvyšuje automaticky svoji slevu podle nákupů. Pokaždé, když překročí 10 tis. Kč, které utratil,
tak se mu sleva zvýší o jedno procento. Maximálně však bude mít celkovou slevu 20 %.

Dále máme správce zákazníků, který nám pomáhá spravovat zákazníky našeho eshopu. Pokud si budeme chtít vytvořit nového
zákazníka, tak jej nebudeme vytvářet přímo, ale použijeme na to našeho správce. U toho zavoláme metodu, která se jmenuje
např. createCustomer() a ta pro nás zákazníka vytvoří podle naší potřeby. Budeme počítat, že zákazníci jsou 3 typů:
běžní zákazníci, ti dostanou výchozí slevu, pak firemní zákazníci, kteří ji mají nižší, pouze 3 % a VIP zákazníci,
kteří ji mají 10 %. Této metodě předáme pouze typ zákazníka, jeho jméno a ona pro nás zákazníka vytvoří "na míru".

Zákazníka si také zaeviduje do svého seznamu a umožní nám, abychom ho kdykoliv dohledali.

K tomu bude sloužit metoda findCustomerById(), které předáme ID zákazníka a ona ho buď vyhledá a vrátí nebo vypíše chybu.
Dále budeme mít metodu findCustomersByName(), které předáme jméno a ona vrátí seznam všech zákazníků, kteří mají dané jméno.

 */

enum class CustomerType {
    Vip, Basic, Corporate
};

class Customer {
    static int s_customerCounter;

    string m_name;
    int m_clubId;
    int m_totalSpent;
    float m_discountPercentage;

    void setName(string name) {
        if (!name.empty()) {
            m_name = name;
        } else {
            m_name = "No name";
            cout << "Name has to be specified." << endl;
        }
    }

    void setDiscountPercentage(float discount) {
        if (discount >= 0 && discount <= 1) {
            m_discountPercentage = discount;
        } else {
            m_discountPercentage = 0.05;
            cout << "Discount has to be between 0 and 1 (it's a percentage)" << endl;
        }
    }

    void updateDiscount(float purchasePrice) {
        // rozdil do dalsiho milniku 10000
        float needForUpgrade = 10000 - m_totalSpent % 10000;
        if (needForUpgrade <= purchasePrice && m_discountPercentage < 0.2) {
            // kolikrat nas nakup prekroci
            int howManyUpgrades = (int) trunc(purchasePrice / 10000); // funkce trunc nam odebere desetinne cislo
            m_discountPercentage += 0.01 * howManyUpgrades;
            if (m_discountPercentage > 0.2) m_discountPercentage = 0.2;
            cout << "Discount upgraded: " << m_discountPercentage << endl;
        } else {
            cout << "For new discount upgrade you need: " << needForUpgrade - purchasePrice << endl;
        }
    }

public:
    Customer(string name, float discount) {
        m_clubId = s_customerCounter;
        s_customerCounter++;
        m_totalSpent = 0;

        setName(name);
        setDiscountPercentage(discount);
    }

    Customer (string name) : Customer(name, 0.05) {}

    string getName() {
        return m_name;
    }

    int getId() {
        return m_clubId;
    }

    float getDiscountPercentage() {
        return m_discountPercentage;
    }

    void addPurchase(float amount) {
        updateDiscount(amount);
        m_totalSpent += amount;
    }

    static int getCustomerCounter() {
        return s_customerCounter;
    }
};

int Customer::s_customerCounter = 0;

class CustomerOrganizer {
    vector<Customer*> m_customers;
public:
    CustomerOrganizer() {
        m_customers = {};
    }

    ~CustomerOrganizer() {
        for (Customer* customer : m_customers) {
            delete customer;
        }
    }

    Customer* createCustomer(string name, CustomerType type) {
        Customer* customer;

        switch (type) {
            case CustomerType::Vip:
                customer = new Customer(name, 0.1);
                break;
            case CustomerType::Basic:
                customer = new Customer(name);
                break;
            case CustomerType::Corporate:
                customer = new Customer(name, 0.03);
                break;
        }

        m_customers.push_back(customer);
        return customer;
    }

    Customer* findCustomerById(int id) {
        if (m_customers.empty() || id >= Customer::getCustomerCounter()) {
            cout << "The ID is out of scope." << endl;
            return nullptr;
        }

        for (Customer* customer : m_customers) {
            if (customer->getId() == id) {
                cout << "Customer found" << endl;
                return customer;
            }
        }

        cout << "Customer not found." << endl;
        return nullptr;
    }

    vector<Customer*> findCustomersByName(string name) {
        if (m_customers.empty()) {
            return {};
        }

        vector<Customer*> suitableCustomers = {};

        for (Customer* customer : m_customers) {
            if (customer->getName() == name) {
                suitableCustomers.push_back(customer);
            }
        }

        return suitableCustomers;
    }

    void deleteCustomerById(int id) {
        if (m_customers.empty() || id >= Customer::getCustomerCounter()) {
            return;
        }

        int position = 0;
        for (Customer* customer : m_customers) {
            if (customer->getId() == id) {
                m_customers.erase(m_customers.begin() + position);
                delete customer;

                cout << "Customer succesfully deleted." << endl;
                return;
            }
            position++;
        }
    }
};

int main() {
    CustomerOrganizer* organizer = new CustomerOrganizer();

    Customer* c1 = organizer->createCustomer("Pepa", CustomerType::Basic);
    Customer* c2 = organizer->createCustomer("Pepa", CustomerType::Vip);
    Customer* c3 = organizer->createCustomer("Jarek", CustomerType::Corporate);

    c1->addPurchase(20000);
    cout << "New discount of customer: " << c1->getName() << " discount: " << c1->getDiscountPercentage() << endl;

    cout << "How many customers have a name Pepa: " << organizer->findCustomersByName("Pepa").size() << endl;

    delete organizer;
    return 0;
}