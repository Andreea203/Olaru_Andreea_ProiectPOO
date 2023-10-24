#include<iostream>
using namespace std;
//Andreea Maria Olaru - Mall

class Magazine {
public:
	static int nrInventar;
	const int nrTotalMagazine;
	string numeFirma;
	float suprafata;
	int nrArticole;
	string* numeArticole;

	static int getNrInventar() {
		return nrInventar;
	}

	Magazine() : nrTotalMagazine(nrInventar++) {
		this->numeFirma = "Zara";
		this->suprafata = 25;
		this->nrArticole = 4;
		this->numeArticole = new string[nrArticole];
		for (int i = 0; i < nrArticole; i++) {
			this->numeArticole[i] = numeArticole[i];
			numeArticole[0] = "tricouri";
			numeArticole[1] = "pantaloni";
			numeArticole[2] = "rochii";
			numeArticole[3] = "fuste";
		}
	}

	Magazine(string numeFirma, float suprafata) : nrTotalMagazine(nrInventar) {
		nrInventar++;
		this->numeFirma = numeFirma;
		this->suprafata = suprafata;
		this->nrArticole = 2;
		this->numeArticole = new string[nrArticole];
		for (int i = 0; i < nrArticole; i++) {
			this->numeArticole[i] = numeArticole[i];
			numeArticole[0] = "hanorace";
			numeArticole[1] = "adidasi";
		}
	}

	Magazine(string numeFirma, float suprafata, int nrArticole, string* numeArticole) : nrTotalMagazine(nrInventar) {
		nrInventar++;
		this->numeFirma = numeFirma;
		this->suprafata = suprafata;
		this->nrArticole = nrArticole;
		this->numeArticole = new string[nrArticole];
		for (int i = 0; i < nrArticole; i++) {
			this->numeArticole[i] = numeArticole[i];
		}
	}

	~Magazine() {
		if (this->numeArticole != NULL) {
			delete[]this->numeArticole;
		}
	}

	void afisareMagazine() {
		cout << "Magazinul " << numeFirma << " , cu suprafata de " << suprafata << " m^2, are " << nrArticole << " tipuri de articole vestimentare, si anume: ";
		if (nrArticole > 0) {
			for (int i = 0; i < nrArticole; i++) {
				cout << numeArticole[i] << ", ";
			}
		}
		else {
			cout << " inca nu are articole.";
		}
		cout << endl;
	}
};
int Magazine::nrInventar = 100;

class Angajati {
public:
	static int idAngajat;
	const int nrMaximZileConcediu;
	string uniforma;
	float salariu;
	int nrAngajati;
	string* numeAngajati;

	static int getIdAngajat() {
		return idAngajat;
	}

	Angajati() : nrMaximZileConcediu(idAngajat++) {
		this->uniforma = "rochie";
		this->salariu = 2600;
		this->nrAngajati = 2;
		this->numeAngajati = new string[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->numeAngajati[i] = numeAngajati[i];
			numeAngajati[0] = "Ioana";
			numeAngajati[1] = "Alexia";
		}
	}

	Angajati(string uniforma, float salariu) : nrMaximZileConcediu(idAngajat) {
		idAngajat++;
		this->uniforma = uniforma;
		this->salariu = salariu;
		this->nrAngajati = 4;
		this->numeAngajati = new string[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->numeAngajati[i] = numeAngajati[i];
			numeAngajati[0] = "George";
			numeAngajati[1] = "Laura";
			numeAngajati[2] = "Razvan";
			numeAngajati[3] = "Daniel";
		}
	}

	Angajati(string uniforma, float salariu, int nrAngajati, string* numeAngajati) : nrMaximZileConcediu(idAngajat) {
		idAngajat++;
		this->uniforma = uniforma;
		this->salariu = salariu;
		this->nrAngajati = nrAngajati;
		this->numeAngajati = new string[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->numeAngajati[i] = numeAngajati[i];
		}
	}

	~Angajati() {
		if (this->numeAngajati != NULL) {
			delete[]this->numeAngajati;
		}
	}

