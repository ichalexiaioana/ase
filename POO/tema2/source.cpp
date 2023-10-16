#include <iostream>
using namespace std;
enum styles { none, backstroke, breaststroke, butterfly, freestyle };

class Swimmer {
private:
	char* name;				//numele sportivului
	char sex;				//sexul
	styles preferredStyle;	//stilul preferat
	int noPB;				//cati timpi inregistrati are sportivul (maxim 3)
	float* topPB;			//cei mai buni timpi in secunde la stilul preferat pe o lungime de 50m, 100m si 200m (unde se aplica)
	bool isRelayRace;		//participa la stafeta
public:
	
	Swimmer() {
		name = new char[strlen("Blank") + 1];
		strcpy(name, "Blank");
		sex = '-';
		preferredStyle = none;
		noPB = 0;
		topPB = new float[0];
		isRelayRace = false;
	}
	///////////////////////////////////////
	void afisare() {
		cout << "\n------------------";
		cout << "\nName: " << name;
		cout << "\nSex: " << sex;
		if (noPB > 0) {
			cout << "\n" << noPB << " personal bests for ";
			if(preferredStyle==freestyle)
				cout << "freestyle races are: ";
			else if (preferredStyle == backstroke)
				cout << "backstroke races are: ";
			else if (preferredStyle == breaststroke)
				cout << "breaststroke races are: ";
			else if (preferredStyle == butterfly)
				cout << "butterfly races are: ";
			for (int i = 0; i < noPB; i++)
				cout << topPB[i] << "s ";
		}
		else {
			cout << "\nNo personal bests recorded";
		}
		if (isRelayRace == true) {
			cout << "\n" << name << " participates in relay races, they swim in the ";
			if (preferredStyle == freestyle)
				cout << preferredStyle << "th position";
			else if (preferredStyle == backstroke)
				cout << preferredStyle << "st position";
			else if (preferredStyle == breaststroke)
				cout << preferredStyle << "nd position";
			else if (preferredStyle == butterfly)
				cout << preferredStyle << "rd position";
		}
		else {
			cout << "\n" << name << " doesn't participates in relay races.";
		}
		cout << "\n------------------";
	}
	///////////////////////////////////////
	void setName(const char* newName) {
		if (newName != NULL && strlen(newName) >= 2) {
			delete[] name;
			name = new char[strlen(newName) + 1];
			strcpy(name, newName);
		}
	}
	void setSex(char newSex) {
		if(newSex=='M' || newSex=='F')
			sex = newSex;
	}
	void setPB(int newNoPB, float* newTopPB, styles newPreferredStyle) {
		if (newPreferredStyle > 0) {
			if (newNoPB <= 3 && newNoPB >= 0) {
				bool ok = true;
				for (int i = 0; i < newNoPB; i++) {
					if (newTopPB[i] <= 0)
						ok = false;
				}
				if (ok == true) {
					preferredStyle = newPreferredStyle;
					noPB = newNoPB;
					delete[] topPB;
					topPB = new float[noPB];
					for (int i = 0; i < noPB; i++) {
						topPB[i] = newTopPB[i];
					}
				}
			}
		}
	}
	void setRelay(bool newIsRElayRace) {
		isRelayRace = newIsRElayRace;
	}
	///////////////////////////////////////
	const char* getName() {
		return name;
	}
	char getSex() {
		return sex;
	}
	const char* getPrefferedStyle() {
		if (preferredStyle == freestyle){
			return "freestyle";
		}
		else if (preferredStyle == backstroke){
			return "backstroke";
		}
		else if (preferredStyle == breaststroke) {
			return "breaststroke";
		}
		else if (preferredStyle == butterfly){
			return "butterfly";
		}
		
	}
	int getNoPB() {
		return noPB;
	}
	const float* getTopPB() {
		return topPB;
	}
	
	bool getRelay() {
		return isRelayRace;
	}
};

int main() {
	Swimmer s;
	Swimmer* ps;
	s.setName("David");
	s.setSex('M');
	float records[] = { 22.16, 46.86, 102.97 };
	s.setPB(3, records, butterfly);
	s.setRelay(true);
	s.afisare();
	cout << "\ngetName returns: " << s.getName();
	cout << "\ngetSex returns: " << s.getSex();
	cout << "\ngetPrefferedStyle returns: " << s.getPrefferedStyle();
	cout << "\ngetNoPB returns: " << s.getNoPB();
	cout << "\ngetTopPB returns: ";
	for (int i = 0; i < s.getNoPB(); i++) {
		cout << s.getTopPB()[i] << "s ";
	}
	cout << "\ngetRellay returns: " << s.getRelay();
	cout << "\n------------------\n";
	return 0;
}