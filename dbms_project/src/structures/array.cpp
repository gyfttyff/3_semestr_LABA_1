#include "structures/array.h"
#include <iostream>
using namespace std;

void array_init(MyArray& arr) { arr.size = 0; arr.capacity = 2; arr.data = new int[arr.capacity]; }

void array_push(MyArray& arr, int val) {

    if (arr.size == arr.capacity) {
        arr.capacity *= 2; 
        int* n = new int[arr.capacity];
        for (int i = 0; i < arr.size; i++) n[i] = arr.data[i];
        delete[] arr.data; arr.data = n;
    }
    
    arr.data[arr.size++] = val;
}

int array_get(MyArray& arr, int index) { 

    return (index >= 0 && index < arr.size) ? arr.data[index] : -1; 

}

void array_del(MyArray& arr, int index) {

    if (index < 0 || index >= arr.size) return;
    for (int i = index; i < arr.size - 1; i++) arr.data[i] = arr.data[i + 1];
    arr.size--;

}

void array_print(MyArray& arr) {

    cout << "Array: "; 
    for(int i = 0; i < arr.size; i++) cout << arr.data[i] << " "; 
    cout << endl;
}