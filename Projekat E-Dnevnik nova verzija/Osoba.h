#pragma once
#include <iostream>
using namespace std;

class Osoba {
private:
	string ime, prezime;
	unsigned int id;
public:
	Osoba() = default;
	void setIme(string ime);
	void setPrezime(string prezime);
	void setID();
	
	int brojKreiranihOsoba();
	string getIme();
	string getPrezime();
	int getID();
	
	~Osoba() = default;
};