	void afisareAngajati() {
		cout << "Angajatii au ca si uniforma: " << uniforma << ", au un salariu de " << salariu << " lei, sunt in numar de " << nrAngajati << " si se numesc: ";
		if (nrAngajati > 0) {
			for (int i = 0; i < nrAngajati; i++) {
				cout << numeAngajati[i] << ", ";
			}
		}
		else {
			cout << "nu exista angajati.";
		}
		cout << endl;
	}
}; 
int Angajati::idAngajat = 200;

class Produse {
public:
	static int nrInventar;
	const int TVA;
	int pret;
	float greutate;
	int cantitate;
	string* numeProdus;

	static int getNrInventar() {
		return nrInventar;
	}

	Produse() : TVA(nrInventar++) {
		this->pret = 160;
		this->greutate = 2;
		this->cantitate = 2;
		this->numeProdus = new string[cantitate];
		for (int i = 0; i < cantitate; i++) {
			this->numeProdus[i] = numeProdus[i];
			numeProdus[0] = "rochie";
			numeProdus[1] = "hanorac";
		}
	}

	Produse(int pret, float greutate) : TVA(nrInventar) {
		nrInventar++;
		this->pret = pret;
		this->greutate = greutate;
		this->cantitate = 2;
		this->numeProdus = new string[cantitate];
		for (int i = 0; i < cantitate; i++) {
			this->numeProdus[i] = numeProdus[i];
			numeProdus[0] = "fusta";
			numeProdus[1] = "tricou";
		}
	}

	Produse(int pret, float greutate, int cantitate, string* numeProdus) : TVA(nrInventar) {
		nrInventar++;
		this->pret = pret;
		this->greutate = greutate;
		this->cantitate = cantitate;
		this->numeProdus = new string[cantitate];
		for (int i = 0; i < cantitate; i++) {
			this->numeProdus[i] = numeProdus[i];
		}
	}

	~Produse() {
		if (this->numeProdus != NULL) {
			delete[]this->numeProdus;
		}
	}

	void afisareProdus() {
		cout << "Produsele au un pret de " << pret << " lei, au o greutate de " << greutate << " kg, se afla intr-o cantitate de " << cantitate << " si au denumirile de: ";
		if (cantitate > 0) {
			for (int i = 0; i < cantitate; i++) {
				cout << numeProdus[i] << ", ";
			}
		}
		else {
			cout << "nu exista produse.";
		}
		cout << endl;
	}
};
int Produse::nrInventar = 300;

void main() {
	Magazine magazin1;
	magazin1.afisareMagazine();

	string* numeArticole = new string[3];
	numeArticole[0] = "tricouri";
	numeArticole[1] = "pantaloni";
	numeArticole[2] = "veste";

	Magazine magazin2("Nike", 30);
	magazin2.afisareMagazine();

	Magazine magazin3("Adidas", 35, 3, numeArticole);
	magazin3.afisareMagazine();

	/*cout << magazin2.getNrInventar() << endl;*/
	cout << Magazine::getNrInventar() << endl;
	cout << endl;

	Angajati angajat1;
	angajat1.afisareAngajati();

	Angajati angajat2("camasa", 2800);
	angajat2.afisareAngajati();

	string* numeAngajati = new string[3];
	numeAngajati[0] = "Alex";
	numeAngajati[1] = "Andrei";
	numeAngajati[2] = "Maria";

	Angajati angajat3("camasa", 3000, 3, numeAngajati);
	angajat3.afisareAngajati();

	cout << Angajati::getIdAngajat() << endl; 
	cout << endl;

	Produse produs1;
	produs1.afisareProdus();

	Produse produs2(120, 1);
	produs2.afisareProdus();

	string* numeProdus = new string[3];
	numeProdus[0] = "geaca";
	numeProdus[1] = "blugi";
	numeProdus[2] = "adidasi";

	Produse produs3(150, 3, 3, numeProdus);
	produs3.afisareProdus();

	cout << Produse::getNrInventar() << endl;
}