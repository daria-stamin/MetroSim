#ifndef METROSIM_TREN_H
#define METROSIM_TREN_H
#include <iostream>

class Tren {
protected:
    static int nrTren;
    const int id;
    int capacitate;
    float viteza;
    int pret;

public:
    Tren();
    Tren( int capacitate, float viteza, int pret);
    Tren(const Tren& obj);

    Tren& operator=(const Tren& obj);

    virtual ~Tren();

    friend std::istream& operator>>(std::istream& in, Tren& obj);
    friend std::ostream& operator<<(std::ostream& out, const Tren& obj);

    virtual float calculeazaEficienta() const = 0;
    virtual void afisare() const = 0;

};


#endif //METROSIM_TREN_H