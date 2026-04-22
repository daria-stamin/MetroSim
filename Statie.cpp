
#include <string>
#include <iostream>
#include "Statie.h"
#include <cstdlib>

Statie::Statie() {
    this->name = "";

}
Statie::Statie(std::string name) {
    this->name = name;

}
Statie::Statie(const Statie& obj) {
    this->name = obj.name;

}

Statie &Statie::operator=(const Statie &obj) {
    if (this == &obj)
        return *this;
    this->name = obj.name;


    return *this;
}
Statie::~Statie() {

}

std::istream& operator>>(std::istream& in, Statie &obj) {
    char buff[256];
    std::cout << "  Name: ";
    in.getline(buff, 256);
    obj.name = buff;
    return in;
}
 std::ostream& operator<<(std::ostream& out, const Statie &obj) {
    out << obj.name;
    return out;
}

int Statie::genereazaCerere() {
    int randomNum = (rand() % 151) + 100;
    return randomNum;
}

const std::string& getName() {
   // return name;
 }
