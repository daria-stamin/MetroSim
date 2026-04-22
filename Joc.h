//
// Created by daria on 4/15/2026.
//

#ifndef METROSIM_JOC_H
#define METROSIM_JOC_H
#include <vector>
#include "Linie.h"

class Joc {
    int bani;
    int turaCurenta;
    int maxTure;
    std::vector<Linie> linii;
    std::vector<Linie> liniiBlocate;
    int indexLinieDeDeblocat;
public:
    Joc();
    void meniuLoading();
    void poveste();
    void ruleazaJoc();
    void ruleazaTura();

    void afiseazaStatus() const;
    void meniu();

    void cumparaLinie();
    void cumparaTren();
    void extindeLinie();

    void afiseazaTot() const;
};


#endif //METROSIM_JOC_H