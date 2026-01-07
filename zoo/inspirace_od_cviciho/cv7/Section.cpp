//
// Created by Michal Matonoha on 10.11.2025.
//

#include "Section.h"

Section::Section(string position) {
    m_containers = {};
    m_position = position;
}

Section::~Section() {
    int index = 0;
    for (Container* container : m_containers) {
        m_containers.erase(m_containers.begin() + index);
        delete container;
        index++;
    }
}

bool Section::isPositionFree(string position) {
    for (Container* container : m_containers) {
        if (container->getPosition() == position) {
            return false;
        }
    }
    return true;
}


void Section::createContainer(string position, float maxCapacity) {
    if (!isPositionFree(position)) {
        return;
    }

    Container* container = new Container(position, maxCapacity);
    m_containers.push_back(container);
}

void Section::createContainer(string position) {
    // staci nam zavolat ta metoda, jez prijima i tu kapacitu
    createContainer(position, 500);
}

void Section::removeContainer(string position) {
    for (int i = 0; i < m_containers.size(); i++) {
        if (m_containers.at(i)->getPosition() == position) {
            m_containers.erase(m_containers.begin() + i);
            // nema smysl nechat dobihat smycku, pozice je unikatni
            return;
        }
    }
}

Container* Section::getContainerAtPosition(string position) {
    for (Container* container : m_containers) {
        if (container->getPosition() == position) {
            return container;
        }
    }
    return nullptr;
}

void Section::addProductToContainer(string containerPosition, Product *product) {
    if (product == nullptr) {
        return;
    }

    Container* container = getContainerAtPosition(containerPosition);
    if (container != nullptr) {
        container->storeProduct(product);
    }
}

void Section::removeProductsFromContainer(string containerPosition, string productDescription) {
    Container* container = getContainerAtPosition(containerPosition);
    if (container != nullptr) {
        container->removeProduct(productDescription);
    }
}

void Section::printStats() {
    cout << "Section is located at: " << m_position << endl;

    for (Container* container : m_containers) {
        cout << "Absolute location of container: " << m_position + container->getPosition() << "\n"
        << "Has these products: \n" << container->getProductsDescriptions() << "\n"
        << "With total weight of: " << container->getProductsWeight() << "\n" << endl;
    }
}






