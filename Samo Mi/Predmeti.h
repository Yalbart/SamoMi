#pragma once
#include <string>
#include <iostream>
using namespace std;
enum class ItemType {
    Banana,
    Jabuka,
    Olovka,
    Maramice,
    Pacov,
    Amulet
};

class Predmeti {
public:
    Predmeti(ItemType type);

    string GetName() const;
    double GetPrice() const;
    int GetHungerRegen() const;

private:
    ItemType type;
    string ime;
    double cena;
    int zasitnost;
};


