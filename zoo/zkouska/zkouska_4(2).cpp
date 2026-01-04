// Na vstupu se nacházejí trojice desetinných čísel,
// každá trojice představuje teploty jednoho dne měřené ráno,
// v poledne a večer. Počet takto zadaných dní není dopředu znám.
// Zjistěte, v kolika dnech byla průměrná denní teplota vyšší než v předcházejícím dni
// a vypište tři nejteplejší dny celého období (srovnávají se denní průměry teplot).

#include <iostream>

int main() {

    float prevTemp = -1000;
    float currTemp;
    int incCount = 0;

    float num1, num2, num3;
    float max1 = -1000, max2 = -1000, max3 = -1000;

    // iterate each date to find out 
    while (std::cin >> num1 >> num2 >> num3) {
        currTemp = (num1 + num2 + num3) / 3.0;

        if (currTemp > prevTemp and prevTemp != -1000) {
            incCount++;
        }

        if (max1 < currTemp) {
            max3 = max2;
            max2 = max1;
            max1 = currTemp;
        } else if (max2 < currTemp) {
            max3 = max2;
            max2 = currTemp;
        } else if (max3 < currTemp) {
            max3 = currTemp;
        }

        prevTemp = currTemp;
    }

    std::cout << "Number of days with increased temperature: " << incCount << "\n";
    std::cout << "Days with maximum daily temperature: " << "\n";
    
    if (max1 > -1000) {
        std::cout << max1 << " ";
    }

    if (max2 > -1000) {
        std::cout << max2 << " ";
    }

    if (max3 > -1000) {
        std::cout << max3 << "\n";
    }
    
    return 0;
}