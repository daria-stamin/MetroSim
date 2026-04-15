#include <cstring>
#include "Tren.h"
#include <iostream>



// virtual float calculeazaEficienta() const = 0;
// virtual void afisare() const = 0;

int Tren::nrTren = 0;

Tren::Tren(): id(++nrTren){
    this->capacitate = 0;
    this->pret = 0;
    this->viteza = 0.0;
}
Tren::Tren( int capacitate, float viteza, int pret):id(++nrTren) {
    this->capacitate = capacitate;
    this->pret = pret;
    this->viteza = viteza;
}
Tren::Tren(const Tren& obj): id(++nrTren) {
    this->capacitate = obj.capacitate;
    this->pret = obj.pret;
    this->viteza = obj.viteza;
}
Tren& Tren::operator=(const Tren& obj) {
    if (this == &obj)
        return *this;
    this->capacitate = obj.capacitate;
    this->pret = obj.pret;
    this->viteza = obj.viteza;
    return *this;
}

Tren::~Tren() {

}


std::istream& operator>>(std::istream& in, Tren& obj) {
   // char buff[256];
    // std::cout << "  Name: ";
    // in.getline(buff, 256);
    // obj.nume = buff;

    std::cout << "  Capacitatea trenului: ";
    in >> obj.capacitate;
    in.ignore();

    std::cout << "  Pretul trenului: ";
    in >> obj.pret;
    in.ignore();

    std::cout << "  Viteza trenului: ";
    in >> obj.viteza;
    in.ignore();

    return in;
}

std::ostream& operator<<(std::ostream& out, const Tren& obj) {
    out << "  [Trenul #" << obj.id << "] ";
    out << std::endl <<" Capacitatea trenului: " << obj.capacitate;
    out << std::endl <<" Pretul trenului: " << obj.pret;
    out << std::endl <<" Viteza trenului: " << obj.viteza;

    return out;
}

