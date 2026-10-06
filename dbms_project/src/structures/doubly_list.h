#pragma once

struct DNode { 
    int data; 
    DNode* prev; 
    DNode* next; 
};

void dlist_init(DNode* &head, DNode* &tail);
void dlist_push_tail(DNode* &head, DNode* &tail, int val);
void dlist_del(DNode* &head, DNode* &tail, int val);
void dlist_print(DNode* head);