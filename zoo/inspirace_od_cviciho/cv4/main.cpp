#include <iostream>

using namespace std;

/*

Vytvořme dvě třídy - Úkol (Task) a Pracovník(Employee)

Každý úkol bude mít automaticky generovaný identifikátor, který bude představovat pořadové číslo úkolu. Toto číslo bude
sekvenční index, který se s každým úkolem inkrementuje o jedna. Každý úkol bude mít navíc hodinovou složitost (kolik
hodin trvá jeho dokončení) a název (title).

Při vytvoření úkolu se buď zadává pouze jméno a počet hodin. Nebo se zadá pouze jméno a délka se automaticky nastaví
na 1 hodinu. Id se generuje automaticky a všechny údaje chceme vracet.

Pracovník má evidováno jméno, velikost úvazku na intervalu <0, 1> (1 = plný úvazek, 0,5 = poloviční úvazek). Plný
úvazek má velikost 40 hodin týdně. Hodnoty jména a úvazku zadáváme v konstruktoru a jsme schopni je vracet. Počet
odpracovaných hodin je na počátku 0. Dále můžeme změnit velikost úvazku a zaevidovat úkol (nechceme, aby pracoval přesčas)
a vynulovat odpracované hodiny.

 */

class WorkLogger {
    static WorkLogger* s_instance;

    string m_eventLog;
    int m_activeTasks;
    WorkLogger() {
        m_activeTasks = 0;
        m_eventLog = "Log of tasks: \n";
    }

public:
    static WorkLogger* getInstance() {
        if (s_instance == nullptr) {
            s_instance = new WorkLogger();
        }
        return s_instance;
    }

    void logWork(string employeeName, int taskId) {
        m_eventLog += "Employee: " + employeeName + " was assigned task with id: " + to_string(taskId) + "\n";
    }

    void increaseActiveTasks() {
        m_activeTasks++;
    }

    void decreaseActiveTasks() {
        m_activeTasks--;
    }

    void printLog() {
        cout << "Active tasks: " << m_activeTasks << "\n"
        << m_eventLog << endl;
    }
};

WorkLogger* WorkLogger::s_instance = nullptr;

class Task {
    static int s_taskCounter;

    int m_id;
    float m_hoursToCompletion;
    string m_title;

    void setHoursToCompletion(float hoursToCompletion) {
        if (hoursToCompletion > 0) {
            m_hoursToCompletion = hoursToCompletion;
        } else {
            m_hoursToCompletion = 1;
            cout << "Hours to completion has to be higher than 0" << endl;
        }
    }

    void setTitle(string title) {
        if (!title.empty()) {
            m_title = title;
        } else {
            m_title = "No title";
            cout << "Title cannot be empty" << endl;
        }
    }

public:
    Task(string title, float hoursToCompletion) {
        m_id = s_taskCounter++; // taskCounter incremented after assign
        setHoursToCompletion(hoursToCompletion);
        setTitle(title);

        WorkLogger* logger = WorkLogger::getInstance();
        logger->increaseActiveTasks();
    }

    Task(string title) : Task(title, 1) {}

    ~Task() {
        WorkLogger* logger = WorkLogger::getInstance();
        logger->decreaseActiveTasks();
    }

    int getId() {
        return m_id;
    }

    float getHoursToCompletion() {
        return m_hoursToCompletion;
    }

    string getTitle() {
        return m_title;
    }
};

int Task::s_taskCounter = 0;

class Employee {
    string m_name;
    float m_contractSize;
    float m_workedHours;

    void setName(string name) {
        if (!name.empty()) {
            m_name = name;
        } else {
            m_name = "No name";
            cout << "Name cannot be empty" << endl;
        }
    }

public:
    Employee(string name, float contractSize) {
        m_workedHours = 0;
        setName(name);
        setContractSize(contractSize);
    }

    void setContractSize(float contractSize) {
        if (contractSize > 0 && contractSize <= 1) {
            m_contractSize = contractSize;
        } else {
            m_contractSize = 1;
            cout << "Contract size has to be between 0 and 1 (fulltime)" << endl;
        }
    }

    void assignTask(Task* task) {
        if (task->getHoursToCompletion() <= m_contractSize * 40 - m_workedHours) {
            m_workedHours += task->getHoursToCompletion();

            WorkLogger* logger = WorkLogger::getInstance();
            logger->logWork(m_name, task->getId());
        } else {
            cout << "Employee can not work overtime." << endl;
        }

    }

    string getName() {
        return m_name;
    }

    float getContractSize() {
        return m_contractSize;
    }

    void resetWorkedHours() {
        m_workedHours = 0;
    }

    void printInfo() {
        cout << "Employee Name: " << m_name << "\n"
        << "Works: " << m_contractSize * 40 << " hours a week." << "\n"
        << "Has already worked: " << m_workedHours << endl;
    }
};

int main() {
    Task* fullTimeTask = new Task("Part time activity");
    Task* partTimeTask = new Task("Full time activity", 40);

    Employee* pepa = new Employee("Pepa", 0.5);

    pepa->assignTask(fullTimeTask);
    pepa->assignTask(partTimeTask);
    pepa->printInfo();

    WorkLogger* logger = WorkLogger::getInstance();
    logger->printLog();

    delete fullTimeTask;
    logger->printLog();
    return 0;
}