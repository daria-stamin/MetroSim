#ifndef METROSIM_EXCEPTII_H
#define METROSIM_EXCEPTII_H

#include <exception>
#include <string>

class InputInvalidException : public std::exception {
    std::string mesaj;

public:
    InputInvalidException(const std::string& mesaj = "Input invalid!")
        : mesaj(mesaj) {}

    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};


class BaniInsuficientiException : public std::exception {
    std::string mesaj;
public:
    BaniInsuficientiException(const std::string& mesaj = "Nu ai suficenti bani!")
        : mesaj(mesaj) {}

    const char* what() const noexcept override {
        return mesaj.c_str();
    }

};
class IndexInvalidException : public std::exception {
    std::string mesaj;
public:
    IndexInvalidException(const std::string& mesaj = "Nu ai selectat indexul valid!")
        : mesaj(mesaj) {}

    const char* what() const noexcept override {
        return mesaj.c_str();
    }

};

#endif //METROSIM_EXCEPTII_H