#pragma once

using namespace std;
class Osoba {
private:
	char ime[30], prezime[30];
	int godiste;
	static int id;
public:
	Osoba();
	virtual void setId();
	void setIme(char ime[30]);
	void setPrezime(char prezime[30]);;
	void setGodiste(int godiste);
	char* getIme();
	char* getPrezime();
	int getGodiste();
	int getId();
	friend istream& operator>>(istream& stream, Osoba& osoba);
	friend ostream& operator<<(ostream& stream, Osoba& osoba);
	~Osoba() = default;
};
