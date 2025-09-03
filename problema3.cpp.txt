#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicul {
protected:
    int viteza_maxima;
public:
    Vehicul(int v) : viteza_maxima(v) {}
    virtual void accelereaza() = 0;
    virtual void afiseazaTip() = 0;
    virtual ~Vehicul() {}
};

class Masina : public Vehicul {
    int nr_usi;
public:
    Masina(int v, int u) : Vehicul(v), nr_usi(u) {}

    void accelereaza() override {
        cout << "Masina cu " << nr_usi << " usi accelereaza..." << endl;
    }

    void afiseazaTip() override {
        cout << "Tip: Masina, Viteza maxima: " << viteza_maxima 
             << ", Numar usi: " << nr_usi << endl;
    }
};

class Motocicleta : public Vehicul {
    bool are_sidecar;
public:
    Motocicleta(int v, bool s) : Vehicul(v), are_sidecar(s) {}

    void accelereaza() override {
        cout << "Motocicleta accelereaza rapid..." << endl;
    }

    void afiseazaTip() override {
        cout << "Tip: Motocicleta, Viteza maxima: " << viteza_maxima 
             << ", Are sidecar: " << (are_sidecar ? "Da" : "Nu") << endl;
    }
};

template <typename T>
void gestioneazaVehicule(vector<T*> lista) {
    for (auto v : lista) {
        v->afiseazaTip();
        v->accelereaza();
    }
}

int main() {
    vector<Vehicul*> vehicule;

    vehicule.push_back(new Masina(180, 4));
    vehicule.push_back(new Motocicleta(220, false));
    vehicule.push_back(new Masina(200, 2));
    vehicule.push_back(new Motocicleta(160, true));

    gestioneazaVehicule(vehicule);

    for (auto v : vehicule) {
        delete v;
    }

    return 0;
}
