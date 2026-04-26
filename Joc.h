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

    int citesteZero();
    int citesteOptiunemeniu();
    int citesteLoading();

    void poveste();
    void ruleazaTura();

    void afiseazaStatus() const;
    bool meniu();

    void cumparaLinie();
    void cumparaTren();
    void extindeLinie();

    void afiseazaTot() const;

    void goodEnding();
    void badEnding();

public:
    Joc();

    void meniuLoading();
    void ruleazaJoc();


    void incarca();
    void salveaza();

};


#endif //METROSIM_JOC_H