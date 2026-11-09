#include "Taxt.h"
Taxt::Taxt()
    : pare(0.0), glad(20), magija(0) {
    // Empty constructor sets all member variables to zero
}

void Taxt::stanje() const {

    
    cout << "                                                         Pare: "<<pare << endl;
    cout << "                                                         Glad: "<<glad << endl;
    cout << "                                                         Preostala magija: "<<magija << endl;
    cout << endl;
}
void Taxt::SetPare(double novaPare) {
    pare = novaPare;
}

void Taxt::SetGlad(int novaGlad) {
    glad = novaGlad;
}

void Taxt::SetMagija(int novaMagija) {
    magija = novaMagija;
}
double Taxt::GetPare() const {
    return pare;
}

int Taxt::GetGlad() const {
    return glad;
}

int Taxt::GetMagija() const {
    return magija;
}