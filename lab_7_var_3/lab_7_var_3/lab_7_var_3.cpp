#include <iostream>
#include <string>
#include <array>
using namespace std;

template<typename T> void reverseArray(T* arr, int len) {
    for (int i = 0, k = len - 1; i < k; i++, k--)
    {
        T temp = arr[k];
        arr[k] = arr[i];
        arr[i] = temp;
    }
}

template<>
void reverseArray(char* arr, int len) {
    for (int i = 0, k = len - 1; i < k; i++, k--)
    {
        char temp = arr[k];
        arr[k] = arr[i];
        arr[i] = temp;
    }
}

template<typename T> void show(T* arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    char arr3[] = { 'a','b','c','d' };
    reverseArray(arr3, size(arr3));
    show(arr3, size(arr3));

    int arr[] = { 1,2,3,4,5 };
    reverseArray(arr, size(arr));
    show(arr, size(arr));

    string arr1[] = { "a","b","c","d" };
    reverseArray(arr1, size(arr1));
    show(arr1, size(arr1));

    double arr2[] = { 1.4,2.5,3.1,4.4,5.5 };
    reverseArray(arr2, size(arr2));
    show(arr2, size(arr2));

}