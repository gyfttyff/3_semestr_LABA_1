#include "structures/singly_list.h"
#include <iostream>
using namespace std;

void slist_init(SNode* &head) { 
    head = nullptr; 
}

void slist_push_tail(SNode* &head, int val) {

    SNode* n = new SNode;
    n->data = val;
    n->next = nullptr;

    if (head == nullptr) { 
        head = n; 
        return; 
    }
    
    SNode* c = head; 
    while (c->next != nullptr) {
        c = c->next; 
    }

    c->next = n;
}

void slist_del(SNode* &head, int val) {
    if (head == nullptr) return;

    if (head->data == val) { 
        SNode* t = head; 
        head = head->next; 
        delete t;          // Удаляем старую голову
        return; 
    }

    // узел перед удаляемым
    SNode* c = head;
    while (c->next != nullptr && c->next->data != val) {
        c = c->next; 
    }

    // если нашли перепрыгиваем через удаляемый узел
    if (c->next != nullptr) { 
        SNode* t = c->next; 
        c->next = t->next; 
        delete t; 
    }
}

void slist_print(SNode* head) {
    cout << "SinglyList: "; 
    SNode* c = head; 
    while(c != nullptr) { 
        cout << c->data << " "; 
        c = c->next; 
    } 
    cout << endl;
}