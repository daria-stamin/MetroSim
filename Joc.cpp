
#include "Joc.h"
#include "Tren.h"
#include "TrenLent.h"
#include "TrenNormal.h"
#include "TrenRapid.h"

Joc::Joc() {
    bani = 1000;
    turaCurenta = 0;
    maxTure = 90;

    Linie l;
    linii.push_back(l);
}


void Joc::ruleazaJoc() {
    while (turaCurenta < maxTure) {
        afiseazaStatus();
        meniu();
        ruleazaTura();
    }

    if (bani >= 25000)
        std::cout << "AI CASTIGAT!\n";
    else
        std::cout << "AI PIERDUT!\n";
}

void Joc::ruleazaTura() {
    int venitTotal = 0;
    for (int i=0; i < linii.size(); i++) {
        venitTotal += linii[i].calculVenitTotal();
    }
    bani += venitTotal;
    turaCurenta++;

    std::cout<< "Ai castigat: " << venitTotal << " bani\n";
}

void Joc::afiseazaStatus() const {
    std::cout<<"Bani total: "<<bani<<"\n";
    std::cout<<"Tura curenta: "<<turaCurenta<<"/"<<maxTure<<"\n";
}

void Joc::cumparaLinie(){
    if (bani >= 500) {
        Linie l;
        linii.push_back(l);
        bani -= 500;
    } else {
        std::cout << "Nu ai bani!\n";
    }

}
void Joc::cumparaTren(){
    int index;
    std::cout << "Alege linia: ";
    std::cin >> index;

    if (bani >= 300) {
        Tren* t = new TrenLent(100, 50, 200);
        linii[index].adaugaTren(t);
        bani -= 300;
    }
}
void Joc::extindeLinie() {
        int index;
        std::cout << "Alege linia: ";
        std::cin >> index;

        // if (bani >= 300) {
        //
        //     linii[index].adaugaStatie(const &Statie statie);
        // }
}

void Joc::afiseazaTot() const{
    std::cout << "\n===== RETEA METRO =====\n";

    for (int i = 0; i < linii.size(); i++) {
        std::cout << "\nLinia " << i << ":\n";

        std::cout << linii[i] << "\n";
    }
}


void Joc::meniu() {
    std::cout << "\n1. Cumpara linie\n";
    std::cout << "2. Cumpara tren\n";
    std::cout << "3. Extinde linie\n";
    std::cout << "0. Continua\n";

    int x;
    std::cin>>x;
    while(x > 3)
    {
        std::cout<<"Invalid number! Please try again!"<<'\n';
        std::cout<<"Press the number:";
        std::cin>>x;
        std::cout<<std::endl;
    }
    switch(x)
    {
        case(1):
        {
            system("CLS");
            cumparaLinie();
            break;
        }
        case(2):
        {
            system("CLS");
            cumparaTren();
            break;
        }
        case(3):
        {
            system("CLS");
            extindeLinie();
            break;
        }


    }
}