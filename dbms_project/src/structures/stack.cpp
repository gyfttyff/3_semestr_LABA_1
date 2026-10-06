#include "structures/stack.h"
#include <iostream>
using namespace std;
void stack_init(MyStack& st) { 
    st.top = -1; //стек пуст
    st.cap = 2; // нач глубина
    st.data = new int[st.cap]; 
}

void stack_push(MyStack& st, int val) {
    if (st.top == st.cap - 1) { 
        st.cap *= 2; 
        int* n = new int[st.cap]; 

        for(int i = 0; i <= st.top; i++) n[i]=st.data[i]; 

        delete[] st.data; 
        st.data=n; 
    }
    st.top++;  // на одну позицию вверз уходит голова
    st.data[st.top] = val; // в голову пишем значение
}

int stack_pop(MyStack& st) {
    if (st.top < 0) return -1; // стек пуст
    int val = st.data[st.top]; // верх
    st.top--;                  // опускаем указатель головы вниз
    return val;                
     
}

void stack_print(MyStack& st) { cout << "Stack: "; for(int i = st.top; i >= 0; i--) cout << st.data[i] << " "; cout << endl; }