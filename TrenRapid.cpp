
#include "TrenRapid.h"
#include <iostream>

TrenRapid::TrenRapid() {
    this->capacitate = 15;
    this->viteza = 70;
    this->pret = 5000;
}

TrenRapid::TrenRapid(int capacitate, float viteza, int pret) : Tren(capacitate, viteza, pret) {}

TrenRapid::TrenRapid(const TrenRapid& obj) : Tren(obj) {}

TrenRapid& TrenRapid::operator=(const TrenRapid& obj) {
    if (this != &obj) {
        Tren::operator=(obj);
    }
    return *this;
}

TrenRapid::~TrenRapid() {}

float TrenRapid::calculeazaEficienta() const {
    return viteza * 1.5;
}

void TrenRapid::afisare() const {
    std::cout << "Tren Rapid; ";
    //std::cout << *this;
}

std::istream& operator>>(std::istream& in, TrenRapid& obj) {
    in >> static_cast<Tren&>(obj);
    return in;
}

std::ostream& operator<<(std::ostream& out, const TrenRapid& obj) {
    out << "Tren Rapid:\n";
    out << static_cast<const Tren&>(obj);
    return out;
}