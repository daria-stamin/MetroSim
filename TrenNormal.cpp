//
// Created by daria on 4/15/2026.
//

#include "TrenNormal.h"
#include <iostream>

TrenNormal::TrenNormal() {
    this->capacitate = 20;
    this->viteza = 70;
    this->pret = 3000;
}

TrenNormal::TrenNormal(int capacitate, float viteza, int pret) : Tren(capacitate, viteza, pret) {}

TrenNormal::TrenNormal(const TrenNormal& obj) : Tren(obj) {}

TrenNormal& TrenNormal::operator=(const TrenNormal& obj) {
    if (this != &obj) {
        Tren::operator=(obj);
    }
    return *this;
}

TrenNormal::~TrenNormal() {}

float TrenNormal::calculeazaEficienta() const {
    return viteza * 0.75;
}

void TrenNormal::afisare() const {
    std::cout << "Tren Normal; ";
   // std::cout << *this;
}

std::istream& operator>>(std::istream& in, TrenNormal& obj) {
    in >> static_cast<Tren&>(obj);
    return in;
}

std::ostream& operator<<(std::ostream& out, const TrenNormal& obj) {
    out << "Tren Normal:\n";
    out << static_cast<const Tren&>(obj);
    return out;
}