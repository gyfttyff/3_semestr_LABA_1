#include "structures/doubly_list.h"
#include <iostream>
using namespace std;

// Инициализация: поезд пуст, ни головы, ни хвоста нет
void dlist_init(DNode* &head, DNode* &tail) { 
    head = nullptr; 
    tail = nullptr; 
}

// Добавление в хвост
void dlist_push_tail(DNode* &head, DNode* &tail, int val) {
    DNode* n = new DNode;
    n->data = val;
    n->next = nullptr; // вперёд никого нет
    n->prev = tail;    // назад смотрим на текущий хвост

    if (tail == nullptr) { 
        head = n; // новый вагон становится головой
        tail = n; // И он же становится хвостом
        return; 
    }
    
    tail->next = n; // старый хвост теперь смотрит вперёд на новый вагон
    tail = n;       // новый вагон официально становится хвостом
}

void dlist_del(DNode* &head, DNode* &tail, int val) {
    DNode* c = head; // начинаем поиск с головы
    
    while (c != nullptr) {
        if (c->data == val) {
            // вперёд у левого соседа
            if (c->prev != nullptr) 
                c->prev->next = c->next; // левый сосед смотрит на правого
            else 
                head = c->next; // если левого нет удаляем голову

            // назад у правого соседа
            if (c->next != nullptr) 
                c->next->prev = c->prev; // правый сосед смотрит на левого
            else 
                tail = c->prev; // если правого нет удаляем хвост

            delete c; 
            return;
        }
        c = c->next; 
    }
}

void dlist_print(DNode* head) {
    cout << "DoublyList: "; 
    DNode* c = head; 
    while(c != nullptr) { 
        cout << c->data << " "; 
        c = c->next; 
    } 
    cout << endl;
}