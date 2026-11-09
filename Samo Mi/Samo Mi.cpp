// Samo Mi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "AsciiArtPrinter.h"
#include "Predmeti.h"
#include "PrintItem.h"
#include "Taxt.h"

using namespace std;

int main()
{
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
    srand(static_cast<unsigned int>(time(0)));

    AsciiArtPrinter printer;
    PrintItem printerItema;
    string filename;
    Taxt taxt;
    int input;
    double price;
    double currentPare;
    int hungerRegen;
    int currentGlad;
    int currentMagija;
    
    for (int i = 1; i < 32; i++) {
        int itemType = rand() % 6; 

        ItemType type;
        switch (itemType) {
        case 0:
            type = ItemType::Banana;
            break;
        case 1:
            type = ItemType::Jabuka;
            break;
        case 2:
            type = ItemType::Olovka;
            break;
        case 3:
            type = ItemType::Maramice;
            break;
        case 4:
            type = ItemType::Pacov;
            break;
        case 5:
            type = ItemType::Amulet;
            break;
        }

        Predmeti item(type);
        
        if (i > 1) {
            printerItema.PrintArtOnly(type);
            cout << "                                                                           Novi dan , nova parica!" << endl;
            cout << "                                                                         Pronasli ste novi predmet! " << endl;
            cout << endl;
            cout << "                                                         Predmet: " << item.GetName() << endl;
            cout << "                                                         Cena: " << item.GetPrice() << " para" << endl;
            cout << "                                                         Zasitnost: " << item.GetHungerRegen() << endl;
            cout << "                                                                 Sta bi ste zeleli da uradite sa ovim predmetom?" << endl;
            cout << "                                                       Unesite broj 1 da bi ste ga pojeli ili 2 da bi ste ga prodali." << endl;
            cout << endl;
            cin >> input;

            if (input == 1) {
                // Reduce glad by the GetHungerRegen value of the item
                hungerRegen = item.GetHungerRegen();
                currentGlad = taxt.GetGlad();
                taxt.SetGlad(currentGlad - hungerRegen);
                // Check if the item is "Amajlija" and update magija value
                if (item.GetName() == "Amulet") {
                    currentMagija = taxt.GetMagija();
                    taxt.SetMagija(currentMagija + 1);
                }
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (input == 2) {
                // Sell the item and raise pare by the GetPrice value
                price = item.GetPrice();
                currentPare = taxt.GetPare();
                taxt.SetPare(currentPare + price);
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else {
                cout << "Dok ste se premisljali sta da uradite sa ovim predmetom, jedno malo dete je projurilo pored vas i otelo vam ga iz ruke. (Pogresan unos)" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }

            system("pause");
            system("cls");
        }
        filename = "art" + to_string(i) + ".txt";
        printer.PrintArt(filename);
        if (i > 1) {
            cout << "                                                         Dan:" << printer.getInstNum() - 1 << endl;
            taxt.stanje();
        }
        currentGlad = taxt.GetGlad();
        taxt.SetGlad(currentGlad + 5);

        if (taxt.GetGlad() > 100) {
            system("cls");
            printerItema.PrintArt("smrt.txt");
            system("pause");

            exit(0);
        }

        if (taxt.GetPare() > 333) {
            system("cls");
            printerItema.PrintArt("pobedaa.txt");
            system("pause");

            exit(0);
        }
        if (taxt.GetMagija() > 0) {
            cout<<"Posedujete (" << taxt.GetMagija() << ") magiju, da li zelite da je iskoristite i vratite se u proslost ? " << endl;
            cout << "Unesite broj 1 ukoliko zelite , a bilo koji drugi taster ukoliko ne zelite." << endl;
            cin >> input;
            if (input == 1) {
                system("cls");
                printer.GoBack();
                i--;
                taxt.SetMagija(currentMagija--);
                cout<<"Vratili ste se u proslost..." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                system("pause");
            }
            else {
                //cin.clear();
                cout << "" << endl;
                cout << "                           Nastavljate zivot normalnim tokom..." << endl;
                cin.clear();
                cin.ignore(1000, '\n');

            }
        }

        system("pause");
        system("cls");
    }
    
    printerItema.PrintArt("kraj.txt");
    system("pause");
    system("cls");

    return 0;
}


