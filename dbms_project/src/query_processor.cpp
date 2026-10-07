#include "query_processor.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void query_process(const string& query, 
                   MyArray& arr, 
                   SNode* &flist_head, 
                   DNode* &dlist_head, DNode* &dlist_tail, 
                   MyStack& stack, 
                   MyQueue& que, 
                   TNode* &tree_root) {
    
    vector<string> cmd; 
    stringstream ss(query); 
    string t; 
    while(ss >> t) cmd.push_back(t);
    if (cmd.empty()) return;
    string c = cmd[0]; 
    char type = c[0];

    if (type == 'M') {
        if (c == "MPUSH" && cmd.size() > 2) array_push(arr, stoi(cmd[2]));
        else if (c == "MDEL" && cmd.size() > 1) array_del(arr, stoi(cmd[1]));
        array_print(arr);
    } 
    else if (type == 'F') {
        if (c == "FPUSH" && cmd.size() > 2) slist_push_tail(flist_head, stoi(cmd[2]));
        else if (c == "FDEL" && cmd.size() > 1) slist_del(flist_head, stoi(cmd[1]));
        slist_print(flist_head);
    } 
    else if (type == 'L') {
        if (c == "LPUSH" && cmd.size() > 2) dlist_push_tail(dlist_head, dlist_tail, stoi(cmd[2]));
        else if (c == "LDEL" && cmd.size() > 1) dlist_del(dlist_head, dlist_tail, stoi(cmd[1]));
        dlist_print(dlist_head);
    } 
    else if (type == 'S') {
        if (c == "SPUSH" && cmd.size() > 1) stack_push(stack, stoi(cmd[1]));
        else if (c == "SPOP") cout << "SPOP: " << stack_pop(stack) << endl;
        stack_print(stack);
    } 
    else if (type == 'Q') {
        if (c == "QPUSH" && cmd.size() > 1) queue_push(que, stoi(cmd[1]));
        else if (c == "QPOP") cout << "QPOP: " << queue_pop(que) << endl;
        queue_print(que);
    } 
    else if (type == 'T') {
        if (c == "TINSERT" && cmd.size() > 1) cbt_insert(tree_root, stoi(cmd[1]));
        else if (c == "TCHECK") cout << "Is Complete: " << (cbt_is_complete(tree_root) ? "TRUE" : "FALSE") << endl;
        cbt_print(tree_root);
    }
    else if (c == "PRINT") {
        array_print(arr);
        slist_print(flist_head);
        dlist_print(dlist_head);
        stack_print(stack);
        queue_print(que);
        cbt_print(tree_root);
    }
}