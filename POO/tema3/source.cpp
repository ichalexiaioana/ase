#include<iostream>
#include<string>
using namespace std;

enum Tip { EMPTY, STANDARD, ERGONOMICA, MECANICA, CABLU, BLUETOOTH };
string tipString[] = { "EMPTY", "Standard", "Ergonomica", "Mecanica", "Cablu", "Bluetooth" };

class Tastatura {
private:
	string brand;
	int numarAlfabete;
	string* alfabete;
	Tip tipuri[2];
	bool areNumpad;
public:
	Tastatura() {
		this->brand = "N/A";
		this->numarAlfabete = 0;
		this->alfabete = nullptr;
		this->tipuri[0] = Tip::EMPTY;
		this->tipuri[1] = Tip::EMPTY;
		this->areNumpad = false;
	}
	Tastatura(string brand, int numarAlfabete, string* alfabete) {
		if (brand != "")//validare brand
			this->brand = brand;
		else
			this->brand = "N/A";
		if (numarAlfabete > 0) {//validare numarAlfabete
			char ok = 1;
			for (int i = 0; i < numarAlfabete; i++) {//validare alfabete
				if (alfabete[i] == "")
					ok = 0;
			}
			if (ok != 0) {
				this->numarAlfabete = numarAlfabete;
				this->alfabete = new string[this->numarAlfabete];
				for (int i = 0; i < this->numarAlfabete; i++) {
					this->alfabete[i] = alfabete[i];
				}
			}
			else {
				this->numarAlfabete = 0;
				this->alfabete = nullptr;
			}
		}
	}
	Tastatura(const Tastatura& t) {
		if (t.brand != "")//validare brand
			this->brand = t.brand;
		else
			this->brand = "N/A";
		if (t.numarAlfabete > 0) {//validare numarAlfabete
			char ok = 1;
			for (int i = 0; i < t.numarAlfabete; i++) {//validare alfabete
				if (t.alfabete[i] == "")
					ok = 0;
			}
			if (ok != 0) {
				this->numarAlfabete = t.numarAlfabete;
				this->alfabete = new string[this->numarAlfabete];
				for (int i = 0; i < this->numarAlfabete; i++) {
					this->alfabete[i] = t.alfabete[i];
				}
			}
			else {
				this->numarAlfabete = 0;
				this->alfabete = nullptr;
			}
		}
		if (sizeof(t.tipuri) / sizeof(t.tipuri[0]) == 2) {//validare tipuri
			if ((t.tipuri[0] == STANDARD || t.tipuri[0] == ERGONOMICA || t.tipuri[0] == MECANICA) && (t.tipuri[1] == CABLU || t.tipuri[1] == BLUETOOTH)) {
				this->tipuri[0] = t.tipuri[0];
				this->tipuri[1] = t.tipuri[1];
			}
		}
		if(t.areNumpad==true || t.areNumpad==false)
			this->areNumpad = t.areNumpad;
	}
	void setTipuri(Tip newTipuri[]) {
		if (sizeof(newTipuri) / sizeof(newTipuri[0]) == 2) {//validare newTipuri
			if ((newTipuri[0] == STANDARD || newTipuri[0] == ERGONOMICA || newTipuri[0] == MECANICA) && (newTipuri[1] == CABLU || newTipuri[1] == BLUETOOTH)) {
				this->tipuri[0] = newTipuri[0];
				this->tipuri[1] = newTipuri[1];
			}
		}
	}
	void setNumpad(bool newAreNumpad) {
		this->areNumpad = newAreNumpad;
	}
	void afisare() {
		cout << "-----------";
		cout << "\nBrand: " << this->brand;
		cout << "\nNumar alfabete: " << this->numarAlfabete;
		if (this->numarAlfabete > 0)
			cout << "\nAlfabetele sunt: ";
		else
			cout << "\nNu sunt alfabete";
		for (int i = 0; i < this->numarAlfabete; i++)
			cout << this->alfabete[i] << " ";
		if (this->tipuri[0] != EMPTY && this->tipuri[1] != EMPTY)
			cout << "\nTastatura este " << tipString[this->tipuri[0]] << " si se conecteaza prin " << tipString[this->tipuri[1]];
		cout << "\nTastatura ";
		if (!areNumpad)
			cout << "nu ";
		cout << "are numpad";
		cout << "\n-----------\n";
	}
	~Tastatura() {
		delete[] this->alfabete;
		this->alfabete = nullptr;
	}
};


int main() {
	Tastatura t1;
	t1.afisare();
	Tip newTipuri[] = { Tip::ERGONOMICA, Tip::BLUETOOTH };
	string newAlfabete[] = { "Latin", "Romana" };
	string newBrand = "Logitech";
	Tastatura t2("Logitech", 2, newAlfabete);
	t2.setTipuri(newTipuri);
	t2.setNumpad(true);
	t2.afisare();
	Tastatura t3 = t2;
	t3.afisare();
	return 0;
}