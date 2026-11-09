#include "AsciiArtPrinter.h"


AsciiArtPrinter::AsciiArtPrinter() : instanceNum(0) {}

AsciiArtPrinter::~AsciiArtPrinter() = default;

void AsciiArtPrinter::PrintArt(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();

    instanceNum++;
    printedPages.push(instanceNum);
}

void AsciiArtPrinter::PrintArtOnly(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void AsciiArtPrinter::GoBack() {
    if (printedPages.size() < 2) {
        cout << "No previous state available." << endl;
        return;
    }

    printedPages.pop();
    instanceNum = printedPages.top();

    string filename = "art" + to_string(instanceNum) + ".txt";
    PrintArt(filename);
    instanceNum--;
}

int AsciiArtPrinter::getInstNum() {
    
    return instanceNum;
}