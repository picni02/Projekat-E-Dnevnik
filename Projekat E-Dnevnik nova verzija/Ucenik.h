#pragma once
#include <iostream>
#include <vector>
#include "Osoba.h"
#include "Predmet.h"

enum Status { odlican, vrloDobar, dobar, dovoljan, nedovoljan };

class Ucenik : public Osoba {
private:
	vector <Predmet> predmeti;
	string razred;
	Status statusUcenika;
public:
	Ucenik() = default;
	void setRazred(string razred);
	void setOcjena();
	void setStatus();
	string getRazred();
	vector<Predmet>& getOcjene();
	string getStatus();
	friend istream& operator>>(istream& stream, Ucenik& ucenik);
	friend ostream& operator<<(ostream& stream, Ucenik& ucenik);
	
	~Ucenik() = default;
};