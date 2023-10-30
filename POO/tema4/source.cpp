#include <iostream>
using namespace std;
enum tipuriTricou {NONAME, CREWNECK, VNECK, POLO, SLEEVELESS, LONGSLEEVE};
string tipString[] = { "NONAME", "CREWNECK", "VNECK", "POLO", "SLEEVELESS", "LONGSLEEVE"};

class Tricou {
private:
	tipuriTricou tip = tipuriTricou::NONAME;
	const int ID;
	float pret = 0;
	int nrMarimi = 0;
	string* marimi = nullptr;
	static float TVA;
	static int nrTricouri;
public:
	Tricou(int ID) :ID(ID) {
		Tricou::nrTricouri++;
	}
	Tricou(int ID, tipuriTricou tip, float pret) :ID(ID){
		this->tip = tip;
		if (pret > 0)
			this->pret = pret + Tricou::TVA * pret;
		Tricou::nrTricouri++;
	}
	Tricou(const Tricou& t) :ID(t.ID) {
		this->tip = t.tip;
		this->pret = t.pret;
		if (t.nrMarimi > 0 && t.marimi != nullptr) {
			this->nrMarimi = t.nrMarimi;
			this->marimi = new string[this->nrMarimi];
			for (int i = 0; i < this->nrMarimi; i++)
				this->marimi[i] = t.marimi[i];
		}
		Tricou::nrTricouri++;
	}
	void operator=(const Tricou& t) {
		delete[] this->marimi;
		this->marimi = nullptr;

		this->tip = t.tip;
		this->pret = t.pret;
		if (t.nrMarimi > 0 && t.marimi != nullptr) {
			this->nrMarimi = t.nrMarimi;
			this->marimi = new string[this->nrMarimi];
			for (int i = 0; i < this->nrMarimi; i++)
				this->marimi[i] = t.marimi[i];
		}
		else {
			delete[] this->marimi;
			this->marimi = nullptr;
		}
	}
	void setTip(tipuriTricou tip) {
		this->tip = tip;
	}
	void addMarimi(int nrMarimiExtra, string* marimiExtra) {
		if (nrMarimiExtra > 0) {
			string* newMarimi = new string[this->nrMarimi + nrMarimiExtra];
			for (int i = 0; i < nrMarimi; i++)
				newMarimi[i] = this->marimi[i];
			for (int i = 0; i < nrMarimiExtra; i++)
				newMarimi[i+this->nrMarimi] = marimiExtra[i];
			this->nrMarimi += nrMarimiExtra;
			delete[] this->marimi;
			this->marimi = nullptr;
			this->marimi = newMarimi;
		}
	}
	static int getNrTricouri() {
		return Tricou::nrTricouri;
	}
	void afisare() {
		cout << "\n--------------";
		cout << "\nTip tricou: " << tipString[this->tip];
		cout << "\nID: " << this->ID;
		cout << "\nPret: " << this->pret;
		cout << "\nNumar marimi: " << this->nrMarimi;
		cout << "\nMarimi: ";
		for (int i = 0; i < this->nrMarimi; i++)
			cout << this->marimi[i]<<" ";
		cout << "\n-------------";
	}
	~Tricou() {
		delete[] this->marimi;
		this->marimi = nullptr;
		Tricou::nrTricouri--;
	}
};
float Tricou::TVA = 0.2;
int Tricou::nrTricouri = 0;

int main() {
	Tricou t1(54);
	t1.setTip(SLEEVELESS);
	t1.afisare();
	cout << "\n>NUMARUL CURENT DE TRICOURI:" << Tricou::getNrTricouri();

	Tricou* t2 = new Tricou(8, POLO, 5);
	t2->afisare();
	cout << "\n>NUMARUL CURENT DE TRICOURI:" << Tricou::getNrTricouri();

	Tricou t3(32, CREWNECK, 10);
	string marimi3[] = { "XS", "S", "M"};
	t3.addMarimi(3, marimi3);
	t3.afisare();
	cout << "\n>NUMARUL CURENT DE TRICOURI:" << Tricou::getNrTricouri();
	


	Tricou t4(26, LONGSLEEVE, 15);
	string marimi4[] = { "L", "XL" };
	t4.addMarimi(2, marimi4);
	t4.setTip(LONGSLEEVE);
	t4.afisare();
	cout << "\n>NUMARUL CURENT DE TRICOURI:" << Tricou::getNrTricouri();

	delete t2;
	cout << "\n>NUMARUL CURENT DE TRICOURI:" << Tricou::getNrTricouri();

	t4 = t3;//apel supraincarcarea opertor =
	t4.afisare();
	cout << "\n>NUMARUL CURENT DE TRICOURI:" << Tricou::getNrTricouri();

	
	return 0;
}