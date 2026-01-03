// Je dán datový typ relace podle následující definice:
// typedef bool t_matice_pravdy[50][50];
// Vytvořte podprogram, který na základě předaných parametrů
// (čtvercová matice typu t_matice_pravdy a řád matice
// jako celé nezáporné číslo) zjistí, zda relace specifikovaná předanou
// maticí je asymetrická.

#include <iostream>

typedef bool t_matice_pravdy[50][50];

int checkAsymetry(t_matice_pravdy matice, int rad) {
    bool asymmetry = true;

    for (int i = 0; i < rad and asymmetry != false; i++) {
        for (int j = i; j < rad and asymmetry != false; j++)
            if ((i == j) and (matice[i][j] == true)) {
                asymmetry = false;
            } else if (matice[i][j] and matice[j][i]) {
                asymmetry = false;
            }
    }

    std::cout << "asymmetry: " << asymmetry << "\n";

    return asymmetry;
}