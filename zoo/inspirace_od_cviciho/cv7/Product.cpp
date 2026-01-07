//
// Created by Michal Matonoha on 05.11.2025.
//

#include "Product.h"

Product::Product(string description, float weight) {
    setDescription(description);
    setWeight(weight);
}

string Product::getDescription() {
    return m_description;
}

float Product::getWeight() {
    return m_weight;
}

void Product::setDescription(string description) {
    if (!description.empty()) {
        m_description = description;
        return;
    }
    m_description = "No valid description provided";
}

void Product::setWeight(float weight) {
    if (weight >= 0) {
        m_weight = weight;
        return;
    }
    m_weight = 0.5;
}