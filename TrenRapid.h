
#ifndef METROSIM_TRENRAPID_H
#define METROSIM_TRENRAPID_H
#include "Tren.h"

class TrenRapid : public Tren {
public:
    TrenRapid();
    TrenRapid(int capacitate, float viteza, int pret);
    TrenRapid(const TrenRapid &obj);

    virtual ~TrenRapid();

    TrenRapid &operator=(const TrenRapid &obj);

    friend std::ostream &operator<<(std::ostream &out, const TrenRapid &obj);
    friend std::istream &operator>>(std::istream &in, TrenRapid &obj);

    float calculeazaEficienta() const override;
    void afisare() const override;

};


#endif //METROSIM_TRENRAPID_H