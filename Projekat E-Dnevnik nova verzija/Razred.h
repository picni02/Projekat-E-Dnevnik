#pragma once
#include "Razrednik.h"
#include "Ucenik.h"
#include <vector>

using namespace std;

class Razred {
private:
	vector <Ucenik> ucenici;
	Razrednik razrednik;
	string nazivRazreda;
	string pomNazivRazreda = nazivRazreda + ".txt";
	static int brojUcenika;
	int kapacitetRazreda;
public:
	Razred() = default;
	void setNazivRazreda(string nazivRazreda);
	void setKapacitetRazreda(int brojUcenika);
	void setRazrednika();
	void dodajUcenikauRazred(Ucenik& ucenik);
	void izbrisiUcenikaIzRazreda();
	void ispisRazreda();
	string getNazivRazreda();
	string getPomNazivRazreda();
	int getBrojUcenika();
	vector<Ucenik>& getUcenici();
	void ispisUcenika();
	void pretragaUcenika(int id);
	void unesiOcjenuUceniku(int id);
	void ispisOcjenaUcenika(int id);
	void ispisRazrednika();
	void operator++(int);  // uvecava broj ucenika za 1
	~Razred() = default;
};