#pragma once
#include "Ucenik.h"
#include "Razrednik.h"
#include <vector>
using namespace std;

class Razred {
private:
	char nazivRazreda[30];
	vector<Ucenik> ucenici;
	Razrednik razrednik;
	int brojUcenika;
	int idRazrednika;
public:
	Razred();
	void setNazivRazreda();
	void setBrojUcenika();
	char* getNazivRazreda();
	int getBrojUcenika();
	void unosUcenika(Ucenik& ucenik);
	void ucitajUcenike();

	~Razred() = default;
};