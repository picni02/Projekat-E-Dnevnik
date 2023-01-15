#include <iostream>
#include "Razred.h"
#include "Ucenik.h"
#include "Razrednik.h"
#include <fstream>
#include <string>

using namespace std;

int glavniMeni() {
	int odabir;
	system("cls");
	cout << "---------------------------------\n";
	cout << "---------------MENI--------------\n";
	cout << "---------------------------------\n";
	cout << "\t1. Postavi razrednika\n";
	cout << "\t2. Unos ucenika u razred\n";
	cout << "\t3. Unos ocjene uceniku\n";
	cout << "\t4. Ispis razreda\n";
	cout << "\t5. Ispis razrednika\n";
	cout << "\t6. Brisanje ucenika iz razreda\n";
	cout << "\t7. Pretraga ucenika\n";
	cout << "\t8. Ispis ocjena ucenika\n";
	cout << "\t0. EXIT\n";
	cout << "Odabir: ";
	cin >> odabir;
	cin.ignore();

	return odabir;
}

void raz(Razred& razred) {
	int odabir, id;
	Ucenik ucenik;
	do
	{
		odabir = glavniMeni();
		system("cls");
		switch (odabir)
		{
		case 1:
			razred.setRazrednika();
			system("pause");
			break;
		case 2:
			cin >> ucenik;
			razred.dodajUcenikauRazred(ucenik);
			system("pause");
			break;
		case 3:
			razred.ispisUcenika();
			int pom;
			cout << "Odaberite ID ucenika sa liste kojem zelite unijeti ocjenu: ";
			cin >> pom;
			razred.unesiOcjenuUceniku(pom);
			system("pause");
			break;
		case 4:
			razred.ispisRazreda();
			system("pause");
			break;
		case 5:
			razred.ispisRazrednika();
			system("pause");
			break;
		case 6:
			razred.izbrisiUcenikaIzRazreda();
			system("pause");
			break;
		case 7:
			cout << "Unesi ID ucenika kojeg zelite pretraziti: ";
			cin >> id;
			razred.pretragaUcenika(id);
			system("pause");
			break;
		case 8:
			razred.ispisUcenika();
			int idUcenika;
			cout << "Unesite id ucenika cije ocjene zelite vidjeti: ";
			cin >> idUcenika;
			razred.ispisOcjenaUcenika(idUcenika);
			system("pause");
			break;
		case 0:
			cout << "Dovidjena! :)\n";
			break;
		default:
			cout << "ERROR\n";
			break;
		}
		cout << "---------------------------------\n";
	} while (odabir != 0);
}


int main() {
	Razred razred;
	string nazivRazreda, provjera;
	int brojUcenika, odabir;
	try
	{
		cin.ignore();
		system("pause");
		cout << "Dobrodosli u aplikaciju E-dnevnik!\n";
		system("pause");
		system("cls");
		cout << "Unesite naziv razreda: ";
		getline(cin, nazivRazreda);
		ifstream ispis("razredi.txt");
		/* while (ispis.eof()) {
			ispis >> provjera;
			if (provjera == nazivRazreda) {
				cout << "Taj razred je vec kreiran!"<<endl;
				system("pause");
			}
			else {
				*/
				ofstream unos("razredi.txt", ios::app);
				razred.setNazivRazreda(nazivRazreda);
				cout << "Kapacitet razreda: ";
				cin >> brojUcenika;
				razred.setKapacitetRazreda(brojUcenika);
				unos << razred.getNazivRazreda() << endl;
				unos.close();
				cout << "Kreiran je razred pod nazivom " << razred.getNazivRazreda() << "!\n";

				raz(razred);

			
		
	}
	catch (const char* GRESKA)
	{
		cout << "[GRESKA] " << GRESKA << endl;
	}

	return 0;
}