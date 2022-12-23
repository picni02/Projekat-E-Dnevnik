#pragma once
#include "Osoba.h"
#include "Ucenik.h"
#include <iostream>
#include <vector>
using namespace std;

class Roditelj : public Osoba {
	vector<Ucenik> djeca;
public:
	Roditelj();
	void dodajDijete(Ucenik& dijete);
	vector<Ucenik>& getDjeca();
	friend istream& operator>>(istream& stream, Roditelj& roditelj);
	friend ostream& operator<<(ostream& stream, Roditelj& roditelj);
	~Roditelj() = default;
};