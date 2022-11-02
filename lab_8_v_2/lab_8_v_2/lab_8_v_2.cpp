#include <iostream>
#include <exception>
#include <string>
#include <iomanip>
#include <conio.h>

using namespace std;

const int MAX = 50;

class MatrixException : public exception
{
private:
	string m_error;
public:
	MatrixException(string error) : m_error(error)
	{
	}
	const char* what() const noexcept { return m_error.c_str(); }
};

class Matrix
{
private:

	int sizeCol;
	int sizeRow;
	int** arr;

public:
	Matrix()
	{
		arr = nullptr;
		sizeCol = 0;
		sizeRow = 0;
	}

	Matrix(int col, int row) {
		if (col <= 0 || row <= 0 || col>MAX || row>MAX) {
			throw MatrixException("Uncorrect size of array!\n");
		}
		arr = nullptr;
		sizeCol = col;
		sizeRow = row;
	}

	Matrix(int** arrFromCopy, int sizeC, int sizeR)
	{
		if (arrFromCopy == nullptr)
			throw MatrixException("Matrix is empty!\n");
		if ((sizeC <= 0 or sizeC >= MAX) or (sizeR <= 0 or sizeR >= MAX))
			throw MatrixException("Uncorrect size of array!\n");
		arr = new int* [sizeC];

		for (int i = 0; i < sizeC; i++) {
			if (!(arr[i] = new int[sizeR])) {
				throw MatrixException("Error of memory allocation!\n");
			}
		}

		for (int x = 0; x < sizeC; x++) {
			for (int y = 0; y < sizeR; y++) {
				if (!(arr[x][y] = arrFromCopy[x][y])) {
					throw MatrixException("Assignment error!\n");
				}
			}
		}
		sizeCol = sizeC;
		sizeRow = sizeR;
	}

	int getCols()
	{
		return sizeCol;
	}

	int getRows()
	{
		return sizeRow;
	}

	void print() {
		if (arr == nullptr)
			throw MatrixException("Matrix is empty!\n");
		for (int i = 0; i < sizeRow; i++) {
			for (int k = 0; k < sizeCol; k++) {
				cout << arr[i][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	Matrix operator=(Matrix newArr)
	{
		delete[] arr;
		sizeCol = newArr.sizeCol;
		sizeRow = newArr.sizeRow;

		arr = new int* [sizeCol];
		for (int i = 0; i < sizeCol; i++)
			if (!(arr[i] = new int[sizeRow]))
				throw MatrixException("Error of memory allocation!\n");

		for (int i = 0; i < sizeCol; i++)
			for (int j = 0; j < sizeRow; j++)
				if (!(arr[i][j] = newArr.arr[i][j]))
					throw MatrixException("Assignment error!\n");
		return newArr;
	}

	void fillMatrix() {
		arr = new int* [sizeCol];
		for (int i = 0; i < sizeCol; i++) {
			if (!(arr[i] = new int[sizeRow])) {
				throw MatrixException("Error of memory allocation!\n");
			}
		}

		for (int i = 0; i < sizeCol; i++) {
			for (int k = 0; k < sizeRow; k++) {
				cout << "arr[" << i << "][" << k << "] : ";
				cin >> arr[i][k];
			}
		}
	}

	void changeElement(int iCol, int iRow, int newElement) {
		arr[iRow][iCol] = newElement;
	}

	int getElementAt(int iCol,int iRow) {
		if (arr == nullptr) {
			throw MatrixException("Matrix is empty");
		}
		return arr[iCol][iRow];
	}

	void mulOn(int value) {
		if (arr == nullptr) {
			throw MatrixException("Matrix is empty");
		}
		for (int i = 0; i < sizeCol; i++) {
			for (int k = 0; k < sizeRow; k++) {
				arr[i][k] *= value;
			}
		}
	}

	bool isContainElement(int element) {
		if (arr == nullptr) {
			throw MatrixException("Matrix is empty");
		}
		for (int i = 0; i < sizeCol; i++) {
			for (int k = 0; k < sizeRow; k++) {
				if (arr[i][k] == element) {
					return true;
				}
			}
		}
		return false;
	}

	void plus(Matrix obj) {
		if (arr == nullptr) {
			throw MatrixException("Matrix is empty");
		}
		if (obj.getCols() == sizeCol and obj.getRows() == sizeRow) {
			for (int i = 0; i < sizeCol; i++) {
				for (int k = 0; k < sizeRow; k++) {
					arr[i][k] += obj.getElementAt(i,k);
				}
			}
		}
	}


	bool operator==(Matrix obj)
	{
		if (sizeCol == obj.getCols() and sizeRow == obj.getRows())
		{
			bool check = true;
			for (int x = 0; x < sizeCol; x++)
				for (int y = 0; y < sizeRow; y++)
					if (arr[x][y] != obj.arr[x][y])
					{
						check = false;
						break;
					}
			return check;
		}
		else return false;
	}

	bool operator>(Matrix obj) {
		if (sizeCol == obj.getCols() and sizeRow == obj.getRows()) {
			return this->sumOfElements() > obj.sumOfElements();
		}
		else {
			throw MatrixException("Matrixs are different sizes!");
		}
	}

	int sumOfElements() {
		if (arr == nullptr) {
			throw MatrixException("Matrix is empty!");
		}
		int sum = 0;
		for(int i=0;i<sizeCol;i++){
			for (int k = 0; k < sizeRow; k++) {
				sum += arr[i][k];
			}
		}
		return sum;
	}

};

void new_terminate()
{
	cout << " my terminate handler!\n";
	exit(-1);
}

void my_unexpected()
{
	cout << "my_unexpected handler\n" << endl;
}

int main() {

	set_terminate(new_terminate);
	set_unexpected(my_unexpected);

	int** arr = new int* [2];
	for (int i = 0; i < 2; i++) {
		arr[i] = new int[2];
	}
	arr[0][0] = 2;
	arr[0][1] = 2;
	arr[1][0] = 2;
	arr[1][1] = 2;
	try
	{
		Matrix m1 = Matrix(2, 2);
		Matrix m2 = Matrix(arr, 2, 2);
		m1.fillMatrix();
		m2.changeElement(0, 0, 15);
		m1.mulOn(2);

		cout << "m1:" << endl;
		m1.print();

		cout << "m2:" << endl;
		m2.print();

		m1.plus(m2);

		cout << "m1:" << endl;
		m1.print();

		cout << "m2:" << endl;
		m2.print();

		cout << "m1>m2 ? : " << (m2 > m1 ? "yes" : "no") << endl;
		m1 = m2;
		cout << "m1==m2 ? : " << (m1 == m2 ? "yes" : "no") << endl;
		cout << "is matrix m2 contains 14 ? : " << (m2.isContainElement(14) ? "yes" : "no") << endl;
		Matrix m3;
		cout << "element [1][1] of matrix m3 = " << m3.getElementAt(1, 1) << endl;
	} catch (MatrixException err) {
		cout << err.what() << endl;
		terminate();
	}
}