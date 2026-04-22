
#include "Joc.h"
#include "Tren.h"
#include "TrenLent.h"
#include "TrenNormal.h"
#include "TrenRapid.h"

Joc::Joc() {
    bani = 1000;
    turaCurenta = 0;
    maxTure = 60;

    Linie M2;
    Statie s1("Pipera");
    Statie s2("Victoriei");
    Statie s3("Romana");

    Tren* t = new TrenLent(100, 50, 1000);
    M2.adaugaTren(t);

    M2.adaugaStatie(s1);
    M2.adaugaStatie(s2);
    M2.adaugaStatie(s3);

    linii.push_back(M2);
}


void Joc::ruleazaJoc() {
    while (turaCurenta < maxTure) {
        afiseazaStatus();
        meniu();
        ruleazaTura();
    }

    if (bani >= 100000)
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
    std::cout<<"---------------MetroSim----------------"<<std::endl<<std::endl;
    std::cout<<"Bani total: "<<bani<<"\n";
    std::cout<<"Tura curenta: "<<turaCurenta<<"/"<<maxTure<<"\n";
    afiseazaTot();
}

void Joc::cumparaLinie(){
    std::cout<<"Linie noua costa 20.000 de bani."<<std::endl;
    if (bani >= 20000) {
        Linie l;
        linii.push_back(l);
        bani -= 20000;
    } else {
        std::cout << "Nu ai bani!\n";
    }
    std::cout<<"Press 0 to continue...\n";
    int x;
    std::cin>>x;
    while (x!=0) {
        std::cout<<"Invalid number! Try again.\n";
        std::cin>>x;
    }
    system("CLS");
    meniu();

}
void Joc::cumparaTren(){
    std::cout<<"Un Tren Lent costa 1.000 de bani."<<std::endl;
    std::cout<<"Un Tren Normal costa 3.000 de bani."<<std::endl;
    std::cout<<"Un Tren Rapid costa 5.000 de bani."<<std::endl;
    int index;
    std::cout << "Alege linia: ";
    std::cin >> index;

    std::cout<<"Ce fel de tren vrei sa cumperi:"<<std::endl;

    std::cout<<"1. Tren Lent"<<std::endl;
    std::cout<<"2. Tren Normal"<<std::endl;
    std::cout<<"3. Tren Rapid"<<std::endl;


    int y;
    std::cin>>y;
    switch(y) {
        case(1):
        {
            if (bani >= 1000) {
                Tren* t = new TrenLent(100, 50, 1000);
                linii[index].adaugaTren(t);
                bani -= 1000;
            }
            break;
        }
        case(2):
        {
            if (bani >= 3000) {
                Tren* t = new TrenNormal(100, 70, 3000);
                linii[index].adaugaTren(t);
                bani -= 3000;
            }
            break;
        }
        case(3):
        {
            if (bani >= 5000) {
                Tren* t = new TrenRapid(100, 90, 5000);
                linii[index].adaugaTren(t);
                bani -= 5000;
            }
            break;
        }
    }



    std::cout<<"Press 0 to continue...\n";
    int x;
    std::cin>>x;
    while (x!=0) {
        std::cout<<"Invalid number! Try again.\n";
        std::cin>>x;
    }
    system("CLS");
    meniu();
}
void Joc::extindeLinie() {
    std::cout<<"Statie noua costa 8.000 de bani."<<std::endl;
    int index;
    std::cout << "Alege linia: ";
    std::cin >> index;

        // if (bani >= 300) {
        //
        //     linii[index].adaugaStatie(const &Statie statie);
        // }

    std::cout<<"Press 0 to continue...\n";
    int x;
    std::cin>>x;
    while (x!=0) {
        std::cout<<"Invalid number! Try again.\n";
        std::cin>>x;
    }
    system("CLS");
    meniu();
}

void Joc::afiseazaTot() const{

    for (int i = 0; i < linii.size(); i++) {
        std::cout << "\nLinia " << i+1 << ":\n";

        std::cout << linii[i] << "\n";
    }
}


void Joc::meniu() {
    std::cout << "\n1. Cumpara linie\n";
    std::cout << "2. Cumpara tren\n";
    std::cout << "3. Extinde linie\n";
    std::cout << "0. Continua\n"<<std::endl;



    int x;
    std::cout<<"Press the number:";
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
           // system("CLS");
            cumparaLinie();
            break;
        }
        case(2):
        {
            //system("CLS");
            cumparaTren();
            break;
        }
        case(3):
        {
           // system("CLS");
            extindeLinie();
            break;
        }


    }
}

// M1.adaugaStatie("Dristor 2");
// M1.adaugaStatie("Obor");
// M1.adaugaStatie("Gara de Nord");
// M1.adaugaStatie("Eroiilor");
// M1.adaugaStatie("Izvor");
// M1.adaugaStatie("Republica");

// M2.adaugaStatie("Universitate");
// M2.adaugaStatie("Unirii");
// M2.adaugaStatie("Berceni");

// M3.adaugaStatie("Preciziei");
// M3.adaugaStatie("Gorjului");
// M3.adaugaStatie("Lujerului");
// M3.adaugaStatie("Timpuri Noi");
// M3.adaugaStatie("Dristor 1");
// M3.adaugaStatie("Anghel Salingy");


