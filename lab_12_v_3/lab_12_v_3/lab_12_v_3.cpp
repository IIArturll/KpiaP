#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string path1 = "file1.txt";
string path2 = "file2.txt";
string subStr;
int search(string str);
void readAndWrite() {
	try {
		fstream file1;
		fstream file2;
		file1.open(path1);
		cout << path1 << " успешно открыт" << endl;
		file2.open(path2, ios::app);
		cout << path2 << " успешно открыт" << endl;
		string str;
		int countStr = 1;
		while (getline(file1, str)) {
			cout << "Считана строка " << countStr++ <<" : "<<str<< endl;
			
			int count = search(str);

			file2 << count << "\n";
			cout << "записано в файл " << count << endl;
		}
		file1.close();
		cout << path1 << " успешно закрыт" << endl;

		file2.close();
		cout << path2 << " успешно закрыт" << endl;
	} catch (exception ex) {
		cout << ex.what() << endl;
		cout << "ошибка открытия файла" << endl;
	}	
}

int search(string str) {
	int count = 0;
	for (int i = 0; i < str.length();)
	{
		int ind1 = -1;
		if ((ind1 = str.rfind(" ")) == -1) {
			break;
		}
		auto s1 = str.substr(ind1 + 1);
		if (s1.find(subStr) != -1) {
			count++;
			cout << "найдено вхождение подстроки " << subStr << " в слове " << s1 << endl;
		}
		str.erase(ind1);
	}
	if (str.find(subStr) != -1) {
		count++;
		cout << "найдено вхождение подстроки " << subStr << " в слове " << str << endl;
	}
	return count;
}

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Enter string for searching" << endl;
	cin >> subStr;
	readAndWrite();
}