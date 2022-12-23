#include "Roditelj.h"
#include <iostream>

Roditelj::Roditelj() {
	char ime[30] = "Novi";
	char prezime[30] = "Roditelj";
	int godiste = 1970;
	this->setIme(ime);
	this->setPrezime(prezime);
	this->setGodiste(godiste);
	this->setId();
}

