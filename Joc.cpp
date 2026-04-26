
#include "Joc.h"
#include "Tren.h"
#include "TrenLent.h"
#include "TrenNormal.h"
#include "TrenRapid.h"
#include "Exceptii.h"
#include <fstream>
Joc::Joc() {
    bani = 1000;
    turaCurenta = 0;
    maxTure = 90;

    indexLinieDeDeblocat = 0;


    Linie M2;
    M2.adaugaStatieDisponibila(Statie("Pipera"));
    M2.adaugaStatieDisponibila(Statie("Victoriei"));
    M2.adaugaStatieDisponibila(Statie("Romana"));
    M2.adaugaStatieDisponibila(Statie("Universitate"));
    M2.adaugaStatieDisponibila(Statie("Unirii"));
    M2.adaugaStatieDisponibila(Statie("Berceni"));

    for (int i = 0; i < 3; i++) {
        M2.adaugaStatie(M2.getUrmatoareaStatie());
        M2.cresteIndex();
    }

    Tren* t = new TrenLent(100, 50, 1000);
    M2.adaugaTren(t);

    linii.push_back(M2);

    Linie M1;
    M1.adaugaStatieDisponibila(Statie("Dristor_2"));
    M1.adaugaStatieDisponibila(Statie("Obor"));
    M1.adaugaStatieDisponibila(Statie("Gara_de_Nord"));
    M1.adaugaStatieDisponibila(Statie("Eroilor"));
    M1.adaugaStatieDisponibila(Statie("Izvor"));
    M1.adaugaStatieDisponibila(Statie("Republica"));

    for (int i = 0; i < 3; i++) {
        M1.adaugaStatie(M1.getUrmatoareaStatie());
        M1.cresteIndex();
    }

    liniiBlocate.push_back(M1);


    Linie M3;
    M3.adaugaStatieDisponibila(Statie("Preciziei"));
    M3.adaugaStatieDisponibila(Statie("Gorjului"));
    M3.adaugaStatieDisponibila(Statie("Lujerului"));
    M3.adaugaStatieDisponibila(Statie("Timpuri_Noi"));
    M3.adaugaStatieDisponibila(Statie("Dristor_1"));
    M3.adaugaStatieDisponibila(Statie("Anghel_Saligny"));

    for (int i = 0; i < 3; i++) {
        M3.adaugaStatie(M3.getUrmatoareaStatie());
        M3.cresteIndex();
    }

    liniiBlocate.push_back(M3);
}

void Joc::poveste() {
    std::cout << R"(
                    ---------- MetroSim ----------


        Dupa al 67-lea refuz de angajare de la o companie IT te dai batut.
    Poate viata corporatista nu e de tine...

    Cu coada intre picioare o iei incet-incet spre metrou Pipera.

    In metrou gasesti urmatorul anunt:

    *******************************************************************************************
        MeroRex isi mareste echipa!

    Intership pe 3 luni in echipa de management. Dupa perioada de proba daca totul merge bine
    garantam JOB.
    *******************************************************************************************

    Ai 3 luni la dispozitie (90 de ture) sa maresti sistemul de trenuri si sa faci profit
    companiei de 100.000 de bani.

    Succes!!

    Apasa 0 pentru a continua: )";
    citesteZero();
}
int Joc::citesteOptiunemeniu() {
    int x;
    while (true) {
        try {
            std::cin >> x;
            if (std::cin.fail()) {
                throw InputInvalidException("Nu ai introdus un numar!");
            }

            if (x != 0 && x != 1 && x != 2 && x != 3) {
                throw InputInvalidException("Trebuie sa introduci o optiune valida!");
            }
            system("CLS");
            return x;
        }
        catch (const InputInvalidException& e) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << e.what() << " Incearca din nou: ";
        }
    }
}
int Joc::citesteZero() {
    int x;
    while (true) {
        try {
            std::cin >> x;
            if (std::cin.fail()) {
                throw InputInvalidException("Nu ai introdus un numar!");
            }

            if (x != 0) {
                throw InputInvalidException("Trebuie sa introduci 0!");
            }
            system("CLS");
            return x;
        }
        catch (const InputInvalidException& e) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << e.what() << " Incearca din nou: ";
        }
    }
}

