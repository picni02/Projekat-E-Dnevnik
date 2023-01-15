#pragma once
#include "Osoba.h"
#include <iostream>
using namespace std;

enum Spol { muski, zenski };

class Razrednik : public Osoba {
private:
	string razred;
	Spol spol;
public:
	Razrednik();
	void setRazred(string razred);
	void setSpol();
	string getRazred();
	string getSpol();
	friend istream& operator>>(istream& stream, Razrednik& razrednik);
	friend ostream& operator<<(ostream& stream, Razrednik& razrednik);
	~Razrednik() = default;
};