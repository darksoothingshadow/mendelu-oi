#include <iostream>
#include <fstream>

// Napište program, který v textovém souboru, jehož diskové jméno je zadáno jako parametr z příkazového řádku,
// spočítá procentuální podíl počtu písmen anglické abecedy (velkých i malých dohromady) k počtu všech znaků (i bílých).
// Pokud parametr není v příkazovém řádku zadán nebo není zadán správně, program jen vypíše odpovídající chybové hlášení
// A nastavte návratovou hodntu programu na -1.

int main(int argc, char* argv[]) {
    // zkontroluj podminku
    if (argc < 2) {
        std::cout << "not enough parameters" << "\n";
        return -1;
    }

    std::ifstream file(argv[1]);
    
    if (!file.is_open()) {
        std::cout << "file could not be opened" << "\n";
        return -1;
    }

    float charCount = 0;
    float letterCount = 0;
    char ch;

    while (file.get(ch)) {
        if ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z')) {
            letterCount++;
        }

        charCount++;
    }

    float procentualniPodil = (letterCount / charCount) * 100.0;

    std::cout << "Percentage share of of letters to number is: " << procentualniPodil << "\n";

    file.close();
    return 0;
}