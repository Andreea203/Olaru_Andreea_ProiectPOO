#include<iostream>
using namespace std;
//Andreea Maria Olaru - Mall

class Magazine {
private:
	static int nrInventar;
	const int nrTotalMagazine;
	string numeFirma;
	float suprafata;
	int nrArticole;
	string* numeArticole;
public:
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

	Magazine(const Magazine& m) : nrTotalMagazine(nrInventar++) {
		this->numeFirma = m.numeFirma;
		this->suprafata = m.suprafata;
		this->nrArticole = m.nrArticole;
		this->numeArticole = new string[m.nrArticole];
		for (int i = 0; i < m.nrArticole; i++) {
			this->numeArticole[i] = m.numeArticole[i];
		}
	}

	Magazine operator=(const Magazine& mg) {
		if (this != &mg) {
			this->numeFirma = mg.numeFirma;
			this->suprafata = mg.suprafata;
			this->nrArticole = mg.nrArticole;
			if (this->numeArticole != NULL) {
				delete[]this->numeArticole;
			}
			this->numeArticole = new string[mg.nrArticole];
			for (int i = 0; i < mg.nrArticole; i++) {
				this->numeArticole[i] = mg.numeArticole[i];
			}
		}
		return *this;
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

	void adaugareArticol(string numeArticol) {
		string* aux = new string[this->nrArticole + 1];
		for (int i = 0; i < this->nrArticole; i++) {
			aux[i] = this->numeArticole[i];
		}
		aux[this->nrArticole] = numeArticol;
		this->nrArticole++;
		if (this->numeArticole) {
			delete[]this->numeArticole;
		}
		this->numeArticole = aux;
	}

	int getNrTotalMagazine() {
		return nrTotalMagazine;
	}

	void setArticole(int nrArticole, string* numeArticole) {
		if (nrArticole > 0) {
			this->nrArticole = nrArticole;
			if (this->numeArticole != NULL) {
				delete[]this->numeArticole;
			}
			this->numeArticole = new string[nrArticole];
			for (int i = 0; i < nrArticole; i++) {
				this->numeArticole[i] = numeArticole[i];
			}
		}
	}

	string getNumeFirma() {
		return numeFirma;
	}
	void setNumeFirma(string numeFirma) {
		if (this->numeFirma.length() > 0) {
			this->numeFirma = numeFirma;
		}
	}

	float getSuprafata() {
		return suprafata;
	}
	void setSuprafata(float suprafata) {
		if (suprafata > 0) {
			this->suprafata = suprafata;
		}
	}

	int getNrArticole() {
		return nrArticole;
	}
	void setNrArticole(int nrArticole) {
		if (nrArticole > 0) {
			this->nrArticole = nrArticole;
		}
	}

	string* getNumeArticole() {
		return numeArticole;
	}
	string getNumeArticol(int i) {
		if (i >= 0 && i < nrArticole) {
			return numeArticole[i];
		}
	}

	friend string getArticole(const Magazine& m);
};
int Magazine::nrInventar = 100;

string getArticole(const Magazine& m) {
	string aux = ", ";
	for (int i = 0; i < m.nrArticole; i++) {
		aux += m.numeArticole[i] + ", ";
	}
	return aux;
}

class Angajati {
private:
	static int idAngajat;
	const int nrMaximZileConcediu;
	string uniforma;
	float salariu;
	int nrAngajati;
	string* numeAngajati;
public:
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

	Angajati(const Angajati& a) : nrMaximZileConcediu(idAngajat++) {
		this->uniforma = a.uniforma;
		this->salariu = a.salariu;
		this->nrAngajati = a.nrAngajati;
		this->numeAngajati = new string[a.nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->numeAngajati[i] = numeAngajati[i];
		}
	}

	Angajati operator=(const Angajati& a) {
		if (this != &a) {
			this->uniforma = a.uniforma;
			this->salariu = a.salariu;
			this->nrAngajati = a.nrAngajati;
			if (this->numeAngajati != NULL) {
				delete[]this->numeAngajati;
			}
			this->numeAngajati = new string[a.nrAngajati];
			for (int i = 0; i < a.nrAngajati; i++) {
				this->numeAngajati[i] = a.numeAngajati[i];
			}
		}
		return *this;
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

	void adaugareAngajat(string numeAngajat) {
		string* aux = new string[this->nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->numeAngajati[i];
		}
		aux[this->nrAngajati] = numeAngajat;
		this->nrAngajati++;
		if (this->numeAngajati) {
			delete[]this->numeAngajati;
		}
		this->numeAngajati = aux;
	}

	int getNrMaximZileConcediu() {
		return nrMaximZileConcediu;
	}

	void setAngajati(int nrAngajati, string* numeAngajati) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->numeAngajati != NULL) {
				delete[]this->numeAngajati;
			}
			this->numeAngajati = new string[nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->numeAngajati[i] = numeAngajati[i];
			}
		}
	}

	string getUniforma() {
		return uniforma;
	}
	void setUniforma(string uniforma) {
		if (this->uniforma.length() > 0) {
			this->uniforma = uniforma;
		}
	}

	float getSalariu() {
		return salariu;
	}
	void setSalariu(float salariu) {
		if (salariu > 0) {
			this->salariu = salariu;
		}
	}

	int getNrAngajati() {
		return nrAngajati;
	}
	void setNrAngajati(int nrAngajati) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
		}
	}

	string* getNumeAngajati() {
		return numeAngajati;
	}
	string getNumeAngajat(int i) {
		if (i >= 0 && i < nrAngajati) {
			return numeAngajati[i];
		}
	}
	friend string getSirAngajati(const Angajati& an);
}; 
int Angajati::idAngajat = 200;

