# 📚 Shrnutí - Návrhové vzory a konvence v C++

---

## 🎯 1. Command Pattern (Příkazový vzor)

**Umístění:** `zoo/command/`

**Účel:** Zapouzdřit operace jako objekty, umožnit dynamické přidávání nových funkcí.

> *"Chceme třídu naučit nové funkce, potomci BEZ atributů"*

### Struktura:
```
Operation (abstraktní)     ←── Adding (konkrétní)
       ↑                   ←── Multiplying (konkrétní)
       │
Calculator (obsahuje vector<Operation*>)
```

### Příklad implementace:

#### Abstraktní třída (rozhraní) - `Operation.h`:
```cpp
class Operation {
    std::string m_description;  // jediný atribut - popis operace
public:
    Operation(std::string description);
    std::string getDescription();
    virtual float calculate(float number1, float number2) = 0;  // čistě virtuální
};
```

#### Konkrétní příkaz - `Adding.h`:
```cpp
class Adding : public Operation {
public:
    Adding();  // bez vlastních atributů!
    float calculate(float number1, float number2);  // implementace
};
```

#### Invoker (volající) - `Calculator.h`:
```cpp
class Calculator {
    float m_number1;
    float m_number2;
    std::vector<Operation*> m_operations;    // pole všech operací
    Operation* m_chosenOperation;            // vybraná operace

public:
    Calculator();
    ~Calculator();  // destruktor pro uvolnění paměti
    void run();

private:
    void readNumbers();
    void printAvailableOperations();
    void chooseOperation();
    void callOperations();
};
```

#### Použití v `main.cpp`:
```cpp
int main() {
    Calculator* calculator = new Calculator();
    calculator->run();
    delete calculator;
    return 0;
}
```

---

## 🔄 2. State Pattern (Stavový vzor)

**Umístění:** `zoo/state/`

**Účel:** Umožnit objektu měnit své chování podle vnitřního stavu.

### Struktura:
```
WorkPosition (abstraktní)  ←── Developer (stav 1)
       ↑                   ←── Manager (stav 2)
       │
Employee (obsahuje WorkPosition* - aktuální stav)
```

### Příklad implementace:

#### Abstraktní stav - `WorkPosition.h`:
```cpp
class WorkPosition {
public:
    virtual void printInfo() = 0;           // čistě virtuální metoda
    virtual ~WorkPosition() = default;      // virtuální destruktor!
};
```

#### Konkrétní stavy - `Developer.h` a `Manager.h`:
```cpp
class Developer : public WorkPosition {
    std::vector<std::string> m_languages;  // vlastní atributy stavu
public:
    Developer(std::vector<std::string> languages);
    void printInfo() override;
    ~Developer() override = default;
};

class Manager : public WorkPosition {
    std::string m_specialization;
public:
    Manager(std::string specialization);
    void printInfo() override;
    ~Manager() override = default;
};
```

#### Context (kontext) - `Employee.h`:
```cpp
class Employee {
    std::string m_name;
    int m_birthYear;
    WorkPosition* m_workPosition;  // ukazatel na aktuální stav

    void setName(std::string name);
    void setBirthYear(int birthYear);

public:
    Employee(std::string name, int birthYear, std::vector<std::string> languages);
    
    // Metody pro změnu stavu
    void changeToManager(std::string specialization);
    void changeToDeveloper(std::vector<std::string> languages);
    
    void printInfo();
};
```

#### Implementace změny stavu - `Employee.cpp`:
```cpp
void Employee::changeToManager(std::string specialization) {
    if (specialization.empty()) {
        specialization = "communication";
    }
    delete m_workPosition;                      // smazat starý stav
    m_workPosition = new Manager(specialization); // vytvořit nový
}

void Employee::changeToDeveloper(std::vector<std::string> languages) {
    if (languages.empty()) {
        languages.push_back("C++");
    }
    delete m_workPosition;
    m_workPosition = new Developer(languages);
}
```

---

## 🏫 3. Infosystém (Zkouškový systém)

**Umístění:** `zoo/infosystem/`

**Účel:** Klasická doménová aplikace s více propojenými třídami.

### Struktura vztahů:
```
Ucitel ←────────── VysledekStudenta ──────────→ Zkouska
  (1)                  (N)                         (1)
                       ↓
              Zkouska obsahuje vector<VysledekStudenta*>
```

### Příklad implementace:

#### Jednoduchá třída s volitelným atributem - `Ucitel.h`:
```cpp
class Ucitel {
    string m_name;
    string m_department;  // volitelný atribut

    void setName(string name);  // privátní setter pro validaci

public:
    Ucitel(string name);                      // konstruktor bez ústavu
    Ucitel(string name, string department);   // konstruktor s ústavem

    string getName();
    string getDepartment();
    void setDepartment(string department);    // veřejný setter
};
```

#### Třída s ukazatelem na jinou třídu - `VysledekStudenta.h`:
```cpp
class VysledekStudenta {
    string m_studentName;
    int m_grade;
    Ucitel* m_teacher;  // ukazatel na učitele (asociace)

    void setStudentName(string studentName);
    void setGrade(int grade);

public:
    VysledekStudenta(string studentName, int grade, Ucitel* teacher);

    string getStudentName();
    int getGrade();
    Ucitel* getTeacher();
    void printInfo();
};
```

