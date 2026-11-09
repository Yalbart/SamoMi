#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "Predmeti.h"
using namespace std;
class AsciiArtPrinter
{
private:
	int instanceNum;
	stack<int> printedPages;
	
public:
	AsciiArtPrinter();
	~AsciiArtPrinter();

	void PrintArt(const string& filename);
	void Footer();
	void GoBack();
	static void PrintArtOnly(const std::string& filename);
	int getInstNum();

};

