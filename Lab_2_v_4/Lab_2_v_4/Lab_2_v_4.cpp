#include <iostream>
#include<string>
#include<locale>
#include <stdarg.h>
using namespace std;
        
class NegComplexNumber {


private:

    int x;
    int y;

public:

    NegComplexNumber() {
        this->x = 0;
        this->y = 0;
    }

    NegComplexNumber(int x, int y) {  
        if (x > 0) {
            this->x = -x;
        } else {
            this->x = x;
        }
        
        if (y > 0) {
            this->y = -y;
        } else {
            this->y = y;
        }

    }


    ~NegComplexNumber() = default;


    friend ostream& operator <<(ostream& out, NegComplexNumber& numb);
};

class ComplexNumber {

private:

    int x;
    int y;
    int arr[5][2] = { {1,1} ,{4,3}, {7,3}, {7,5}, {4,4} };

public:

    ComplexNumber() {
        this->x = 0;
        this->y = 0;
    }

    ComplexNumber(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void operator =(ComplexNumber& numb) {
        this->x = numb.x;
        this->y = numb.y;
    }

    ComplexNumber operator[](const int i)
    {
        return ComplexNumber(arr[i][0], arr[i][1]);
    }

    ComplexNumber& operator++() {
        x += 1;
        return *this;
    }

    ComplexNumber& operator ++(int)
    {
        ComplexNumber prev = *this;
        ++* this;
        return prev;
    }

    ComplexNumber operator +(ComplexNumber& numb) {
        int tempX = this->x + numb.x;
        int tempY = this->y + numb.y;
        ComplexNumber temp = ComplexNumber(tempX, tempY);
        return temp;
    }

    bool operator==(ComplexNumber& numb) {
        return this->x == numb.x && this->y == numb.y;
    }

    bool operator>(ComplexNumber& numb) {
        return this->x > numb.x;
    }

    ComplexNumber operator *(ComplexNumber& numb) {
        int tempX = this->x * numb.x - this->y * numb.y;
        int tempY = this->x * numb.y + numb.x * this->y;
        ComplexNumber temp = ComplexNumber(tempX, tempY);
        return temp;
    }

    operator int()
    {
        return x;
    }

    operator char()
    {
        return char(x);
    }

    operator NegComplexNumber () {
        return NegComplexNumber(x, y);
    }

    friend ostream& operator <<(ostream& out, ComplexNumber& obj);
    
    friend ComplexNumber& operator--(ComplexNumber& obj);
    
    friend ComplexNumber& operator--(ComplexNumber& obj, int);
    
    friend ComplexNumber& operator-(ComplexNumber& numb, ComplexNumber& otherNumb);
    
    friend ComplexNumber& operator-(ComplexNumber& numb, int otherNumb);
    
    friend bool operator<(ComplexNumber& numb, ComplexNumber& otherNumb);
    
    friend bool operator<(ComplexNumber& numb, int otherNumb);

    ~ComplexNumber() = default;

};


ostream& operator <<(ostream& out, ComplexNumber& numb)
{
    
    string res;
    
    if (numb.x != 0) {
        res += to_string(numb.x);
    }
    
    if (numb.y > 0) {
        res += "+" + to_string(numb.y) + "i";
    }
    
    else if (numb.y < 0) {
        res += "" + to_string(numb.y) + "i";
    }

    out << res;
    
    return out;
}

ComplexNumber& operator--(ComplexNumber& numb)
{
    numb.x -= 1;
    
    return numb;
}

ComplexNumber& operator--(ComplexNumber& numb, int)
{
    ComplexNumber prev = numb;
    
    numb.x -= 1;
    
    return prev;
}

ComplexNumber& operator -(ComplexNumber& numb, ComplexNumber& otherNumb) {
    
    int tempX = numb.x - otherNumb.x;
    
    int tempY = numb.y - otherNumb.y;
    
    ComplexNumber temp = ComplexNumber(tempX, tempY);
    
    return temp;
}

ComplexNumber& operator -(ComplexNumber& numb, int otherNumb) {
    
    int tempX = numb.x - otherNumb;

    ComplexNumber temp = ComplexNumber(tempX, numb.y);

    return temp;
}

bool operator<(ComplexNumber& numb, ComplexNumber& otherNumb)
{
    return numb.x < otherNumb.x;
}

bool operator<(ComplexNumber& numb, int otherNumb)
{
    return numb.x <= otherNumb;
}

ostream& operator <<(ostream& out, NegComplexNumber& numb) {
    
    if (numb.x == 0 && numb.y == 0) {
        
        out << "-0-0i";
    
        return out;
    }
    
    string res = to_string(numb.x) + "" + to_string(numb.y) + "i";
    
    out << res;
    
    return out;
}

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "start" << endl;

    ComplexNumber numb1 = ComplexNumber(2, 3);
    
    ComplexNumber numb2 = ComplexNumber(-1, 1);

    ComplexNumber numb3 = numb1 + numb2;
    
    cout << "(" << numb1 << ") + (" << numb2 << ") = " << numb3 << endl;

    bool flag = numb1 > numb2;
    
    string res = flag ? "true" : "false";
    
    cout << "(" << numb1 << ") > (" << numb2 << ") = " << res << endl;

    numb3++;
    
    cout << "numb3++ = " << numb3 << endl;

    numb3--;
    
    cout << "numb3-- = " << numb3 << endl;

    ++numb3;

    cout << "++numb = " << numb3 << endl;

    ComplexNumber numb4 = numb1 - numb2;
    
    cout << "(" << numb1 << ") - (" << numb2 << ") = " << numb4 << endl;

    bool flag1 = numb4 < numb2;
    
    string res1 = flag ? "false" : "true";
    
    cout << "(" << numb4 << ") < (" << numb2 << ") = " << res1 << endl;
    
    auto b = numb1[2];
    
    cout << "numb1[2] =" << b << endl;

    cout << "int(numb1) = " << (int)numb1 << endl;

    cout << "char(numb1) = " << (char)numb1 << endl;
    
    auto a = (NegComplexNumber)numb1;

    cout << " ComplexNumber to NegComplexNumber " << a << endl;

    return 0;
}
