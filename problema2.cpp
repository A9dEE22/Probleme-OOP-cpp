#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Comanda {
protected:
    int id_comanda;
    double valoare_totala;
public:
    Comanda(int id, double val) : id_comanda(id), valoare_totala(val) {}
    virtual void proceseaza() = 0;
    virtual void afiseazaDetalii() = 0;
    virtual ~Comanda() {}
};

class ComandaOnline : public Comanda {
    string adresa_livrare;
public:
    ComandaOnline(int id, double val, string adr) 
        : Comanda(id, val), adresa_livrare(adr) {}

    void proceseaza() override {
        cout << "Comanda online #" << id_comanda 
             << " este pregatita pentru livrare la: " 
             << adresa_livrare << endl;
    }

    void afiseazaDetalii() override {
        cout << "Comanda Online - ID: " << id_comanda
             << ", Valoare: " << valoare_totala
             << ", Adresa: " << adresa_livrare << endl;
    }
};

class ComandaMagazin : public Comanda {
    int nr_casier;
public:
    ComandaMagazin(int id, double val, int casier) 
        : Comanda(id, val), nr_casier(casier) {}

    void proceseaza() override {
        cout << "Comanda din magazin #" << id_comanda 
             << " a fost procesata la casierul " << nr_casier << endl;
    }

    void afiseazaDetalii() override {
        cout << "Comanda Magazin - ID: " << id_comanda
             << ", Valoare: " << valoare_totala
             << ", Casier: " << nr_casier << endl;
    }
};

template <typename T>
class ProcesorComenzi {
    vector<T*> lista;
public:
    void adaugaComanda(T* c) {
        lista.push_back(c);
    }

    void ruleazaProcesare() {
        for (auto c : lista) {
            c->afiseazaDetalii();
            c->proceseaza();
        }
    }

    ~ProcesorComenzi() {
        for (auto c : lista) {
            delete c;
        }
    }
};

int main() {
    ProcesorComenzi<Comanda> procesor;

    procesor.adaugaComanda(new ComandaOnline(1, 150.5, "Str. Lalelelor nr.10"));
    procesor.adaugaComanda(new ComandaMagazin(2, 89.9, 3));
    procesor.adaugaComanda(new ComandaOnline(3, 230.0, "Bd. Republicii nr.5"));

    procesor.ruleazaProcesare();

    return 0;
}
