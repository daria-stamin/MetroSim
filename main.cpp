#include <iostream>
#include "Tren.h"
#include "TrenLent.h"
#include "TrenNormal.h"
#include "TrenRapid.h"
int main() {
    TrenLent t1(100, 10, 100);
    TrenNormal t2(200, 20, 200);
    TrenRapid t3(300, 30, 300);
    std::cout << t1;
    std::cout << std::endl;
    std::cout << t2;
    std::cout << std::endl;
    std::cout << t3;

    std::cout << "Eficienta: " << t1.calculeazaEficienta() << "\n";

    return 0;
}