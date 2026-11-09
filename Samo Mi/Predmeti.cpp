#include "Predmeti.h"
Predmeti::Predmeti(ItemType itemType) : type(itemType) {
    switch (type) {
    case ItemType::Banana:
        ime = "Banana";
        cena = 22.0; 
        zasitnost = 20;
        break;
    case ItemType::Jabuka:
        ime = "Jabuka";
        cena = 11.0; 
        zasitnost = 15;
        break;
    case ItemType::Olovka:
        ime = "Olovka";
        cena = 15.3; 
        zasitnost = 5;
        break;
    case ItemType::Maramice:
        ime = "Maramice";
        cena = 33.0; 
        zasitnost = 2;
        break;
    case ItemType::Pacov:
        ime = "Covpa";
        cena = 0.2; 
        zasitnost = -35; 
        break;
    case ItemType::Amulet:
        ime = "Amulet";
        cena = 33.3; 
        zasitnost = -10;
        break;
    }
}


std::string Predmeti::GetName() const {
   
        return ime;
}

double Predmeti::GetPrice() const {
    // Add implementation for getting price of each item
    return cena;
}

int Predmeti::GetHungerRegen() const {
    // Add implementation for getting hunger regeneration of each item
    return zasitnost;
}