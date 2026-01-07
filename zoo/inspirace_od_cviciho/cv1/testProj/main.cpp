#include <iostream>

/*

Dnes bude naším úkolem prvně namodelovat a následně naimplementovat třídu, jež bude reprezentovat auto. Každé auto má
svého výrobce, model, modelový rok a emisní standard. Každé auto bude mít metodu (printInfo) vypisující veškeré
informace o něm. Má také metody, které dovolují nastavit parametry třídy (setry). Má také metody (getry), které nám
parametry třídy umožňují vracet.

 */

class Car {
public:
    std::string m_model;
    std::string m_brand;
    int m_modelYear;
    int m_emissionStandard;

    void printInfo() {
        std::cout << "Car: \n"
        << m_brand << " " << m_model << "\n"
        << "Was made in: \n"
        << m_modelYear << "\n"
        << "EURO: " << m_emissionStandard << std::endl;
    }

    bool isInputValid(std::string input) {
        // kontrolujeme zda vstup neni prazdny
        return !input.empty();
    }

    bool isYearValid(int year) {
        // kontrolujeme zda rok vyroby dava smysl - auta se v 15. stoleti nedelala
        return 1886 <= year && year <= 2025;
    }

    void setModel(std::string model) {
        if (isInputValid(model)) {
            m_model = model;
            return;
        }
        std::cout << "Model name can not be empty." << std::endl;
    }

    void setBrand(std::string brand) {
        if (isInputValid(brand)) {
            m_brand = brand;
            return;
        }
        std::cout << "Brand name can not be empty." << std::endl;
    }

    void setModelYear(int year) {
        if (isYearValid(year)) {
            m_modelYear = year;
            return;
        }
        std::cout << "Model year have to be in correct range." << std::endl;
    }

    void setEmissionStandard(int standard) {
        // zde by mela take probihat nejaka kontrola
        m_emissionStandard = standard;
    }

    std::string getModel() {
        return m_model;
    }

    std::string getBrand() {
        return m_brand;
    }

    int getModelYear() {
        return m_modelYear;
    }

    int getEmissionStandard() {
        return m_emissionStandard;
    }

    int emissionTax() {
        if (m_modelYear > 2015) {
            return 0;
        }

        if (m_emissionStandard >= 3) {
            return 3000;
        }

        if (m_emissionStandard == 2) {
            return 5000;
        }

        if (m_emissionStandard <= 1) {
            return 10000;
        }
    }
};

int main() {
    Car* car = new Car();

    car->setBrand("");
    car->setBrand("Skoda");
    car->setModel("1203");
    car->setModelYear(1968);
    car->setEmissionStandard(0);

    car->printInfo();

    std::cout << "\n\nEmission tax for licence transfer is: " << car->emissionTax() << std::endl;

    delete car;
    return 0;
}