string getSirAngajati(const Angajati& an) {
	string aux = ", ";
	for (int i = 0; i < an.nrAngajati; i++) {
		aux += an.numeAngajati[i] + ", ";
	}
	return aux;
}

class Produse {
private:
	static int nrInventar;
	const int TVA;
	int pret;
	float greutate;
	int cantitate;
	string* numeProduse;
public:
	static int getNrInventar() {
		return nrInventar;
	}

	Produse() : TVA(nrInventar++) {
		this->pret = 160;
		this->greutate = 2;
		this->cantitate = 2;
		this->numeProduse= new string[cantitate];
		for (int i = 0; i < cantitate; i++) {
			this->numeProduse[i] = numeProduse[i];
			numeProduse[0] = "rochie";
			numeProduse[1] = "hanorac";
		}
	}

	Produse(int pret, float greutate) : TVA(nrInventar) {
		nrInventar++;
		this->pret = pret;
		this->greutate = greutate;
		this->cantitate = 2;
		this->numeProduse = new string[cantitate];
		for (int i = 0; i < cantitate; i++) {
			this->numeProduse[i] = numeProduse[i];
			numeProduse[0] = "fusta";
			numeProduse[1] = "tricou";
		}
	}

	Produse(int pret, float greutate, int cantitate, string* numeProduse) : TVA(nrInventar) {
		nrInventar++;
		this->pret = pret;
		this->greutate = greutate;
		this->cantitate = cantitate;
		this->numeProduse = new string[cantitate];
		for (int i = 0; i < cantitate; i++) {
			this->numeProduse[i] = numeProduse[i];
		}
	}

	Produse(const Produse& p) : TVA(nrInventar++) {
		this->pret = p.pret;
		this->greutate = p.greutate;
		this->cantitate = p.cantitate;
		this->numeProduse = new string[p.cantitate];
		for (int i = 0; i < p.cantitate; i++) {
			this->numeProduse[i] = p.numeProduse[i];
		}
	}

	Produse operator=(const Produse& p) {
		if (this != &p) {
			this->pret = p.pret;
			this->greutate = p.greutate;
			this->cantitate = p.cantitate;
			if (this->numeProduse != NULL) {
				delete[]this->numeProduse;
			}
			this->numeProduse = new string[p.cantitate];
			for (int i = 0; i < p.cantitate; i++) {
				this->numeProduse[i] = p.numeProduse[i];
			}
		}
		return *this;
	}

	~Produse() {
		if (this->numeProduse != NULL) {
			delete[]this->numeProduse;
		}
	}

	void afisareProdus() {
		cout << "Produsele au un pret de " << pret << " lei, au o greutate de " << greutate << " kg, se afla intr-o cantitate de " << cantitate << " si au denumirile de: ";
		if (cantitate > 0) {
			for (int i = 0; i < cantitate; i++) {
				cout << numeProduse[i] << ", ";
			}
		}
		else {
			cout << "nu exista produse.";
		}
		cout << endl;
	}

	void adaugareProdus(string numeProdus) {
		string* aux = new string[this->cantitate + 1];
		for (int i = 0; i < this->cantitate; i++) {
			aux[i] = this->numeProduse[i];
		}
		aux[this->cantitate] = numeProdus;
		this->cantitate++;
		if (this->numeProduse) {
			delete[]this->numeProduse;
		}
		this->numeProduse = aux;
	}

	int getTVA() {
		return TVA;
	}
	void setProduse(int cantitate, string* numeProduse) {
		if (cantitate > 0) {
			this->cantitate = cantitate;
			if (this->numeProduse != NULL) {
				delete[]this->numeProduse;
			}
			this->numeProduse = new string[cantitate];
			for (int i = 0; i < cantitate; i++) {
				this->numeProduse[i] = numeProduse[i];
			}
		}
	}

	int getPret() {
		return pret;
	}
	void setPret(int pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}

