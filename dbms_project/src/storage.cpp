#include "storage.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

void storage_load(const string& filename, 
                  MyArray& arr, 
                  SNode* &flist_head, 
                  DNode* &dlist_head, DNode* &dlist_tail, 
                  MyStack& stack, 
                  MyQueue& que, 
                  TNode* &tree_root) {
    
    ifstream in(filename);
    if (!in) {
        cout << "File not found, starting empty" << endl;
        return;
    }

    string line;
    while (getline(in, line)) {
        int val;
        
        if (line.substr(0, 6) == "ARRAY:") {
            stringstream ss(line.substr(6));
            while (ss >> val) array_push(arr, val);
        }
        else if (line.substr(0, 6) == "SLIST:") {
            stringstream ss(line.substr(6));
            while (ss >> val) slist_push_tail(flist_head, val);
        }
        else if (line.substr(0, 6) == "DLIST:") {
            stringstream ss(line.substr(6));
            while (ss >> val) dlist_push_tail(dlist_head, dlist_tail, val);
        }
        else if (line.substr(0, 6) == "STACK:") {
            stringstream ss(line.substr(6));
            while (ss >> val) stack_push(stack, val);
        }
        else if (line.substr(0, 6) == "QUEUE:") {
            stringstream ss(line.substr(6));
            while (ss >> val) queue_push(que, val);
        }
        else if (line.substr(0, 5) == "TREE:") {
            stringstream ss(line.substr(5));
            while (ss >> val) cbt_insert(tree_root, val);
        }
    }
    in.close();
    cout << "Loaded from " << filename << endl;
}

void storage_save(const string& filename, 
                  MyArray& arr, 
                  SNode* flist_head, 
                  DNode* dlist_head, 
                  MyStack& stack, 
                  MyQueue& que, 
                  TNode* tree_root) {
    
    ofstream out(filename);
    if (!out) {
        cout << "Error saving file" << endl;
        return;
    }

    out << "ARRAY:";
    for (int i = 0; i < arr.size; i++) out << " " << arr.data[i];
    out << "\n";

    out << "SLIST:";
    SNode* c1 = flist_head;
    while (c1) { out << " " << c1->data; c1 = c1->next; }
    out << "\n";

    out << "DLIST:";
    DNode* c2 = dlist_head;
    while (c2) { out << " " << c2->data; c2 = c2->next; }
    out << "\n";

    out << "STACK:";
    for (int i = 0; i <= stack.top; i++) out << " " << stack.data[i];
    out << "\n";

    out << "QUEUE:";
    for (int i = 0; i < que.count; i++) out << " " << que.data[(que.head + i) % que.cap];
    out << "\n";

    out << "TREE:";
    if (tree_root != nullptr) {
        queue<TNode*> q;
        q.push(tree_root);
        while (!q.empty()) {
            TNode* curr = q.front(); q.pop();
            out << " " << curr->data;
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    out << "\n";

    out.close();
    cout << "Saved to " << filename << endl;
}