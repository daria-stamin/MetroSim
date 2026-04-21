//
// Created by daria on
#include "Linie.h"
#include "Tren.h"
#include "TrenLent.h"
#include "TrenNormal.h"
#include "TrenRapid.h"

Linie::Linie() {
    this->pretBilet = 0;
}
Linie::Linie(std::vector<Statie> statii, std::vector<Tren*> trenuri, float pretBilet){
    this->statii = statii;
    this->pretBilet = pretBilet;
}
Linie::Linie(const Linie& obj) {
    this->statii = obj.statii;
    this->pretBilet = obj.pretBilet;

    for (int i = 0; i < obj.trenuri.size(); i++) {
        trenuri.push_back(obj.trenuri[i]);
    }
}

Linie &Linie::operator=(const Linie &obj) {
    if (this == &obj)
        return *this;
    this->statii = obj.statii;
    this->pretBilet = obj.pretBilet;

    trenuri.clear();

    for (int i = 0; i < obj.trenuri.size(); i++) {
        trenuri.push_back(obj.trenuri[i]);
    }
    return *this;
}
Linie::~Linie() {
  //  delete[] trenuri.data();
    trenuri.clear();
}

std::istream& operator>>(std::istream& in, Linie& obj) {
    std::cout << "Pret bilet: ";
    in >> obj.pretBilet;

    int nrStatii;
    std::cout << "Numar statii: ";
    in >> nrStatii;

    obj.statii.clear();
    for (int i = 0; i < nrStatii; i++) {
        Statie s;
        in >> s;
        obj.statii.push_back(s);
    }

    int nrTrenuri;
    std::cout << "Numar trenuri: ";
    in >> nrTrenuri;

    obj.trenuri.clear();
    for (int i = 0; i < nrTrenuri; i++) {
        std::cout << "Tip tren (1-Lent, 2-Normal, 3-Rapid): ";
        int tip;
        in >> tip;

        Tren* t = nullptr;

        if (tip == 1)
            t = new TrenLent();
        else if (tip == 2)
            t = new TrenNormal();
        else if (tip == 3)
            t = new TrenRapid();

        if (t != nullptr) {
            in >> *t;
            obj.trenuri.push_back(t);
        }
    }

    return in;
}
std::ostream& operator<<(std::ostream& out, const Linie& obj) {
    out << "Pret bilet: " << obj.pretBilet << "\n";

    out << "Statii:\n";
    for (int i = 0; i < obj.statii.size(); i++) {
        out << obj.statii[i] << "\n";
    }

    out << "Trenuri:\n";
    for (int i = 0; i < obj.trenuri.size(); i++) {
        obj.trenuri[i]->afisare();
        out << "\n";
    }

    return out;
}
int Linie::calculVenitTotal() {
    int total = 0;
    int eficentaTrenBonus = 0;
    for (int i = 0; i < trenuri.size(); i++) {
        eficentaTrenBonus += trenuri[i]->calculeazaEficienta() * pretBilet;
    }
    for (int i=0;i<statii.size();i++) {
        total += statii[i].genereazaCerere();
    }
    return total * eficentaTrenBonus;
}

void Linie::adaugaTren(Tren* t) {
    trenuri.push_back(t);
}

void Linie::adaugaStatie(const Statie& statie) {
    statii.push_back(statie);
}