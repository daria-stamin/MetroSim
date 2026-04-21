//
// Created by daria on 4/15/2026.
//
#include <string>
#include <iostream>
#include "Statie.h"
#include <cstdlib>

Statie::Statie() {
    this->name = "";
    this->cererePAsageri = 0;
}
Statie::Statie(std::string name, int cererePAsageri) {
    this->name = name;
    this->cererePAsageri = cererePAsageri;
}
Statie::Statie(const Statie& obj) {
    this->name = obj.name;
    this->cererePAsageri = obj.cererePAsageri;
}

Statie &Statie::operator=(const Statie &obj) {
    if (this == &obj)
        return *this;
    this->name = obj.name;
    this->cererePAsageri = obj.cererePAsageri;

    return *this;
}
Statie::~Statie() {

}

std::istream& operator>>(std::istream& in, Statie &obj) {
    char buff[256];
    std::cout << "  Name: ";
    in.getline(buff, 256);
    obj.name = buff;

    std::cout << "  Cerere pasageri: ";
    in >> obj.cererePAsageri;
    in.ignore();
    return in;
}
 std::ostream& operator<<(std::ostream& out, const Statie &obj) {
    out << "Statia: " << obj.name;
    out << std::endl <<" Cererea Pasagerilor: " << obj.cererePAsageri;
    return out;
}

int Statie::genereazaCerere() {

    srand(time(0));
    int randomNum = (rand() % 601) + 500; // (nr random dintre 0-600) + 500 gen
    return randomNum;
}

const std::string& getName() {
   // return name;
 }
