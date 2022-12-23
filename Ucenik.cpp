#include "Ucenik.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

int Ucenik::id = 1;

/*void Ucenik::setId(int id) {
	Ucenik::id = id;
}
int Ucenik::getId() {
	return Ucenik::id;
}*/

Ucenik::Ucenik() {
	strcpy(this->ime, "Novi");
	strcpy(this->prezime, "Ucenik");
	strcpy(this->razred, "1a");
	this->id = 1;
	this->status = Status::odlican;
}

Ucenik::Ucenik(const Ucenik& ucenik) {
	strcpy(this->ime, ucenik.ime);
	strcpy(this->prezime, ucenik.prezime);
	strcpy(this->razred, ucenik.razred);
	this->id = ucenik.id;
	this->status = ucenik.status;
}

/*void Ucenik::setIme(char ime[30]) {
	// cout << "Unesi ime ucenika: ";
	// cin.getline(this->ime, 30);
	strcpy_s(this->ime, ime);
}

void Ucenik::setPrezime(char prezime[30]) {
	//cout << "Unesi prezime ucenika: ";
	//cin.getline(this->prezime, 30);
	strcpy_s(this->prezime, prezime);
}
*/
void Ucenik::setRazred(char razred[30]) {
	// cout << "Unesi razred ucenika: ";
	// cin.getline(this->razred, 20);
	strcpy_s(this->razred, razred);
}

void Ucenik::setOcjena() {
	Predmet ocjena;
	ocjena.setNazivPredmeta();
	ocjena.setOcjena();

	ocjene.push_back(ocjena);
}

void Ucenik::setStatus(char status[30]) {
	if (_strcmpi("Odlican", status) == 0) {
		this->status = Status::odlican;
	}
	else if (_strcmpi("Vrlo dobar", status) == 0) {
		this->status = Status::vrloDobar;
	}
	else if (_strcmpi("Dobar", status) == 0) {
		this->status = Status::dobar;
	}
	else if (_strcmpi("Dovoljan", status) == 0) {
		this->status = Status::dovoljan;
	}
	else if (_strcmpi("Nedovoljan", status) == 0) {
		this->status = Status::nedovoljan;
	}
}

/*char* Ucenik::getIme() {
	return this->ime;
}

char* Ucenik::getPrezime() {
	return this->prezime;
}
*/
char* Ucenik::getRazred() {
	return this->razred;
}

vector<Predmet>& Ucenik::getOcjene() {
	return this->ocjene;
}

Status Ucenik::promijeniStatus() {
	int odabir;
	cout << "Status:\n\t1. odlican\n\t2.vrlo dobar\n\t 3. dobar\n\t4. dovoljan\n\t5. nedovoljan\nOdabir:";
	cin >> odabir;
	do {
		switch (odabir)
		{
		case 1:
			this->status = Status::odlican;
			cout << "Status ucenika je promijenjen sa " << this->getStatus() << " na odlican!\n";
		case 2:
			this->status = Status::vrloDobar;
			cout << "Status ucenika je promijenjen sa " << this->getStatus() << " na vrlo dobar!\n";
		case 3:
			this->status = Status::dobar;
			cout << "Status ucenika je promijenjen sa " << this->getStatus() << " na dobar!\n";
		case 4:
			this->status = Status::dovoljan;
			cout << "Status ucenika je promijenjen sa " << this->getStatus() << " na dovoljan!\n";
		case 5:
			this->status = Status::nedovoljan;
			cout << "Status ucenika je promijenjen sa " << this->getStatus() << " na nedovoljan!\n";
		default:
			cout << "Pogresan odabir!\n";
			break;
		}
	} while (odabir < 1 || odabir > 5);
	
}

string Ucenik::getStatus() {
	if (this->status == Status::odlican) {
		return "Odlican";
	}
	else if (this->status == Status::vrloDobar) {
		return "Vrlo dobar";
	}
	else if (this->status == Status::dobar) {
		return "Dobar";
	}
	else if (this->status == Status::dovoljan) {
		return "Dovoljan";
	}
	else if (this->status == Status::nedovoljan) {
		return "Nedovoljan";
	}
}

istream& operator>>(istream& stream, Ucenik& ucenik) {
	char ime[30], prezime[30], razred[30];
	cout << "Unesi ime: ";
	cin.getline(ime, 30);
	ucenik.setIme(ime);
	cout << "Unesi prezime: ";
	cin.getline(prezime, 30);
	ucenik.setPrezime(prezime);
	cout << "Unesi razred: ";
	cin.getline(razred, 30);
	ucenik.setRazred(razred);
	ucenik.setId();
	ucenik.promijeniStatus();
	ucenik.unosUcenika(ucenik);
	return stream;
}

ostream& operator<<(ostream& stream, Ucenik& ucenik) {
	stream << "Ime ucenika: " << ucenik.getIme() << endl;
	stream << "Prezime ucenika: " << ucenik.getPrezime() << endl;
	stream << "Godiste ucenik: " << ucenik.getGodiste() << endl;
	stream << "ID ucenika: " << ucenik.getId() << endl;
	stream << "Razred: " << ucenik.getRazred() << endl;
	stream << "Status ucenika: " << ucenik.getStatus() << endl;

	return stream;
}


void Ucenik::unosUcenika(Ucenik& ucenik) {
	ofstream datoteka("ucenici.txt", ios::app);
	ofstream datoteka1("id.txt", ios::app);
	datoteka << "ID: " << ucenik.getId() << endl;
	datoteka1 << ucenik.getId() << endl;
	datoteka << "Ime i prezime ucenika: " << ucenik.getIme()<<" "<<ucenik.getPrezime() << endl;
	datoteka << "Razred: " << ucenik.getRazred() << endl;
	datoteka << "Status: " << ucenik.getStatus() << endl;
	datoteka.close();
	datoteka1.close();
}

void ucitajUcenike() {
	string provjera, tekst, tekst1;
 
	Ucenik temp;
	vector<Ucenik> ucenici;
	ifstream ispis("ucenici.txt");
	if (!ispis) {
		cout << "[GRESKA] Datoteka se ne moze otvoriti!\n";
	}
	while (ispis.eof()) {
		ispis >> provjera;
		if (provjera == "ID:") {
			ispis >> provjera;
			temp.setId(stoi(provjera));
		}
	}	if (provjera == "Ime i prezime ucenika:") {
		tekst = "";
		tekst1 = "";
		do {
			ispis >> provjera;
			if (provjera != " ") {
				tekst += provjera;
			}
			else if (provjera != "Razred:") {
				tekst1 += provjera;
			}
		} while (provjera != "Razred:");
		string s = tekst;
		string s1 = tekst1;
		char niz[50], niz1[50];

		strcpy(niz, s.c_str());
		strcpy(niz1, s1.c_str());
		temp.setIme(niz);
		temp.setPrezime(niz1);
		if (provjera == "Razred:") {
			ispis >> provjera;
			temp.setRazred(stoi(provjera));
		}
		if (provjera == "Iznos:") {
			ispis >> provjera;
			temp.iznos = stoi(provjera);
		}
		if (provjera == "Vrsta:") {
			ispis >> provjera;
			if (provjera == "Privatni") {
				temp.vrsta = privatni;
			}
			if (provjera == "Poslovni") temp.vrsta = poslovni;
			if (provjera == "Super") temp.vrsta = super;
			ucenici.push_back(temp);
		}
	}
}
