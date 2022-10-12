#include<iostream>
#include<string>
#include<locale>
#include <stdarg.h>
using namespace std;

 class Animal {
 protected:
	 string name;
 public:
	 
	 Animal(string name) {
		 cout << "Конструктор Животное" << endl;
		 this->name = name;
	 }

	 virtual string getInfo() {
		 return "name: "+name;
	 }

	 virtual ~Animal() {
		 cout <<"деконструктор класса животное" << endl;
	 }
};

 class Mammals : public virtual Animal {
 protected:
	 double mouthSpan;
	 string gender;
 public:

	 Mammals(string name, string gender, double mouthSpan) :Animal(name) {
		 cout << "Конструктор Млекопитающее" << endl;
		 if (gender._Equal("male") == 0 && gender._Equal("female") == 0) {
			 cout << "Нету cуществует такого гендера" << endl;
			 exit(-1);
		 }
		 this->mouthSpan= mouthSpan;
		 this->gender = gender;
		 
	 }

	 string getInfo() override {
		 return "name: "+name+", gander: "+gender + ", mouth span: " + to_string(mouthSpan) + " sm.";
	 }
	
	 void virtual milkFeed() {
		 if (gender._Equal("female")) {
			 cout << "Кормит молоком" << endl;
		 } else {
			 cout<<"Мужикая особь не может кормить молоком"<<endl;
		 }
	}

	 ~Mammals() override {

		 cout << "деконструктор класса млекопитающее" << endl;
	 }
 };

 class Lion : public Mammals {
 protected:
	 double maneSpan;
 public:

	 Lion(string name,string gender, double mouthSpan, double maneSpan) : Mammals(name, gender, mouthSpan),Animal(name){
		 cout << "Конструктор Лев" << endl;
		 this->maneSpan = maneSpan;
	 }
	 
	 string getInfo() override {
		 return "name: " + name + ", gander: " + gender + ", mouth span: " + to_string(mouthSpan) + " sm., mane span: "+ to_string(maneSpan);
	 }

	 void virtual hunt() {
		 cout << "Охотиться" << endl;
	 }

	 ~Lion() override {
		 cout << "деконструктор класса лев" << endl;
	 }

 };   

 class Bird : public virtual Animal {
 protected:
	 double  wingSpan;
 public:
	 
	 Bird(string name, double  wingSpan) :Animal(name) {
		 cout << "Конструктор Птица" << endl;
		 this->wingSpan = wingSpan;
	 }

	 string getInfo() override {
		 return  "name: "+ name + " wingspan: " + to_string(wingSpan)+" sm.";
	 }
	 
	 void virtual fly() {
		 cout << "flying " << endl;
	 }

	 ~Bird() override {
		 cout<< "деконструктор класса птица" << endl;
	 }

 };
 
class Eagle : public Bird{
protected:
	double visualAcuity;
public:
	Eagle(string name, double  wingSpan, double visialAcuity) :Bird(name, wingSpan),Animal(name){
		cout << "Конструктор Орёл" << endl;
		this->visualAcuity = visialAcuity;
	}
	
	string getInfo() override {
		return  "name: " + name + ", wingspan: " + to_string(wingSpan) + " sm., visual acuity "+to_string(visualAcuity);
	}

	void virtual beakGrinding() {
		cout << "Стачивает клюв" << endl;
	}

	~Eagle()override {
		cout << "деконструктор класса орёл" << endl;
	}
};

class Griffin : private Lion,private Eagle {
private:
	double valueOfMana;
public:
	Griffin(string name, string gender, double wingSpan, double visialAcuity,double valueOfMana): 
		Lion(name,gender,0,0),Eagle(name,wingSpan,visialAcuity),Animal(name){
		cout << "Конструктор Грифон" << endl;
		this->valueOfMana = valueOfMana;
	}
	string getInfo() override {
		return "name: " + name + ", gander: " + gender + ", wingspan: " + to_string(wingSpan) + "sm. , visual acuity: "
			+ to_string(visualAcuity) + ", value of mana: " +to_string(valueOfMana);
	}

	void fireBreathe() {
		cout <<name<< " дышит огнем " + to_string(valueOfMana / 10) + " с." << endl;
	}

	void fly() override {
		cout << name << " летает" << endl;
	}

	void hunt() override {
		cout << name << " охотиться" << endl;
	}

	void beakGrinding() override {
		cout << name << " стачивает клюв" << endl;
	}

	void milkFeed() {
		if (gender._Equal("female")) {
			cout << name<< " кормит молоком" << endl;
		}
		else {
			cout << "Мужская особь не может кормить молоком" << endl;
		}
	}

	~Griffin() override {
		cout << "деконструктор класса грифон" << endl;
	}
};

int main(){
	setlocale(LC_ALL, "rus");
	
	Griffin gr = Griffin("Griffin", "female", 70, 14, 200);
	cout<<endl<<gr.getInfo()<<endl;
	gr.getInfo();
	gr.beakGrinding();
	gr.fly();
	gr.fireBreathe();
	gr.hunt();
	gr.milkFeed();
	cout << endl;
}




























