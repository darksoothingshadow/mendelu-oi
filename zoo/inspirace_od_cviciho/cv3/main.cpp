#include <iostream>

/*

Budeme programovat třídu, která bude reprezentovat bankovní účet. Každý účet má jméno vlastníka, zůstatek, limit pro výběr
a informaci o tom, zda je transparentní. Každý nově vytvořený účet je vždy netransparentní. Při vytvoření účtu je nutné
zadat jméno vlastníka a limit pro výběr. Při výpisu účtu se u transparentních účtů zobrazují i limity a zůstatek,
u netransparetních jen jméno. Transparentnost lze zapnout, ale nelze ji poté vypnout.

Každá operace musí být zapsána do logu. Úspěšné akce: „Událost <popis události>“, zatímco chyby: „Chyba: <popis chyby>“.
Chyby se zároveň vypíší i na obrazovku. Na konci musí být možné log vypsat.

Operace:
Vklad hotovosti (nelze vložit zápornou částku).
Výběr hotovosti (kontrola limitu i zůstatku).
Změna limitu (nesmí být záporný).
Změna majitele účtu.
Přepnutí účtu na transparentní (zpět to nejde).
Výpis údajů o účtu (zohlednit transparentnost).
Vypsání logu.

 */

class BankAccount {
    std::string m_ownerName;
    float m_balance;
    float m_atmLimit;
    bool m_isTransparent;
    std::string m_eventLog;

public:
    BankAccount(std::string ownerName, float atmLimit) {
        m_balance = 500;
        m_isTransparent = false;
        m_eventLog = "";
        setOwnerName(ownerName);
        setAtmLimit(atmLimit);
    }

    void setAtmLimit(float newLimit) {
        if (newLimit < 0) {
            logError("Limit can not be lower than 0; you tried: " + std::to_string(newLimit));
        } else {
            m_atmLimit = newLimit;
            logSuccesfulEvent("Limit was set to: " + std::to_string(m_atmLimit));
        }
    }

    void setOwnerName(std::string ownerName) {
        if (!ownerName.empty()) {
            m_ownerName = ownerName;
            logSuccesfulEvent("Owner name was set to: " + m_ownerName);
        } else {
            logError("Owner name can't be empty;");
        }
    }

    float getBalance() {
        logSuccesfulEvent("Balance value was gotten by external entity;");
        return m_balance;
    }

    std::string getOwnerName() {
        logSuccesfulEvent("Owner name was gotten by external entity;");
        return m_ownerName;
    }

    void printInfo() {
        if (m_isTransparent) {
            std::cout << "Account owner: " << m_ownerName << "\n"
            << "Account limit: " << m_atmLimit << "\n"
            << "Account balance: " << m_balance << "\n" << std::endl;
        } else {
            std::cout << "Account owner: " << m_ownerName << "\n"
            << "Account is not transparent.\n" << std::endl;
        }
    }

    void printLog() {
        std::cout << m_eventLog << std::endl;
    }

    void makeAccountTransparent() {
        if (m_isTransparent) {
            logError("Account is already transparent;");
        } else {
            m_isTransparent = true;
            logSuccesfulEvent("Account was set to transparent;");
        }
    }

    void depositMoney(float amount) {
        if (amount < 0) {
            logError("Amount for deposit can't be lower than zero;");
        } else {
            m_balance += amount;
            logSuccesfulEvent(std::to_string(amount) + " was deposited; New balance: " + std::to_string(m_balance) + ";");
        }
    }

    void withdrawMoney(float amount) {
        if (amount <= m_atmLimit && amount <= m_balance && amount > 0) {
            m_balance -= amount;
            logSuccesfulEvent(std::to_string(amount) + " was taken from the account; New balance: " + std::to_string(m_balance) + ";");
        } else {
            logError(std::to_string(amount) + " can not be taken from the account");
        }
    }

private:
    void logSuccesfulEvent(std::string event) {
        m_eventLog += "SUCC_EVENT: " + event + "\n";
    }

    void logError(std::string error) {
        std::cerr << "Error happened: " << error << std::endl;
        m_eventLog += "ERROR: " + error + "\n";
    }
};

int main() {
    BankAccount* pepaAccount = new BankAccount("Pepa Mrazek", 500.00);

    pepaAccount->printInfo();

    pepaAccount->depositMoney(10000);
    pepaAccount->withdrawMoney(100);
    
    pepaAccount->makeAccountTransparent();
    pepaAccount->printInfo();
    pepaAccount->printLog();

    std::cout << "=============== TESTING ERRORS =====================" << std::endl;

    pepaAccount->depositMoney(-1);
    pepaAccount->withdrawMoney(-1);

    pepaAccount->withdrawMoney(600);

    pepaAccount->printLog();

    delete pepaAccount;
    return 0;
}