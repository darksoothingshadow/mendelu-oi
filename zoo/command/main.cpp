#include <iostream>//command - chceme tridu naucit nove funkce, potomci BEZ atributu

#include "Calculator.h"
//nema smysl, aby matematicke operace exislovali bez kalkulacky, po cely beh programu budou operace zustavat uvnitr kalkulacky

int main() {
    Calculator* calculator = new Calculator();
    calculator->run();

    delete calculator;
    return 0;
}