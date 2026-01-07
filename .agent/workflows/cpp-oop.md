---
description: Create C++ programs following MENDELU OOP university design principles
---

# MENDELU C++ OOP Workflow

Follow these principles when creating C++ programs for university exercises.

## 1. Project Structure

Each class should have:
- `ClassName.h` - header file with declarations
- `ClassName.cpp` - implementation file
- `main.cpp` - entry point with usage examples
- `CMakeLists.txt` - build configuration

## 2. Header File Template (.h)

```cpp
//
// Created by [author] on [date].
//

#ifndef PROJECTNAME_CLASSNAME_H
#define PROJECTNAME_CLASSNAME_H

#include <iostream>
#include <vector>
using namespace std;

class ClassName {
    // Private attributes with m_ prefix
    string m_name;
    float m_value;
    vector<OtherClass*> m_items;

    // Private setters for validation
    void setName(string name);
    void setValue(float value);

public:
    // Constructor with required parameters
    ClassName(string name, float value);
    
    // Destructor if managing pointers
    ~ClassName();
    
    // Public getters
    string getName();
    float getValue();
    
    // Public methods
    void addItem(OtherClass* item);
    void removeItem(string identifier);
    void printInfo();
};

#endif //PROJECTNAME_CLASSNAME_H
```

## 3. Implementation File Template (.cpp)

```cpp
//
// Created by [author] on [date].
//

#include "ClassName.h"

// Constructor - use setters for validation
ClassName::ClassName(string name, float value) {
    setName(name);
    setValue(value);
    m_items = {};
}

// Destructor - clean up owned pointers
ClassName::~ClassName() {
    for (OtherClass* item : m_items) {
        delete item;
    }
}

// Private setter with validation
void ClassName::setName(string name) {
    if (!name.empty()) {
        m_name = name;
        return;
    }
    m_name = "Default name";
}

void ClassName::setValue(float value) {
    if (value >= 0) {
        m_value = value;
        return;
    }
    m_value = 0;
}

// Getters
string ClassName::getName() {
    return m_name;
}

float ClassName::getValue() {
    return m_value;
}

// Methods working with collections
void ClassName::addItem(OtherClass* item) {
    if (item == nullptr) {
        return;
    }
    m_items.push_back(item);
}

void ClassName::removeItem(string identifier) {
    for (int i = 0; i < m_items.size(); i++) {
        if (m_items.at(i)->getIdentifier() == identifier) {
            m_items.erase(m_items.begin() + i);
            return; // position is unique
        }
    }
}

void ClassName::printInfo() {
    cout << "Name: " << m_name << endl;
    cout << "Value: " << m_value << endl;
    for (OtherClass* item : m_items) {
        cout << item->getInfo() << endl;
    }
}
```

## 4. Key Design Principles

### Naming Conventions
| Element | Convention | Example |
|---------|------------|---------|
| Private attributes | `m_` prefix | `m_name`, `m_products` |
| Classes | PascalCase | `Product`, `Container` |
| Methods | camelCase | `addProduct()`, `getName()` |
| Parameters | camelCase | `string productName` |

### Validation Pattern
- Private setters validate input
- Constructor calls setters (not direct assignment)
- Default values for invalid input

```cpp
void Product::setWeight(float weight) {
    if (weight >= 0) {
        m_weight = weight;
        return;
    }
    m_weight = 0.5; // default fallback
}
```

### Pointer Management
- Use `nullptr` checks before operations
- Owner class is responsible for `delete`
- Initialize vectors as empty `m_items = {}`

```cpp
void Container::storeProduct(Product* product) {
    if (product == nullptr) {
        return;
    }
    m_products.push_back(product);
}
```

### Helper Methods
- Private helper methods for common operations
- Return early pattern for cleaner code

```cpp
private:
    bool isPositionFree(string position);
    Container* getContainerAtPosition(string position);
```

## 5. Abstract Classes (Design Patterns)

```cpp
class AbstractClass {
public:
    AbstractClass() = default;
    virtual void abstractMethod() = 0;  // Pure virtual
    virtual ~AbstractClass() = default; // Virtual destructor
};

class ConcreteClass : public AbstractClass {
public:
    ConcreteClass();
    void abstractMethod() override;
    ~ConcreteClass() override = default;
};
```

## 6. main.cpp Template

```cpp
#include <iostream>
#include "ClassName.h"

using namespace std;

/*
[Copy exercise description here as comment]
*/

int main() {
    // Create objects with new
    Product* apple = new Product("Apple", 0.5);
    Container* box = new Container("A1", 100);
    
    // Demonstrate functionality
    box->storeProduct(apple);
    box->printInfo();
    
    // Clean up
    delete apple;
    delete box;
    
    return 0;
}
```

## 7. CMakeLists.txt Template

```cmake
cmake_minimum_required(VERSION 3.29)
project(ProjectName)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjectName
    main.cpp
    ClassName.cpp
    OtherClass.cpp
)
```

## 8. Common Patterns

### Aggregation (has-a, doesn't own)
```cpp
class Section {
    vector<Container*> m_containers;  // stores pointers from outside
public:
    void addContainer(Container* container);  // receives pointer
};
```

### Composition (has-a, owns and creates)
```cpp
class Section {
    vector<Container*> m_containers;
public:
    void createContainer(string position) {
        Container* c = new Container(position);  // creates inside
        m_containers.push_back(c);
    }
    ~Section() {
        for (auto c : m_containers) delete c;  // responsible for deletion
    }
};
```

### Method Overloading
```cpp
void createContainer(string position);           // default capacity
void createContainer(string position, float capacity);  // custom capacity
```