	float getGreutate() {
		return greutate;
	}
	void setGreutate(float greutate) {
		if (greutate > 0) {
			this->greutate = greutate;
		}
	}

	int getCantitate() {
		return cantitate;
	}
	void setCantitate(int cantitate) {
		if (cantitate > 0) {
			this->cantitate = cantitate;
		}
	}

	string* getNumeProduse() {
		return numeProduse;
	}
	string getNumeProdus(int i) {
		if (i >= 0 && i < cantitate) {
			return numeProduse[i];
		}
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
	magazin2.adaugareArticol("geci");
	magazin2.afisareMagazine();

	Magazine magazin3("Adidas", 35, 3, numeArticole);
	magazin3.afisareMagazine();

	/*cout << magazin2.getNrInventar() << endl;*/
	cout << Magazine::getNrInventar() << endl;
	Magazine m1 = magazin2;
	Magazine m2(magazin2);
	magazin2.afisareMagazine();
	m1 = magazin2;
	m1.afisareMagazine();
	cout << m1.getNrTotalMagazine() << endl;
	cout << m1.getNumeFirma() << endl;
	m1.setNumeFirma("Puma");
	cout << m1.getNumeFirma() << endl;
	cout << m1.getSuprafata() << endl;
	m1.setSuprafata(40);
	cout << m1.getSuprafata() << endl;
	cout << m1.getNrArticole() << endl;
	m1.setNrArticole(7);
	cout << m1.getNrArticole() << endl;

	string* vector = new string[2]{ "sepci","palarii" };
	m1.setArticole(2, vector);
	m1.afisareMagazine();
	cout << *m1.getNumeArticole()<< endl;
	/*cout << m1.getNumeArticole() << endl;*/
	cout << m1.getNumeArticol(1) << endl;
	delete[]vector;
	/*cout << getArticole(m1);*/
	cout << endl;

	Angajati angajat1;
	angajat1.afisareAngajati();

	Angajati angajat2("camasa", 2800);
	angajat2.afisareAngajati();
	angajat2.adaugareAngajat("Ioana");
	angajat2.afisareAngajati();

	string* numeAngajati = new string[3];
	numeAngajati[0] = "Alex";
	numeAngajati[1] = "Andrei";
	numeAngajati[2] = "Maria";

	Angajati angajat3("camasa", 3000, 3, numeAngajati);
	angajat3.afisareAngajati();

	cout << Angajati::getIdAngajat() << endl; 
	Angajati a1 = angajat2;
	Angajati a2(angajat2);
	angajat2.afisareAngajati();
	cout << a1.getNrMaximZileConcediu() << endl;
	cout << a1.getUniforma() << endl;
	a1.setUniforma("costum");
	cout << a1.getUniforma() << endl;
	cout << a1.getSalariu() << endl;
	a1.setSalariu(4000);
	cout << a1.getSalariu() << endl;
	cout << a1.getNrAngajati() << endl;
	a1.setNrAngajati(2);
	cout << a1.getNrAngajati() << endl;

	string* vector1= new string[2]{ "Ana", "Raluca" };
	a1.setAngajati(2, vector1);
	a1.afisareAngajati();
	cout << *a1.getNumeAngajati() << endl;
	/*cout << a1.getNumeAngajati() << endl; */
	cout << a1.getNumeAngajat(1) << endl;
	delete[]vector1;
	/*cout << getSirAngajati(a1);*/
	cout << endl;

	Produse produs1;
	produs1.afisareProdus();

	Produse produs2(120, 1);
	produs2.afisareProdus();
	produs2.adaugareProdus("pantaloni");
	produs2.afisareProdus();

	string* numeProduse = new string[3];
	numeProduse[0] = "geaca";
	numeProduse[1] = "blugi";
	numeProduse[2] = "adidasi";

	Produse produs3(150, 3, 3, numeProduse);
	produs3.afisareProdus();

	cout << Produse::getNrInventar() << endl;
	Produse p1 = produs2;
	Produse p2(produs2);
	produs2.afisareProdus();
	cout << p1.getTVA() << endl;
	cout << p1.getPret() << endl;
	p1.setPret(250);
	cout << p1.getPret() << endl;
	cout << p1.getGreutate() << endl;
	p1.setGreutate(5);
	cout << p1.getGreutate() << endl;
	cout << p1.getCantitate() << endl;
	p1.setCantitate(4);
	cout << p1.getCantitate() << endl;

	string* vector2 = new string[4] {"adidasi", "palarii", "sacouri", "tricouri"};
	p1.setProduse(4, vector2);
	p1.afisareProdus();
	cout << *p1.getNumeProduse() << endl;
	//cout << p1.getNumeProduse() << endl;
	cout << p1.getNumeProdus(1) << endl;
	delete[]vector2;
}