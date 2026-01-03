#include <iostream>

int main() {
    int incDaysTem = 0;
    float mor, day, eve;
    float currentAvg, prevAvg = -1000;
    float max1 = -1000, max2 = -1000, max3 = -1000;

    // while loop over entry data
    while (std::cin >> mor >> day >> eve) {
        currentAvg = (mor + day + eve) / 3.0;
        
        // find max values
        if (currentAvg > max1) {
            max3 = max2;
            max2 = max1;
            max1 = currentAvg;
        } else if (currentAvg > max2) {
            max3 = max2;
            max2 = currentAvg;
        } else if (currentAvg > max3) {
            max3 = currentAvg;
        }
        
        if ((currentAvg > prevAvg) and prevAvg != -1000) {
            incDaysTem++;
        }
        prevAvg = currentAvg;
    }

    // loop over the vector, storing highest values into max variables
    std::cout << "Number of days with increased counter: " << incDaysTem << "\n";

    // case: only 1, 2 or 3 days entered
    if (max1 > -1000) {
        std::cout << "Days with the highest recorded temperature: " << "\n";
        std::cout << max1 << "\n";
    }

    if (max2 > -1000) {
        std::cout << max2 << "\n";
    }

    if (max3 > -1000) {
        std::cout << max3 << "\n";
    }


    // if (max1 == -1000) {
    //     std::cout << "No temperatures recorded." << "\n";
    // } else if (max2 == -1000) {
    //     std::cout << "Days with the highest recorded temperature: " << max1 << "\n";
    // } else if (max3 == -1000) {
    //     std::cout << "Days with the highest recorded temperature: " << max1 << ", " << max2 << "\n";
    // } else {
    //     std::cout << "Days with the highest recorded temperature: " << max1 << ", " << max2 << ", " << max3 << "\n";
    // }

    return 0;
}