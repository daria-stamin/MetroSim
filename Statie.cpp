
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

    srand(time(0));
    int randomNum = (rand() % 601) + 200; // (nr random dintre 0-600) + 200 gen
    return randomNum;
}

const std::string& getName() {
   // return name;
 }
