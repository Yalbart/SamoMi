#include "PrintItem.h"

void PrintItem::PrintArt(const string& filename) {
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}

void PrintItem::PrintArtOnly(ItemType type) {
    string filename;

    switch (type) {
    case ItemType::Banana:
        filename = "banana.txt";
        break;
    case ItemType::Jabuka:
        filename = "jabuka.txt";
        break;
    case ItemType::Olovka:
        filename = "olovka.txt";
        break;
    case ItemType::Maramice:
        filename = "maramice.txt";
        break;
    case ItemType::Pacov:
        filename = "covpa.txt";
        break;
    case ItemType::Amulet:
        filename = "amulet.txt";
        break;
    }

    PrintArt(filename);
}