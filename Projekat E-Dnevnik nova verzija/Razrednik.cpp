#include "Razrednik.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Razrednik::Razrednik() {
	this->setIme("Novi");
	this->setPrezime("Razrednik");
	this->setRazred("Razred");
	this->setID();
	this->setSpol();
}

void Razrednik::setRazred(string razred) {
	this->razred = razred;
}

void Razrednik::setSpol() {
	int odabir;
	cout << "Odabir spola:\n\t1.muski\n\t2.zenski\nOdabir: ";
	do {
		cin >> odabir;
	} while (odabir < 1 || odabir > 2);
	if (odabir == 1) {
		this->spol = Spol::muski;
		cout << "Spol razrednika je postavljen na muski!" << endl;
	}
	else if (odabir == 2) {
		this->spol = Spol::zenski;
		cout << "Spol razrednika je postavljen na zenski" << endl;
	}
}

string Razrednik::getRazred() {
	return this->razred;
}

string Razrednik::getSpol() {
	if (this->spol == Spol::muski) {
		return "Muski";
	}
	else if (this->spol == Spol::zenski) {
		return "Zenski";
	}
}

istream& operator>>(istream& stream, Razrednik& razrednik) {
	string ime, prezime, razred;
	cout << "Unesi ime razrednika: ";
	getline(cin, ime);
	razrednik.setIme(ime);
	cout << "Unesi prezime razrednika: ";
	getline(cin, prezime);
	razrednik.setPrezime(prezime);
	razrednik.setID();
	cout << "Unesi razred razrednika: ";
	getline(cin, razred);
	razrednik.setRazred(razred);
	razrednik.setSpol();

	string nazivDokumenta = razrednik.getIme() + razrednik.getPrezime() + ".txt";
	ofstream unos(nazivDokumenta, ios::app);
	unos << "Razrednik: " << razrednik.getIme() << " " << razrednik.getPrezime() << endl;
	unos << "ID: " << razrednik.getID() << endl;
	unos << "Razred: " << razrednik.getRazred() << endl;
	unos << "Spol: " << razrednik.getSpol() << endl;
	unos.close();

	return stream;
}

ostream& operator<<(ostream& stream, Razrednik& razrednik) {
	stream << "Ime i prezime razrednika: " << razrednik.getIme() << " " << razrednik.getPrezime() << endl;
	stream << "ID razrednika: " << razrednik.getID() << endl;
	stream << "Razred: " << razrednik.getRazred() << endl;
	stream << "Spol: " << razrednik.getSpol() << endl;
	
	return stream;
}