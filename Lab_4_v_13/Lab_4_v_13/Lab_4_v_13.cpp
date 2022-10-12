#include <iostream>
#include<string>
#include<locale>
#include <stdarg.h>

using namespace std;

class Animal {
protected:
    string name;
public:
	Animal(string name) {
		cout << "конструктор животное" << endl;
		this->name = name;
	}
	virtual string getInfo() = 0;
	
	virtual double getSpeed() = 0;

	virtual ~Animal() {
		cout << "деконструктор животное" << endl;
	}
};


class Lion : public Animal {
protected:
	double maneSpan;
	double legStrenthH;
public:

	Lion(string name, double maneSpan,double legStrenthH) : Animal(name) {
		cout << "Конструктор Лев" << endl;
		this->maneSpan = maneSpan;
		this->legStrenthH = legStrenthH;
	}

	string getInfo() override {
		return "name: " + name + ", mane span: " + to_string(maneSpan)+", leg strenth "+to_string(legStrenthH)+" H.";
	}

	double getSpeed() override {
		return (legStrenthH / 4)/20;
	}

	void virtual hunt() {
		cout << "Охотится" << endl;
	}

	~Lion() override {
		cout << "деконструктор класса лев" << endl;
	}

};

class Bird : public Animal {
protected:
	double  wingSpan;
	int coutFlapsPM;
public:

	Bird(string name, double  wingSpan,int coutFlapsPM) :Animal(name) {
		cout << "Конструктор Птица" << endl;
		this->wingSpan = wingSpan;
		this->coutFlapsPM = coutFlapsPM;
	}


	string getInfo() override {
		return  "name: " + name + " wingspan: " + to_string(wingSpan) + " sm., count flaps p/s "+to_string(coutFlapsPM);
	}

	double getSpeed() override {
		return coutFlapsPM / 60 * wingSpan;
	}

	void virtual fly() {
		cout << "flying " << endl;
	}

	~Bird() override {
		cout << "деконструктор класса птица" << endl;
	}
};

class Eagle : public Bird {
protected:
	double visualAcuity;
	int secOfPlanning;
public:
	Eagle(string name, double  wingSpan, double visialAcuity,int coutFlapsPM,int secOfPlanning) :Bird(name, wingSpan,coutFlapsPM){
		cout << "Конструктор Орёл" << endl;
		this->visualAcuity = visialAcuity;
		this->secOfPlanning = secOfPlanning;
	}

	string getInfo() override {
		return  "name: " + name + ", wingspan: " + to_string(wingSpan) + " sm., cout flaps p/s "+to_string(coutFlapsPM)+", visual acuity " 
			+ to_string(visualAcuity) + ", second of planning "+to_string(secOfPlanning);
	}

	double getSpeed() override {
		return coutFlapsPM / 60 * visualAcuity + secOfPlanning * 3;
	}

	void virtual beakGrinding() {
		cout << "Стачивает клюв" << endl;
	}

	~Eagle()override {
		cout << "деконструктор класса орёл" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	Animal* bird = new Bird("bird", 20, 60);
	Animal* eagle = new Eagle("eagle", 60, 13, 50, 20);
	Animal* lion = new Lion("lion", 40, 1500);
	Animal* animals[] = { bird,eagle,lion };
	for (int i = 0; i < 3; i++)
	{
		cout << endl << animals[i]->getInfo() << endl;
		cout << "metrov v sec " << animals[i]->getSpeed() << endl;
	}
	
	for (int i = 0; i < 3; i++){
		delete animals[i];
	}
	
}

