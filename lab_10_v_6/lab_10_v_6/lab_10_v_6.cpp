#include <iostream>
#include <string>
#include <vector>

using namespace std;
template<typename T> class Ring {
private:
	vector<T> ring;
public:
	class Iterato;
	Ring() {
	}

	int find(T el) {
		auto iter = ring.begin();
		for (int i = 0; i < ring.size(); i++) {
			if (ring.at(i) == el) {
				return i;
			}
		}
		return -1;
	}

	void add(T el) {
		if (find(el) != -1) {
			throw exception("Такой элемент уже есть");
		}
		ring.push_back(el);
	}

	void remove(T el) {
		bool flag = true;
		auto iter = ring.begin();
		for (iter; iter < ring.end(); ++iter) {
			if (*iter == el) {
				ring.erase(iter);
				flag = false;
				return;
			}
		}
		if (flag) {
			cout << "Элемента '" << el <<"' нету в контейнере"<< endl;
		}
	}

	void show() {
		auto iter = ring.begin();
		for (iter; iter < ring.end(); ++iter) {
			cout << *iter << " ";
		}
		cout << endl;
	}

	Iterato end() {
		return &*(ring.end()-1);
	}

	Iterato begin() {
		return &*ring.begin();
	}


	class Iterato {
	private:
		T* cur;
	public:
		Iterato(T* first) :cur(first) {}

		T& operator++() {
			return *++cur;
		}
		
		bool operator!=(const Iterato& it) {
			return cur != it.cur+1;
		}
		bool operator==(const Iterato& it) {
			return cur == it.cur;
		}
		T& operator*() {
			return *cur;
		}
	};

};





int main() {
	setlocale(LC_ALL, "rus");
	cout.setf(ios::boolalpha);
	Ring<int> ring;
	try {
		ring.add(4);
		ring.add(5);
		ring.add(3);
		ring.add(2);
		ring.add(4);
 	} catch (exception ex){
		cout << ex.what() << endl;
	}
	ring.show();
	cout <<"ind: "<< ring.find(2) << endl;
	ring.remove(3);
	cout << "ind: " << ring.find(2) << endl;
	ring.show();
	cout << endl;

	Ring<string> ring1;
	try {
		ring1.add("one");
		ring1.add("two");
		ring1.add("three");
	} catch (exception ex){
		cout << ex.what() << endl;
	}
	ring1.show();
	cout<<"ind: "<<ring1.find("five") << endl;
	ring1.remove("one");
	cout << "ind: " << ring1.find("one") << endl;
	ring1.show();
	cout << endl;

	Ring<double> ring2;
	try {
		ring2.add(4.6);
		ring2.add(1.4);
		ring2.add(5.4);
		ring2.add(0.1);
	} catch (exception ex) {
		cout << ex.what() << endl;
	}
	ring2.show();
	cout <<"ind: "<< ring2.find(5.4) << endl;
	ring2.remove(5.5);
	cout << "ind: " << ring2.find(1.4) << endl;
	ring2.show();

	cout << endl;

	for (auto el : ring2) {
		cout << el << endl;
	}
}

