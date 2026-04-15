
#ifndef METROSIM_TRENNORMAL_H
#define METROSIM_TRENNORMAL_H
#include "Tren.h"

class TrenNormal : public Tren {
public:
    TrenNormal();
    TrenNormal(int capacitate, float viteza, int pret);
    TrenNormal(const TrenNormal &obj);

    virtual ~TrenNormal();

    TrenNormal &operator=(const TrenNormal &obj);

    friend std::ostream &operator<<(std::ostream &out, const TrenNormal &obj);
    friend std::istream &operator>>(std::istream &in, TrenNormal &obj);

    float calculeazaEficienta() const override;
    void afisare() const override;

};


#endif //METROSIM_TRENNORMAL_H