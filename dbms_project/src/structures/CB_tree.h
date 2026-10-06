#pragma once
#include <queue> // для обхода дерева

// только одна структура узла. Никаких оберток
struct TNode { 
    int data; 
    TNode* left; 
    TNode* right; 
};

// корень (root)
void cbt_init(TNode* &root);
void cbt_insert(TNode* &root, int val);
bool cbt_search(TNode* root, int val);
bool cbt_is_complete(TNode* root);
void cbt_print(TNode* root);