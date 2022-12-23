#pragma once
#include "Predmet.h"
#include "Osoba.h"
#include <iostream>
#include <vector>

using namespace std;

enum Status{odlican, vrloDobar, dobar, dovoljan, nedovoljan};

class Ucenik : public Osoba {
private:
	char ime[30], prezime[30], razred[20];
	vector<Predmet> ocjene;
	static int id;
	Status status;
public:
	Ucenik();
	Ucenik(const Ucenik& ucenik);
	//static void setId(int id);
	//static int getId();
	//void setIme(char ime[30]);
	//void setPrezime(char prezime[30]);
	void setRazred(char razred[30]);
	void setOcjena();
	//char* getIme();
	//char* getPrezime();
	char* getRazred();
	vector<Predmet>& getOcjene();
	Status promijeniStatus();
	string getStatus();
	friend istream& operator>>(istream& stream, Ucenik& ucenik);
	friend ostream& operator<<(ostream& stream, Ucenik& ucenik);
	//void operator++(); // uvecava id ucenika za 1 od prethodno unesenog
	void setStatus(char status[30]);
	~Ucenik() = default;
};
