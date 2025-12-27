#include <iostream>

int main() {
    typedef bool t_matice_pravdy[50][50];
    unsigned int matrixOrder;
    bool symetrical = true;

    // read user's input
    std::cin >> matrixOrder;
    t_matice_pravdy matrix;

    // enter user's parameter
    for (int i = 0; i < matrixOrder; i ++) {
        for (int j = 0; j < matrixOrder; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // check for symetry
    for (int i = 0; i < matrixOrder and symetrical; i ++) {
        for (int j = (i + 1); j < matrixOrder and symetrical; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symetrical = false;
            }
        }
    }

    symetrical ? std::cout << "The matrice is symetrical." << "\n" : std::cout << "The matrice is not symmetrical.";

    return 0;
}