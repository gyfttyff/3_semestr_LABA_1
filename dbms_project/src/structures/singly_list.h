#pragma once

struct SNode { 
    int data; 
    SNode* next; 
};

void slist_init(SNode* &head);
void slist_push_tail(SNode* &head, int val);
void slist_del(SNode* &head, int val);
void slist_print(SNode* head);