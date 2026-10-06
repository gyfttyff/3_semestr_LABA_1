#include "structures/CB_tree.h"
#include <iostream>
using namespace std;

void cbt_init(TNode* &root) { 
    root = nullptr; 
}

void cbt_insert(TNode* &root, int val) {
    // новый корень
    TNode* n = new TNode;
    n->data = val; 
    n->left = nullptr; 
    n->right = nullptr;

    // новый узел становится корнем
    if (root == nullptr) { 
        root = n; 
        return; 
    }
    
    // оздаем стандартную очередь и кладем туда корень
    queue<TNode*> q; 
    q.push(root);
    
    while (!q.empty()) {
        TNode* curr = q.front(); // берем первый узел из очереди
        q.pop();                 // убираем его из очереди
        
        // пытаемся вставить влево
        if (curr->left == nullptr) { 
            curr->left = n; 
            return; // вставили и вышли
        }
        else {
            q.push(curr->left); // если занято левого ребенка в очередь
        }
        
        // пытаемся вставить вправо
        if (curr->right == nullptr) { 
            curr->right = n; 
            return; // вставили и вышли
        }
        else {
            q.push(curr->right); // если занято правого ребенка в очередь
        }
    }
}

// через очередь обходим всё дерево находя элемент
bool cbt_search(TNode* root, int val) {
    if (root == nullptr) return false;
    
    queue<TNode*> q; 
    q.push(root);
    
    while (!q.empty()) {
        TNode* curr = q.front(); 
        q.pop();
        if (curr->data == val) return true; // нашли
        
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return false;
}

// проверка на полноту 
bool cbt_is_complete(TNode* root) {
    if (root == nullptr) return true;
    
    queue<TNode*> q; 
    q.push(root);
    bool foundGap = false; // нашли ли мы дырку 
    
    while (!q.empty()) {
        TNode* curr = q.front(); 
        q.pop();
        
        // левый ребенок
        if (curr->left) {
            if (foundGap) return false; // если дырка уже была, а тут есть ребенок дерево не полное
            q.push(curr->left);
        } else { 
            foundGap = true; // левый ребенок отсутствует, фиксируем дырку
        }

        // правый ребенок
        if (curr->right) {
            if (foundGap) return false; // снова не полное
            q.push(curr->right);
        } else { 
            foundGap = true; // правый ребенок отсутствует, фиксируем
        }
    }
    return true; // дырок не нашли дерево полное
}

// вывод на экран по уровням
void cbt_print(TNode* root) {
    if (root == nullptr) { 
        cout << "CBTree is empty" << endl; 
        return; 
    }
    
    queue<TNode*> q; 
    q.push(root);
    cout << "CBTree: ";
    
    while (!q.empty()) {
        TNode* curr = q.front(); q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << endl;
}