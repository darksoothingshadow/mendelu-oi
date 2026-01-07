//
// Created by Michal Matonoha on 05.11.2025.
//

#include "Container.h"

Container::Container(string position, float maxLoad) {
    m_position = position;
    setMaxLoad(maxLoad);
    m_products = {};
}

float Container::getProductsWeight() {
    float totalWeight = 0;

    for (Product* product : m_products) {
        totalWeight += product->getWeight();
    }

    return totalWeight;
}

void Container::storeProduct(Product *product) {
    if (product == nullptr) {
        return;
    }

    if (product->getWeight() + getProductsWeight() <= m_maxLoad) {
        m_products.push_back(product);
    }
}

void Container::removeProduct(string description) {
    for (int i = 0; i < m_products.size(); i++) {
        if (m_products.at(i)->getDescription() == description) {
            m_products.erase(m_products.begin() + i);
        }
    }
}

void Container::setMaxLoad(float maxLoad) {
    if (maxLoad >= 0) {
        m_maxLoad = maxLoad;
        return;
    }
    m_maxLoad = 100;
}

string Container::getProductsDescriptions() {
    string descriptions;

    for (Product* product : m_products) {
        descriptions += product->getDescription() + "; \n";
    }

    return descriptions;
}

string Container::getPosition() {
    return m_position;
}

void Container::setPosition(string position) {
    m_position = position;
}