#### Třída s kolekcí ukazatelů - `Zkouska.h`:
```cpp
class Zkouska {
    string m_date;
    string m_name;
    vector<VysledekStudenta*> m_results;  // kolekce výsledků

    void setDate(string date);
    void setName(string name);

public:
    Zkouska(string date, string name);

    // Přidání více výsledků najednou
    void addResults(vector<VysledekStudenta*> results);

    // Vyhledávání podle kritéria
    void printResultsByTeacher(string teacherName);

    // Výpočet průměru
    float getAverageGrade();

    // Filtrování a vrácení kolekce
    vector<int> getGradesByDepartment(string department);

    void printInfo();
};
```

#### Implementace klíčových metod - `Zkouska.cpp`:
```cpp
// Přidání více prvků do kolekce
void Zkouska::addResults(vector<VysledekStudenta*> results) {
    for (VysledekStudenta* result : results) {
        if (result != nullptr) {
            m_results.push_back(result);
        }
    }
}

// Vyhledávání s podmínkou
void Zkouska::printResultsByTeacher(string teacherName) {
    for (VysledekStudenta* result : m_results) {
        if (result->getTeacher() != nullptr && 
            result->getTeacher()->getName() == teacherName) {
            result->printInfo();
        }
    }
}

// Výpočet průměru
float Zkouska::getAverageGrade() {
    if (m_results.empty()) return 0;
    
    float sum = 0;
    for (VysledekStudenta* result : m_results) {
        sum += result->getGrade();
    }
    return sum / m_results.size();
}

// Filtrování a vrácení kolekce
vector<int> Zkouska::getGradesByDepartment(string department) {
    vector<int> grades = {};

    for (VysledekStudenta* result : m_results) {
        if (result->getTeacher() != nullptr &&
            result->getTeacher()->getDepartment() == department) {
            grades.push_back(result->getGrade());
        }
    }
    return grades;
}
```

---

## 📋 Univerzitní konvence - shrnutí

| Prvek | Konvence | Příklad |
|-------|----------|---------|
| Členské proměnné | `m_` prefix | `m_name`, `m_results` |
| Settery | Privátní s validací | `void setGrade(int grade);` |
| Gettery | Veřejné, jednoduchý return | `string getName();` |
| Destruktor | Virtuální v bázové třídě | `virtual ~Base() = default;` |
| Přepsání metody | Klíčové slovo `override` | `void printInfo() override;` |
| Čistě virtuální | `= 0` | `virtual void draw() = 0;` |
| Include guard | `#ifndef CLASS_H` | Na začátku každého `.h` |

---

## 🔧 Validace v setterech

Privátní settery slouží k validaci vstupů s uživatelskou zpětnou vazbou:

```cpp
void Employee::setBirthYear(int birthYear) {
    if (birthYear < 1905) {
        std::cout << "Nastavuji na 1905.\n";
        m_birthYear = 1905;
    } else if (birthYear > 2007) {
        std::cout << "Zaměstnanec nemůže být mladší 18 let. Nastavuji na 2007.\n";
        m_birthYear = 2007;
    } else {
        m_birthYear = birthYear;
    }
}

void Employee::setName(std::string name) {
    if (!name.empty()) {
        m_name = name;
    } else {
        std::cout << "Jméno nemůže být prázdné. Nastavuji na 'John'." << std::endl;
        m_name = "John";
    }
}
```

---

## 📁 Struktura souborů

Každý projekt obsahuje:
- `CMakeLists.txt` - konfigurační soubor pro build
- `main.cpp` - hlavní funkce programu
- `Trida.h` - hlavičkový soubor pro každou třídu
- `Trida.cpp` - implementační soubor pro každou třídu

### Šablona hlavičkového souboru:
```cpp
//
// Created by Autor on DD.MM.YYYY.
//

#ifndef NAZEV_TRIDY_H
#define NAZEV_TRIDY_H

#include <iostream>
#include <vector>
using namespace std;

class NazevTridy {
    // 1. Privátní členské proměnné
    Type m_attribute;
    
    // 2. Privátní settery pro validaci
    void setAttribute(Type value);

public:
    // 3. Konstruktor(y)
    NazevTridy(Type param);
    
    // 4. Destruktor (pokud potřeba)
    ~NazevTridy();
    
    // 5. Veřejné gettery
    Type getAttribute();
    
    // 6. Veřejné metody
    void doSomething();
};

#endif //NAZEV_TRIDY_H
```

---

## 🧠 Paměťový management

- Ruční správa paměti pomocí `new`/`delete`
- Destruktory uvolňují vlastněné ukazatele:

```cpp
Calculator::~Calculator() {
    for (auto operation : m_operations) {
        delete operation;
    }
}
```

- **Virtuální destruktory** v bázových třídách:

```cpp
virtual ~WorkPosition() = default;
```

---

## 📝 Typické zadání zkoušky

Úlohy mají předvídatelnou strukturu:

1. **Bodové hodnocení v komentářích** - např. `(2b)`, `(3b)`
2. **Požadované třídy**: Obvykle 2-4 třídy s vazbami
3. **Vztahy mezi třídami**: 
   - Agregace přes `vector<Class*>` (vlastní kolekci)
   - Asociace přes `Class*` ukazatele (reference)
4. **Požadované metody**:
   - Hromadné přidání: `addResults(vector<T*>)`
   - Vyhledávání/filtrování: `printResultsByTeacher(string)`
   - Výpočet: `getAverageGrade()`
   - Filtr podle kritéria: `getGradesByDepartment(string)`
5. **Funkce main**: Demonstruje všechny požadavky s testovacími daty
