#include "Ucenik.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Ucenik::setRazred(string razred) {
	this->razred = razred;
}

void Ucenik::setOcjena() {
	Predmet predmet;
	cin.ignore();
	predmet.setNazivPredmeta();
	predmet.setOcjena();

	predmeti.push_back(predmet);

	string nazivDokumenta = this->getIme() + this->getPrezime() + ".txt";
	ofstream unos(nazivDokumenta, ios::app);
	unos << predmet.getNazivPredmeta() << ": " << predmet.getOcjena() << endl;
	unos.close();

	cout << "Uspjesno ste unijeli ocjenu uceniku " << this->getIme() << " iz predmeta " << predmet.getNazivPredmeta() << ".\n";
}

void Ucenik::setStatus() {
	int odabir;
	cout << "Status:\n\t1.odlican\n\t2.vrlo dobar\n\t3.dobar\n\t4.dovoljan\n\t5.nedovoljan\nOdabir: ";
	do {
		cin >> odabir;
	} while (odabir < 1 || odabir > 5);
	
	if (odabir == 1) {
		this->statusUcenika = Status::odlican;
		cout << "Status ucenika je promijenjen na " << this->getStatus() << "!\n";
	}
	else if (odabir == 2) {
		this->statusUcenika = Status::vrloDobar;
		cout << "Status ucenika je promijenjen na " << this->getStatus() << "!\n";
	}
	else if (odabir == 3) {
		this->statusUcenika = Status::dobar;
		cout << "Status ucenika je promijenjen na " << this->getStatus() << "!\n";
	}
	else if (odabir == 4) {
		this->statusUcenika = Status::dovoljan;
		cout << "Status ucenika je promijenjen na " << this->getStatus() << "!\n";
	}
	else if (odabir == 5) {
		this->statusUcenika = Status::nedovoljan;
		cout << "Status ucenika je promijenjen na " << this->getStatus() << "!\n";
	}
	else {
		cout << "Pogresan odabir!\n";
	}
}

string Ucenik::getRazred() {
	return this->razred;
}

vector<Predmet>& Ucenik::getOcjene() {
	return this->predmeti;
}

string Ucenik::getStatus() {
	if (this->statusUcenika == Status::odlican) {
		return "Odlican";
	}
	else if (this->statusUcenika == Status::vrloDobar) {
		return "Vrlo dobar";
	}
	else if (this->statusUcenika == Status::dobar) {
		return "Dobar";
	}
	else if (this->statusUcenika == Status::dovoljan) {
		return "Dovoljan";
	}
	else if (this->statusUcenika == Status::nedovoljan) {
		return "Nedovoljan";
	}
}

istream& operator>>(istream& stream, Ucenik& ucenik) {
	string ime, prezime, razred;

	cout << "Unesi ime: ";
	getline(cin, ime);
	ucenik.setIme(ime);
	cout << "Unesi prezime: ";
	getline(cin, prezime);
	ucenik.setPrezime(prezime);
	ucenik.setID();
	cin.ignore();
	cout << "Unesi razred: ";
	getline(cin, razred);
	ucenik.setRazred(razred);
	ucenik.setStatus();

	string nazivDokumenta = ucenik.getIme() + ucenik.getPrezime() + ".txt";
	ofstream unos(nazivDokumenta, ios::app);
	unos << "Ucenik: " << ucenik.getIme() << " " << ucenik.getPrezime() << endl;
	unos << "ID: " << ucenik.getID() << endl;
	unos << "Razred: " << ucenik.getRazred() << endl;
	unos << "Status: " << ucenik.getStatus() << endl;
	unos << "Ocjene: " << endl;
	unos.close();

	return stream;
}

ostream& operator<<(ostream& stream, Ucenik& ucenik) {
	stream << "Ime i prezime: " << ucenik.getIme() << " " << ucenik.getPrezime() << endl;
	stream << "ID: " << ucenik.getID()<<endl;
	stream << "Razred: " << ucenik.getRazred() << endl;
	stream << "Status: " << ucenik.getStatus() << endl;
	stream << "Predmet:\tOcjena\n";
	/*for (auto& i : ucenik.getOcjene()) {
		stream << i.getNazivPredmeta() << ": " << i.getOcjena() << endl;
	}
	*/
	return stream;
}