void Joc::goodEnding() {
    system("CLS");

    std::cout << R"(


                _    _                    _   _             _     _
               / \  (_)      ___ __ _ ___| |_(_) __ _  __ _| |_  | |
              / _ \ | |     / __/ _` / __| __| |/ _` |/ _` | __| | |
             / ___ \| |    | (_| (_| \__ \ |_| | (_| | (_| | |_  |_|
            /_/   \_\_|     \___\__,_|___/\__|_|\__, |\__,_|\__| (_)
                                                |___/

        Metrorex a decis sa te angajeze full time!

     )";
    std::cout<<"Apasa 0 pentru a iesi:";
    citesteZero();
}
void Joc::badEnding() {
    system("CLS");
    std::cout << R"(


                _    _            _              _       _     _
               / \  (_)     _ __ (_) ___ _ __ __| |_   _| |_  | |
              / _ \ | |    | '_ \| |/ _ \ '__/ _` | | | | __| | |
             / ___ \| |    | |_) | |  __/ | | (_| | |_| | |_  |_|
            /_/   \_\_|    | .__/|_|\___|_|  \__,_|\__,_|\__| (_)
                           |_|

        Oricum munca e overrated!

     )";

    std::cout<<"Apasa 0 pentru a iesi:";
    citesteZero();
}

