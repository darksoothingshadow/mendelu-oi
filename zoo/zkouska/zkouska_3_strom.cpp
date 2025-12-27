#include <iostream>

struct Uzel {
    int hodnota;
    Uzel *levy, *pravy;
};

// recursion-based search
int pocetSudychUzlu(Uzel *uzel) {
    if (uzel == nullptr) {
        return 0;
    }

    bool sudy = (uzel->hodnota % 2 == 0);

    if (sudy) {
        return pocetSudychUzlu(uzel->levy) + pocetSudychUzlu(uzel->pravy) + 1; 
    } else {
        return pocetSudychUzlu(uzel->levy) + pocetSudychUzlu(uzel->pravy); 
    }
}

int main() {
    // std::cout << "Pocet sudych uzlu: " << pocetSudychUzlu(...) << "\n";

    return 0;
}