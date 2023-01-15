#include "Razred.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

int Razred::brojUcenika = 0;

void Razred::setNazivRazreda(string nazivRazreda) {
	this->nazivRazreda = nazivRazreda;
}

void Razred::setKapacitetRazreda(int brojUcenika) {
	this->kapacitetRazreda = brojUcenika;
}

void Razred::setRazrednika() {
	cin >> this->razrednik;
}

void Razred::dodajUcenikauRazred(Ucenik& ucenik) {
	ucenici.push_back(ucenik);
}

void Razred::ispisRazreda() {
	int br = 1;
	cout << "Razred: " << this->getNazivRazreda() << endl;
	cout << "Broj ucenika: " << this->getBrojUcenika() << endl;
	cout << "Kapacitet razreda: " << this->kapacitetRazreda << endl;
	cout << "Razrednik: " << this->razrednik.getIme() <<" "<<this->razrednik.getPrezime() << endl;
	if (this->ucenici.empty() == true) {
		cout << "Razred je prazan. Molimo da prvo unesete ucenika u razred!\n";
	}
	else {
		cout << setw(10) << "Redni broj" << setw(30) << "Ime i prezime" << setw(20) << "ID" << setw(20) << "Status" << endl;
		for (auto& r : this->ucenici) {
			cout << setw(10) << br << setw(30) << r.getIme() << " " << r.getPrezime() << setw(20) << r.getID() << setw(20) << r.getStatus() << endl;
			br++;
		}
	}
	
}

void Razred::izbrisiUcenikaIzRazreda() {
	this->ispisRazreda();
	int odabir;
	cout << "Odabir: ";
	
	do {
		cin >> odabir;
	} while (odabir < 1 || odabir > this->ucenici.size());

	this->ucenici.erase(this->ucenici.begin() + odabir - 1);
	cout << "Ucenik pod brojem " << odabir << " je uspjesno uklonjen iz razreda!\n";
}

string Razred::getNazivRazreda() {
	return this->nazivRazreda;
}

string Razred::getPomNazivRazreda() {
	return this->pomNazivRazreda;
}

int Razred::getBrojUcenika() {
	return this->brojUcenika;
}

vector<Ucenik>& Razred::getUcenici() {
	return this->ucenici;
}

void Razred::ispisUcenika() {
	int br = 1;
	cout << "------------------------------------------------------------------------------------------------\n";
	cout << setw(10) << "R.br" << setw(30) << "\tIme i prezime"<<setw(15)<<"\tStatus"<<setw(10)<<"\tID" << endl;
	for (auto& i : this->ucenici) {
		cout << setw(10)<< br << setw(30) << i.getIme() << " " << i.getPrezime() << setw(15) << i.getStatus() << setw(10) << i.getID() << endl;
	}
	cout << "------------------------------------------------------------------------------------------------\n";
}

void Razred::pretragaUcenika(int id) {
	shared_ptr<Razred> ucenik = make_shared<Razred>();
	for (auto& i : this->ucenici) {
		if (i.getID() == id) {
			ucenik->getUcenici().push_back(i);
		}
	}

	if (ucenik->getUcenici().size() == 0) {
		cout << "Nema ucenika pod tim ID-om!\n";
		system("pause");
	}
	else {
		ucenik->ispisUcenika();
	}
}

void Razred::unesiOcjenuUceniku(int id) {
	int br = 0;
	for (auto& i : this->ucenici) {
		if (i.getID() == id) {
			i.setOcjena();
			br++;
		}
	}
	if (br == 0) {
		throw invalid_argument("Nema ucenika sa tim ID-om!");
	}
}

void Razred::ispisOcjenaUcenika(int id) {
	for (auto& i : this->ucenici) {
		if (i.getID() == id) {
			cout << setw(10) << "Predmet" << setw(10) << "Ocjena" << endl;
			for (auto& j : i.getOcjene()) {
				cout << setw(10) << j.getNazivPredmeta() << setw(10) << j.getOcjena() << endl;
			}
		}
	}
}

void Razred::ispisRazrednika() {
	cout << this->razrednik;
}

void Razred::operator++(int) {
	this->brojUcenika += 1;
}