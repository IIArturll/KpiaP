#include <iostream>
#include <string>
using namespace std;
static int COUNT = 0;
class Employe {
	friend void getInfo(Employe &emp);
	friend class Accountant;
private:		

	int id;
	string name;
	double salary;
public: 
	Employe(string name){
			this->id=COUNT++;
			this->name = name;
	}
	Employe() {
		this->id = COUNT++;
		this->name = "noName";
	}
	~Employe() {
		cout << "destructor complited"<<endl;
	}
};
 class Accountant {
 public:
	 void setSalary(Employe &employer, double salary) {
		 if (salary > 0) {
			 employer.salary = salary;
		 }
		 else
		 {
			 cout <<employer.name<<" " << "Salary cant be smoller then zero" << endl;
			 employer.salary = 0;
		 }
	 }
	 friend void getInfo(Employe& emploer) {
		 cout << "id " << emploer.id << " name " << emploer.name << " salary " << emploer.salary << endl;
	 }
	
};


int main()
{
	
	Employe emp = Employe("Tolik");
	Employe emp1 = Employe("Sasha");
	Employe emp2 = Employe("Masha");
	Accountant acc;
	
	acc.setSalary(emp1, 59);	
	acc.setSalary(emp2, -8);
	acc.setSalary(emp, 40);
	getInfo(emp);
	getInfo(emp1);
	getInfo(emp2);
	
	Employe arr[] = { emp,emp1,emp2 };
	for (auto &e : arr) {
		getInfo(e);
	}
	return 0;
}

