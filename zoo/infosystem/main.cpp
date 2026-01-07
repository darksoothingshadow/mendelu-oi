#include <iostream>
#include <vector>
#include "Zkouska.h"
#include "Ucitel.h"
#include "VysledekStudenta.h"

using namespace std;

/*
Mějme informační systém školy spravující zkoušky z předmětů.

(2b) Každá Zkouška má povinně datum (uloženo jako string) a jméno zkoušky.
(2b) Dále existuje třída Učitel. Každý učitel má jméno vynuceně konstruktorem a volitelně může mít 
     uvedený ústav, na kterém učí.
(2b) Dále máme Výsledek studenta. Výsledek studenta obsahuje povinně jméno studenta, známku z dané 
     zkoušky (1 až 5) a ukazatel na učitele, který známku zadal.
(1b) Každá Zkouška obsahuje seznam těchto Výsledků studenta - tzn. výsledky všech studentů, 
     kteří danou zkoušku absolvovali.
(2b) Výsledky se do zkoušky přidávají pomocí metody, která obdrží vektor ukazatelů na výsledky 
     studentů - tzn. je možné zadat více výsledků najednou.
(3b) Vytvořte metodu, která u zkoušky vyhledá všechny záznamy, které zadal učitel s konkrétním 
     jménem. Tyto výsledky vypíše na obrazovku.
(3b) Dále u zkoušky udělejte metodu, která spočítá a vrátí průměrnou známku z dané zkoušky.
(2b) Poslední metoda u zkoušky vrátí seznam všech známek zadaných učiteli z určitého ústavu. 
     Vektor bude obsahovat například [1, 3, 5, 1, 2...].
(2b) V hlavní funkci programu vytvořte zkoušku, alespoň dva učitele a pořiďte cca 6 záznamů 
     o zkoušení studentů, které na dvakrát uložte k vytvořené zkoušce.
(2b) Dále vypište průměrnou známku zkoušky a záznamy zadané jedním z učitelů.

Hodnocení: 25 bodů (4 za model, 21 za implementaci).
*/

int main() {
    // Create teachers (2 required)
    Ucitel* novak = new Ucitel("Jan Novak", "Informatika");
    Ucitel* svoboda = new Ucitel("Marie Svobodova", "Informatika");
    Ucitel* horak = new Ucitel("Petr Horak", "Matematika");

    // Create exam
    Zkouska* zkouska = new Zkouska("15.01.2026", "Programovani v C++");

    // Create student results (6 required)
    VysledekStudenta* result1 = new VysledekStudenta("Adam Marek", 1, novak);
    VysledekStudenta* result2 = new VysledekStudenta("Eva Kralova", 2, novak);
    VysledekStudenta* result3 = new VysledekStudenta("Tomas Prochazka", 3, svoboda);
    VysledekStudenta* result4 = new VysledekStudenta("Lucie Vesela", 1, svoboda);
    VysledekStudenta* result5 = new VysledekStudenta("Martin Dvorak", 4, horak);
    VysledekStudenta* result6 = new VysledekStudenta("Petra Novotna", 2, novak);

    // Add results in two batches (2b requirement)
    vector<VysledekStudenta*> batch1 = {result1, result2, result3};
    vector<VysledekStudenta*> batch2 = {result4, result5, result6};

    zkouska->addResults(batch1);
    zkouska->addResults(batch2);

    // Print exam info
    cout << "=== EXAM INFO ===" << endl;
    zkouska->printInfo();

    // Print average grade (3b)
    cout << "\n=== AVERAGE GRADE ===" << endl;
    cout << "Average: " << zkouska->getAverageGrade() << endl;

    // Print results by specific teacher (3b)
    cout << "\n=== RESULTS BY TEACHER ===" << endl;
    zkouska->printResultsByTeacher("Jan Novak");

    // Get grades by department (2b)
    cout << "\n=== GRADES BY DEPARTMENT ===" << endl;
    vector<int> informaticsGrades = zkouska->getGradesByDepartment("Informatika");
    cout << "Grades from Informatika department: [";
    for (int i = 0; i < informaticsGrades.size(); i++) {
        cout << informaticsGrades.at(i);
        if (i < informaticsGrades.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Clean up
    delete result1;
    delete result2;
    delete result3;
    delete result4;
    delete result5;
    delete result6;
    delete novak;
    delete svoboda;
    delete horak;
    delete zkouska;

    return 0;
}
