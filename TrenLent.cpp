
#include "TrenLent.h"
#include <iostream>

TrenLent::TrenLent() {
    this->capacitate = 35;
    this->viteza = 20;
    this->pret = 1500;
}

TrenLent::TrenLent(int capacitate, float viteza, int pret) : Tren(capacitate, viteza, pret) {}

TrenLent::TrenLent(const TrenLent& obj) : Tren(obj) {}

TrenLent& TrenLent::operator=(const TrenLent& obj) {
    if (this != &obj) {
        Tren::operator=(obj);
    }
    return *this;
}

TrenLent::~TrenLent() {}

float TrenLent::calculeazaEficienta() const {
    return viteza * 0.5;
}

void TrenLent::afisare() const {
    std::cout << "Tren Lent:\n";
    std::cout << *this;
}

std::istream& operator>>(std::istream& in, TrenLent& obj) {
    in >> static_cast<Tren&>(obj);
    return in;
}

std::ostream& operator<<(std::ostream& out, const TrenLent& obj) {
    out << "Tren Lent:\n";
    out << static_cast<const Tren&>(obj);
    return out;
}