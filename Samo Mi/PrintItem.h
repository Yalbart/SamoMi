#pragma once
#include "AsciiArtPrinter.h"

class PrintItem : public AsciiArtPrinter {
public:
    void PrintArt(const std::string& filename);
    void PrintArtOnly(ItemType type);
};

