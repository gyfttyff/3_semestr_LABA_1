#pragma once
struct MyArray {
    int* data;
    int size;
    int capacity;
};
void array_init(MyArray& arr);
void array_push(MyArray& arr, int val);
int array_get(MyArray& arr, int index);
void array_del(MyArray& arr, int index);
void array_print(MyArray& arr);