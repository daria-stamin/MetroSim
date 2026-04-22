//
// Created by daria on 4/15/2026.
//

#ifndef METROSIM_STATIE_H
#define METROSIM_STATIE_H
#include <string>



class Statie {
    std::string name;


public:

    Statie();
    Statie(std::string name);
    Statie(const Statie &obj);

    Statie &operator=(const Statie &obj);
    ~Statie();

    friend std::istream& operator>>(std::istream& in, Statie &obj);
    friend std::ostream& operator<<(std::ostream& out, const Statie &obj);


    int genereazaCerere();

    //int getCerere() const;
};


#endif //METROSIM_STATIE_H