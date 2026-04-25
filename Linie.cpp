//
// Created by daria on
#include "Linie.h"
#include "Tren.h"
#include "TrenLent.h"
#include "TrenNormal.h"
#include "TrenRapid.h"

Linie::Linie() {
    this->pretBilet = 2.5;
    this->indexUrmatoareaStatie = 0;
}
Linie::Linie(std::vector<Statie> statii, std::vector<Tren*> trenuri, float pretBilet){
    this->statii = statii;
    this->pretBilet = pretBilet;
    this->indexUrmatoareaStatie = 0;
}
Linie::Linie(const Linie& obj) {
    this->statii = obj.statii;
    this->statiiDisponibile = obj.statiiDisponibile;
    this->pretBilet = obj.pretBilet;
    this->indexUrmatoareaStatie = obj.indexUrmatoareaStatie;

    for(int i = 0; i < obj.trenuri.size(); i++) {
        trenuri.push_back(obj.trenuri[i]);
    }
}

Linie &Linie::operator=(const Linie &obj) {
    if (this == &obj)
        return *this;

    this->statii = obj.statii;
    this->statiiDisponibile = obj.statiiDisponibile;
    this->pretBilet = obj.pretBilet;
    this->indexUrmatoareaStatie = obj.indexUrmatoareaStatie;

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

    out << "Statii: ";
    int ult=obj.statii.size();
    for (int i = 0; i < obj.statii.size(); i++) {
        if (i == ult-1)
            out << obj.statii[i];
        else
            out << obj.statii[i]<< " -> ";
    }
    out << "\n";
    out << "Trenuri: ";
    for (int i = 0; i < obj.trenuri.size(); i++) {
        obj.trenuri[i]->afisare();
        out << " ";
    }

    return out;
}
int Linie::calculVenitTotal(){
    int total = 0;
    int eficentaTrenBonus = 0;
    for (int i = 0; i < trenuri.size(); i++) {
        eficentaTrenBonus += trenuri[i]->calculeazaEficienta() * pretBilet;
    }
    for (int i=0;i<statii.size();i++) {
        total += statii[i].genereazaCerere();
    }
    return total + eficentaTrenBonus;
}

void Linie::adaugaTren(Tren* t) {
    trenuri.push_back(t);
}

void Linie::adaugaStatie(const Statie& statie) {
    statii.push_back(statie);
}
void Linie::adaugaStatieDisponibila(const Statie& s) {
    statiiDisponibile.push_back(s);
}

bool Linie::areStatiiDeDeblocat() const {
    return indexUrmatoareaStatie < statiiDisponibile.size();
}

Statie Linie::getUrmatoareaStatie() const {
    return statiiDisponibile[indexUrmatoareaStatie];
}

void Linie::cresteIndex() {
    indexUrmatoareaStatie++;
}

void Linie::seteazaIndex(int x) {
    indexUrmatoareaStatie = x;
}
