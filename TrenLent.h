
#ifndef METROSIM_TRENLENT_H
#define METROSIM_TRENLENT_H
#include "Tren.h"

class TrenLent : public Tren {

public:
    TrenLent();
    TrenLent(int capacitate, float viteza, int pret);
    TrenLent(const TrenLent& obj);

    TrenLent& operator=(const TrenLent& obj);

    virtual ~TrenLent();

    friend std::ostream& operator<<(std::ostream& os, const TrenLent& obj);
    friend std::istream& operator>>(std::istream& is, TrenLent& obj);

    float calculeazaEficienta() const override;
    void afisare() const override;
};


#endif //METROSIM_TRENLENT_H