void Joc::ruleazaJoc() {
    while (turaCurenta < maxTure) {
        afiseazaStatus();
        bool continua = meniu();
        if (continua) {
            ruleazaTura();
            salveaza();
        }

    }
    int ok = 0;
    if (indexLinieDeDeblocat == liniiBlocate.size())
        ok = 1;

    for (int i = 0; i < linii.size(); i++) {
        Linie& l = linii[i];
        if (l.areStatiiDeDeblocat()) {
            ok = 0;
        }
    }
    if (bani >= 100000 && ok == 1)
        goodEnding();
    else
        badEnding();
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

void Joc::meniuLoading() {
    std::cout << R"(
    ---------- MetroSim ----------


   ___________   ___________________________________________
    ___   ___ |||  ___   ___   ___    ___ ___  |   __  ,----\
   |   | |   |||| |   | |   | |   |  |   |   | |  |  | |_____\
   |___| |___|||| |___| |___| |___|  | O | O | |  |  |        \
              |||                    |___|___| |  |__|         )
   ___________|||______________________________|______________/
              |||                                        /--------
   -----------'''---------------------------------------'

   0. New Game
   1. Continue Game
   2. Quit

    Press the number: )";
    int n;
    std::cin>>n;
    switch (n) {
        case(0):
        {
            system("CLS");
            poveste();
            system("CLS");
            ruleazaJoc();
            break;
        }
        case(1):
        {
            system("CLS");
            incarca();
            ruleazaJoc();
            break;
        }
        case(2):
        {
            return;
            break;
        }
    }
}

void Joc::afiseazaStatus() const {
    std::cout<<"---------------MetroSim----------------"<<std::endl<<std::endl;
    std::cout<<"Bani total: "<<bani<<"\n";
    std::cout<<"Tura curenta: "<<turaCurenta<<"/"<<maxTure<<"\n";
    afiseazaTot();
}

void Joc::cumparaLinie(){
    std::cout<<"Extindere costa 20.000 de bani.\n";

    if (bani < 20000) {
        throw BaniInsuficientiException();
    }

    if (indexLinieDeDeblocat < liniiBlocate.size()) {

        Linie l = liniiBlocate[indexLinieDeDeblocat];
        linii.push_back(l);

        bani -= 20000;

        std::cout << "Ai deblocat o noua magistrala!\n";

        indexLinieDeDeblocat++;

    } else {
        std::cout << "Ai deblocat toate magistralele!\n";
    }

    std::cout<<"Apasa 0 pentru a continua: ";
    citesteZero();
    system("CLS");

}
void Joc::cumparaTren(){
    std::cout<<"Un Tren Lent costa 1.000 de bani."<<std::endl;
    std::cout<<"Un Tren Normal costa 3.000 de bani."<<std::endl;
    std::cout<<"Un Tren Rapid costa 5.000 de bani."<<std::endl;
    int index;
    std::cout << "Alege linia: "<<'\n';
    for (int i=0; i < linii.size(); i++) {
        std::cout<<i<<std::endl;
    }
    std::cin >> index;

    if (index < 0 || index >= linii.size()) {
        throw IndexInvalidException();

    }

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


    std::cout<<"Apasa 0 pentru a continua: ";
    citesteZero();
    system("CLS");

}
void Joc::extindeLinie() {
    std::cout << "Statie noua costa 8000 bani.\n";

    int index;
    std::cout << "Alege linia: ";
    std::cout<<'\n';
    for (int i=0;i<linii.size();i++)
        std::cout<<i<<'\n';

    std::cin >> index;

    if (index < 0 || index >= linii.size()) {
        throw IndexInvalidException();

    }

    Linie& l = linii[index];

    if (bani < 8000) {
        throw BaniInsuficientiException();

    }

    if (!l.areStatiiDeDeblocat()) {
        std::cout << "Nu mai exista statii de deblocat!\n";
    } else {
        Statie s = l.getUrmatoareaStatie();
        l.adaugaStatie(s);
        l.cresteIndex();

        bani -= 8000;

    }

    std::cout<<"Apasa 0 pentru a continua: ";
    citesteZero();
    system("CLS");

}
void Joc::afiseazaTot() const{

    for (int i = 0; i < linii.size(); i++) {
        std::cout << "\nLinia " << i << ":\n";
        std::cout << linii[i] << "\n";
    }

}


bool Joc::meniu() {
    std::cout << "\n1. Cumpara linie\n";
    std::cout << "2. Cumpara tren\n";
    std::cout << "3. Extinde linie\n";
    std::cout << "0. Continua\n"<<std::endl;



    int x = citesteOptiunemeniu();
    try {
        switch(x)
        {
            case(1):
                system("CLS");
                cumparaLinie();
                system("CLS");
                afiseazaStatus();
                meniu();
                break;

            case(2):
                system("CLS");
                cumparaTren();
                system("CLS");
                afiseazaStatus();
                meniu();
                break;

            case(3):
                system("CLS");
                extindeLinie();
                system("CLS");
                afiseazaStatus();
                meniu();
                break;

            case(0):
                system("CLS");
                return true;
        }
    }
    catch (const std::exception& e) {
        std::cout << "Eroare: " << e.what() << "\n";
        std::cout << "Apasa 0 pentru a continua: ";
        citesteZero();
    }


}

void Joc::salveaza() {
    std::ofstream out("save.txt");

    out << bani << " " << turaCurenta<<std::endl;
    out<< linii.size()<<std::endl;

    for(int i=0; i<linii.size(); i++){
        linii[i].salveazaStatiile(i);

    }
}

void Joc::incarca() {
    std::ifstream in("save.txt");

    int baniSave, turaSave;
    in >> baniSave >> turaSave;

    *this = Joc();
    linii.clear();
   // liniiBlocate.clear();

    bani = baniSave;
    turaCurenta = turaSave;
    int nrLiniiSalvate;
    in >> nrLiniiSalvate;
    //indexLinieDeDeblocat = 0;
    for (int i=0; i<nrLiniiSalvate;i++) {
        Linie M;
        int nrStatiiSalvate;
        in>>nrStatiiSalvate;
        for (int j=0; j<nrStatiiSalvate; j++) {
            std::string statie;
            in>>statie;
            M.adaugaStatieDisponibila(Statie(statie));

        }
        for (int i = 0; i < nrStatiiSalvate; i++) {
            M.adaugaStatie(M.getUrmatoareaStatie());
            M.cresteIndex();
            
        }
        Tren* t = new TrenLent(100, 50, 1000);
        M.adaugaTren(t);

        linii.push_back(M);

    }
    indexLinieDeDeblocat = nrLiniiSalvate - 1;

}