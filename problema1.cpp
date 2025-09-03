#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Angajat {
protected:
    string nume;
    double salariu_baza;
public:
    Angajat(string n, double s) : nume(n), salariu_baza(s) {}
    virtual double calculeazaSalariu() = 0;
    virtual void afiseazaDetalii() = 0;
    virtual ~Angajat() {}
};

class AngajatFullTime : public Angajat {
    double bonus_anual;
public:
    AngajatFullTime(string n, double s, double b) 
        : Angajat(n, s), bonus_anual(b) {}

    double calculeazaSalariu() override {
        return salariu_baza + bonus_anual / 12;
    }

    void afiseazaDetalii() override {
        cout << "Angajat FullTime: " << nume 
             << ", Salariu baza: " << salariu_baza
             << ", Bonus anual: " << bonus_anual
             << ", Salariu total: " << calculeazaSalariu()
             << endl;
    }
};

class AngajatPartTime : public Angajat {
    int ore_lucrate;
    double tarif_ora;
public:
    AngajatPartTime(string n, double s, int ore, double tarif) 
        : Angajat(n, s), ore_lucrate(ore), tarif_ora(tarif) {}

    double calculeazaSalariu() override {
        return ore_lucrate * tarif_ora;
    }

    void afiseazaDetalii() override {
        cout << "Angajat PartTime: " << nume 
             << ", Ore lucrate: " << ore_lucrate
             << ", Tarif/ora: " << tarif_ora
             << ", Salariu total: " << calculeazaSalariu()
             << endl;
    }
};

template <typename T>
void proceseazaAngajati(vector<T*> lista) {
    for (auto ang : lista) {
        ang->afiseazaDetalii();
    }
}

int main() {
    vector<Angajat*> angajati;

    angajati.push_back(new AngajatFullTime("Ion Popescu", 3000, 2400));
    angajati.push_back(new AngajatPartTime("Maria Ionescu", 0, 80, 25));
    angajati.push_back(new AngajatFullTime("Andrei Georgescu", 4000, 3600));

    proceseazaAngajati(angajati);

    for (auto ang : angajati) {
        delete ang;
    }

    return 0;
    
    }