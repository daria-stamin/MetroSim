//
// Created by daria on 4/15/2026.
//

#ifndef METROSIM_LINIE_H
#define METROSIM_LINIE_H
#include "Statie.h"
#include "Tren.h"
#include <vector>

class Linie {
    std::vector<Statie> statii;
    std::vector<Tren*> trenuri;
    float pretBilet;
public:
    Linie();
    Linie(std::vector<Statie> statii, std::vector<Tren*> trenuri, float pretBilet);
    Linie(const Linie& obj);

    ~Linie();
    Linie& operator=(const Linie& obj);

    friend std::ostream& operator<<(std::ostream& os, const Linie& obj);
    friend std::istream& operator>>(std::istream& is, Linie& obj);

    int calculVenitTotal();

    void adaugaStatie(const Statie& statie);
    void adaugaTren(Tren* t);

};


#endif //METROSIM_LINIE_H