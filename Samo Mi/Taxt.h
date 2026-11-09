#pragma once
#include <iostream>
#include "Predmeti.h"

using namespace std;
class Taxt {
private:
    double pare;
    int glad;
    int magija;

public:
    Taxt();
    void SetPare(double novaPare);
    void SetGlad(int novaGlad);
    void SetMagija(int novaMagija);
    double GetPare() const;
    int GetGlad() const;
    int GetMagija() const;
    void stanje() const;
};


