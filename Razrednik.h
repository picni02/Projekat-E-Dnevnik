#pragma once
#include "Osoba.h"
#include <iostream>

using namespace std;

class Razrednik : public Osoba {
private:
	char razred[20];
	char spol[10];
public:
	Razrednik();
	void setRazred();
	void setSpol();
	char* getRazred();
	char* getSpol();
	~Razrednik() = default;
};
