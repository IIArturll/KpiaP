#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
string FileName1 = "file1.txt";
string FIleName2 = "file2.txt";
string FileName3 = "file3.bin";

class Tourist {
private:
	int idCard;
	int age;
	bool visa;
public:
	Tourist() {
		idCard = 0;
		age = 0;
		visa = 0;
	}

	Tourist(int idCard, int age, bool visa) {
		this->age = age;
		this->idCard = idCard;
		this->visa = visa;
	}

	bool isVisa() {
		return visa;
	}

	void obtainVisa() {
		visa = true;
	}

	void writeInTextFileInTextMod() {
		ofstream ofs;
		ofs.open(FileName1, ios::app);
		if (!ofs.is_open()) {
			throw exception("Ошибка открытия файла");
		}
		ofs << *this << "\n";
		ofs.close();
	}

	void writeInTextFileInBinMod() {
		ofstream ofs;
		ofs.open(FIleName2, ios::app);
		if (!ofs.is_open()) {
			throw exception("Ошибка открытия файла");
		}
		ofs.write((char*)this, sizeof(Tourist));
		ofs.close();
	}

	void writeInBinFileInBinMod() {
		ofstream o;
		o.open(FileName3, ios::app);
		o.write(reinterpret_cast<char*>(this), sizeof(Tourist));
		o.close();
	}

	static void readTextFileInTextMod() {
		ifstream fin;
		fin.open(FileName1);
		if (!fin.is_open()) {
			throw exception("Ошибка открытия файла");
		}

		string str;
		string tru = "true";
		string fals = "false";
		while (getline(fin, str)) {
			int ind = 0;
			cout << str << endl;
		}
		fin.close();
	}

	static void readTextFileInBinMod() {
		ifstream fin;
		fin.open(FIleName2);
		if (!fin.is_open()) {
			throw exception("Ошибка открытия файла");
		}
		Tourist t;
		while (fin.read((char*)&t, sizeof(Tourist)))
		{
			cout << t << endl;
		}
		fin.close();
	}

	static void readBinFileInBinMod() {
		ifstream i;
		i.open(FileName3);
		if (!i.is_open()) {
			throw exception("Ошибка открытия файла");
		}
		Tourist temp;
		while (i.read(reinterpret_cast<char*>(&temp), sizeof(Tourist))) {
			cout << temp << endl;
		}
		i.close();
	}

	static void findInAllFiles(int idCard) {
		
		if (findTxtTxt(idCard)) {
			cout << "was found in file1.txt" << endl;
		}
		if (findTxtBin(idCard)) {
			cout << "was found in file2.txt" << endl;
		}		
		if (findBinBin(idCard)) {
			cout << "was found in file3.bin" << endl;
		}
		
	}

	static bool findTxtTxt(int idCard) {
		ifstream i;
		i.open(FileName1);
		Tourist temp;
		bool flag = true;
		while (i >> temp) {
			if (temp.idCard == idCard) {
				cout << temp << endl;
				return true;
			}
		}
		return false;
	}

	static bool findTxtBin(int idCard) {
		ifstream i;
		i.open(FIleName2);
		Tourist temp;
		bool flag = true;
		while (i.read(reinterpret_cast<char*>(&temp), sizeof(temp))) {
			if (temp.idCard == idCard) {
				cout << temp << endl;
				return true;
			}
		}
		return false;
	}

	static bool findBinBin(int idCard) {
		ifstream i;
		i.open(FileName3);
		Tourist temp;
		bool flag = true;
		while (i.read(reinterpret_cast<char*>(&temp), sizeof(temp))) {
			if (temp.idCard == idCard) {
				cout << temp << endl;
				return true;
			}
		}
		return false;
	}

	static void deleteObjInAllFiles(int idCard) {
		deleteObjTxtTxt(idCard);
		deleteObjTxtBin(idCard);
		deleteObjBinBin(idCard);
	}

	static void deleteObjTxtTxt(int idCard) {
		if (findTxtTxt(idCard)) {
			ifstream i;
			ofstream o1;
			i.open(FileName1);
			o1.open(FileName1 + ".tmp",ios::app);
			if (!i.is_open() or !o1.is_open()) {
				throw exception("Ошибка открытия файла");
			}
			Tourist t;
			while (i>>t) {
				if (t.idCard != idCard) {
					o1 << t <<"\n";
				}
			}
			i.close();
			o1.close();
			remove("file1.txt");
			rename("file1.txt.tmp", "file1.txt");
		}
	}

	static void deleteObjTxtBin(int idCard) {
		if (findTxtBin(idCard)) {
			ifstream i;
			ofstream o1;
			i.open(FIleName2);
			o1.open(FIleName2 + ".tmp");
			if (!i.is_open() or !o1.is_open()) {
				throw exception("Ошибка открытия файла");
			}
			Tourist t;
			while (i.read(reinterpret_cast<char*>(&t),sizeof(t))) {
				if (t.idCard != idCard) {
					o1.write(reinterpret_cast<char*>(&t), sizeof(t));
				}
			}
			i.close();
			o1.close();
			remove("file2.txt");
			rename("file2.txt.tmp", "file2.txt");
		}
	}

	static void deleteObjBinBin(int idCard) {
		if (findBinBin(idCard)) {
			ifstream i;
			ofstream o1;
			i.open(FileName3);
			o1.open(FileName3 + ".tmp");
			if (!i.is_open() or !o1.is_open()) {
				throw exception("Ошибка открытия файла");
			}
			Tourist t;
			while (i.read(reinterpret_cast<char*>(&t), sizeof(t))) {
				if (t.idCard != idCard) {
					o1.write(reinterpret_cast<char*>(&t), sizeof(t));
				}
			}
			i.close();
			o1.close();
			remove("file3.bin");
			rename("file3.bin.tmp", "file3.bin");
		}
	}

	friend ostream& operator<<(ostream& os, Tourist& tourist) {
		os << tourist.idCard << " " << tourist.age << " " << tourist.visa;
		return os;
	}

	friend istream& operator>>(istream& in, Tourist& tourist) {
		in >> tourist.idCard >> tourist.age >> tourist.visa;
		return in;
	}
};

int main() {

	setlocale(LC_ALL, "rus");
	cout.setf(ios::boolalpha);

	vector<Tourist> arr{
		Tourist(1,10,true),
		Tourist(2,15,false),
		Tourist(3,20,false),
		Tourist(4,40, true),
		Tourist(5,35,true),
		Tourist(6,23,true)
	};

	try {
		for (auto el : arr) {
				el.writeInTextFileInTextMod();
				el.writeInTextFileInBinMod();
			    el.writeInBinFileInBinMod();
		}

		cout << "----------show-------------" << endl;
		
		cout << "Text file text mode" << endl;
		Tourist::readTextFileInTextMod();
		cout << endl;

		cout << "Text file bin mode" << endl;
		Tourist::readTextFileInBinMod();
		cout << endl;

		cout << "Bin file bin mode" << endl;
		Tourist::readBinFileInBinMod();
		cout << endl;

		cout << "----------finding-------------" << endl;

		Tourist::findInAllFiles(1);

		cout << "----------deleting-------------" << endl;

		Tourist::deleteObjInAllFiles(1);

		cout << "----------show-------------" << endl;

		cout << "Text file text mode" << endl;
		Tourist::readTextFileInTextMod();
		cout << endl;

		cout << "Text file bin mode" << endl;
		Tourist::readTextFileInBinMod();
		cout << endl;

		cout << "Bin file bin mode" << endl;
		Tourist::readBinFileInBinMod();
		cout << endl;

	} catch (exception ex) {
		cout << ex.what();
	}
}

