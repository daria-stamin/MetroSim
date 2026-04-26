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
    std::vector<Statie> statiiDisponibile;
    float pretBilet;
    int indexUrmatoareaStatie;
public:
    Linie();
    Linie(std::vector<Statie> statii, std::vector<Tren*> trenuri, float pretBilet);
    Linie(const Linie& obj);

    ~Linie();
    Linie& operator=(const Linie& obj);

    friend std::ostream& operator<<(std::ostream& os, const Linie& obj);
    friend std::istream& operator>>(std::istream& is, Linie& obj);

    int calculVenitTotal() ;

    void adaugaStatie(const Statie& statie);
    void adaugaStatieDisponibila(const Statie& s);
    void adaugaTren(Tren* t);

    Statie getStatieDisponibila(int index) const;

    bool areStatiiDeDeblocat() const;
    Statie getUrmatoareaStatie() const;
    void cresteIndex();
    void seteazaIndex(int x);

    const float getPretBilet() const;
    void setPretBilet(float pretnou);

    const int getIndexUrmStatie() const;
    void setIndexStatie(int index);

};




#endif //METROSIM_LINIE_H