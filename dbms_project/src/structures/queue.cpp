#include "structures/queue.h"
#include <iostream>
using namespace std;

void queue_init(MyQueue& q) { 
    q.head = 0; 
    q.tail = 0; 
    q.count = 0; 
    q.cap = 2; 
    q.data = new int[q.cap]; 
}

void queue_push(MyQueue& q, int val) {
    if (q.count == q.cap) { 
        q.cap *= 2; 
        int* n = new int[q.cap]; 
        for(int i = 0; i < q.count; i++) 
        n[i] = q.data[(q.head + i) % q.cap]; 
        delete[] q.data; 
        q.data = n; 
        q.head = 0; // сбрасываем голову в начало
        q.tail = q.count; // хвост ставим сразу после последнего элемента
    }
    q.data[q.tail] = val; 
    q.tail = (q.tail + 1) % q.cap; 
    q.count++;
}

int queue_pop(MyQueue& q) {
    if (q.count == 0) return -1; 

    int val = q.data[q.head]; 
    q.head = (q.head + 1) % q.cap; 
    q.count--; 
    return val;
}

void queue_print(MyQueue& q) { cout << "Queue: "; for(int i = 0; i < q.count; i++) cout << q.data[(q.head + i) % q.cap] << " "; cout << endl; }