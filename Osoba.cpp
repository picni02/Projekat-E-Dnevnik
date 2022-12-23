#include "Osoba.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

int Osoba::id = 1;

void Osoba::setId() {
	vector<int> vectorID;
	string provjera;
	ifstream ispis("id.txt");
	if (!ispis) {
		cout << "[GRESKA] Datoteka se ne moze otvoriti!\n";
	}
	while(ispis.eof()){
		ispis >> provjera;
		if (provjera != " ") {
			vectorID.push_back(stoi(provjera));
		}
	}
	for (int i = 0; i < vectorID.size(); i++) {
		if (vectorID[i] == Osoba::id) {
			Osoba::id += 1;
		}
	}
}

int Osoba::getId() {
	return Osoba::id;
}

Osoba::Osoba() {
	strcpy_s(this->ime, "Nova");
	strcpy_s(this->prezime, "Osoba");
	this->godiste = 2000;
	this->id = 1;
}

void Osoba::setIme(char ime[30]) {
	strcpy_s(this->ime, ime);
}

void Osoba::setPrezime(char prezime[30]) {
	strcpy_s(this->prezime, prezime);

}

void Osoba::setGodiste(int godiste) {
	this->godiste = godiste;
}

char* Osoba::getIme() {
	return this->ime;
}
char* Osoba::getPrezime() {
	return this->prezime;
}
int Osoba::getGodiste() {
	return this->godiste;
}

int Osoba::getId() {
	return this->id;
}

istream& operator>>(istream& stream, Osoba& osoba) {
	char ime[30], prezime[30];
	int godiste;
	cout << "Unesi ime: ";
	cin.getline(ime, 30);
	osoba.setIme(ime);
	cout << "Unesi prezime: ";
	cin.getline(prezime, 30);
	osoba.setPrezime(prezime);
	int pom;
	do {
		cout << "Godiste osobe: ";
		cin >> pom;
		if (pom < 1900 || pom > 2023) {
			throw "Unijeli ste pogresno godiste. Pokusajte ponovo!\n";
		}

	} while (pom < 1900 || pom > 2023);
	osoba.setGodiste(pom);
	osoba.setId();

	return stream;
}

ostream& operator<<(ostream& stream, Osoba& osoba) {
	stream << "Ime: " << osoba.getIme() << endl;
	stream << "Prezime: " << osoba.getPrezime() << endl;
	stream << "Godiste: " << osoba.getGodiste() << endl;
	stream << "ID: " << osoba.getId() << endl;

	return stream;
}