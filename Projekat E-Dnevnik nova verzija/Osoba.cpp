#include "Osoba.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*Osoba::Osoba() {
	this->ime = "Nova";
	this->prezime = "Osoba";
	this->id = 1;
}
*/

void Osoba::setIme(string ime) {
	this->ime = ime;
}

void Osoba::setPrezime(string prezime) {
	this->prezime = prezime;
}


int Osoba::brojKreiranihOsoba() {
	int pom = 0;
	string provjera;
	ifstream ispis("id.txt");
	if (!ispis) {
		cout << "[GRESKA] Datoteka se ne moze otvoriti!\n";
	}
	while (ispis.eof()) {
		ispis >> provjera;
		pom = stoi(provjera);
	}
	return pom;
}

void Osoba::setID() {
	unsigned int pom = brojKreiranihOsoba();
	this->id = pom + 1;
}

string Osoba::getIme() {
	return this->ime;
}

string Osoba::getPrezime() {
	return this->prezime;
}

int Osoba::getID() {
	return this->id;
}
