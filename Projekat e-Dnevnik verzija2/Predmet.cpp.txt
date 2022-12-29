#include "Predmet.h"
#include <iostream>
using namespace std;

Predmet::Predmet() {
	strcpy_s(this->nazivPredmeta, "Predmet");
	this->ocjena = 5;
}

Predmet::Predmet(const Predmet& predmet) {
	strcpy_s(this->nazivPredmeta, predmet.nazivPredmeta);
	this->ocjena = predmet.ocjena;
}

void Predmet::setNazivPredmeta() {
	cout << "Unesi naziv predmeta: ";
	cin.getline(this->nazivPredmeta, 20);
}

void Predmet::setOcjena() {
	cout << "Unesi ocjenu iz predmeta " << this->nazivPredmeta << ": ";
	cin >> this->ocjena;
}

char* Predmet::getNazivPredmeta() {
	return this->nazivPredmeta;
}

int Predmet::getOcjena() {
	return this->ocjena;
}

istream& operator>>(istream& stream, Predmet& predmet) {
	predmet.setNazivPredmeta();
	predmet.setOcjena();

	return stream;
}

ostream& operator>>(ostream& stream, Predmet& predmet) {
	stream << "Naziv predmeta: " << predmet.getNazivPredmeta() << endl;
	stream << "Ocjena: " << predmet.getOcjena() << endl;

	return stream;
}