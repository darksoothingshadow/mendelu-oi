// Je dána definice uzlu binárního stromu:
// struct Uzel {
//   int hodnota;
//   Uzel *levy, *pravy;
// };
// Implementujte podprogram pocetLichychUzlu, který určí počet uzlů stromu, v nichž se nacházejí lichá čísla.

#include <iostream>

struct Uzel {
  int hodnota;
  Uzel *levy, *pravy;
};

int pocetLichychUzlu(Uzel* uzel) {
    if (uzel == nullptr) {
        return 0;
    }

    if (uzel->hodnota % 2 != 0) {
        return pocetLichychUzlu(uzel->levy) + pocetLichychUzlu(uzel->pravy) + 1;
    } else {
        return pocetLichychUzlu(uzel->levy) + pocetLichychUzlu(uzel->pravy);
    }
}