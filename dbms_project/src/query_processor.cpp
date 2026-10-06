#include "query_processor.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void query_process(const string& query, MyArray& arr, SinglyList& flist, DoublyList& dlist, MyStack& stack, MyQueue& queue, CBT& tree) {
    vector<string> cmd; 
    stringstream ss(query); // превращает строку в поток, как cin
    string t; 
    while(ss >> t) cmd.push_back(t);  // пока в потоке есть слова, читаем их по одному в переменную t.
    if (cmd.empty()) return;
    string c = cmd[0]; 
    char type = c[0];

    if (type == 'M') {
        if (c == "MPUSH" && cmd.size() > 2) array_push(arr, stoi(cmd[2])); // превращает строку в число 
        else if (c == "MDEL" && cmd.size() > 1) array_del(arr, stoi(cmd[1]));
        array_print(arr);
    } else if (type == 'F') {
        if (c == "FPUSH" && cmd.size() > 2) slist_push_tail(flist, stoi(cmd[2]));
        else if (c == "FDEL" && cmd.size() > 1) slist_del(flist, stoi(cmd[1]));
        slist_print(flist);
    } else if (type == 'L') {
        if (c == "LPUSH" && cmd.size() > 2) dlist_push_tail(dlist, stoi(cmd[2]));
        else if (c == "LDEL" && cmd.size() > 1) dlist_del(dlist, stoi(cmd[1]));
        dlist_print(dlist);
    } else if (type == 'S') {
        if (c == "SPUSH" && cmd.size() > 1) stack_push(stack, stoi(cmd[1]));
        else if (c == "SPOP") cout << "SPOP: " << stack_pop(stack) << endl;
        stack_print(stack);
    } else if (type == 'Q') {
        if (c == "QPUSH" && cmd.size() > 1) queue_push(queue, stoi(cmd[1]));
        else if (c == "QPOP") cout << "QPOP: " << queue_pop(queue) << endl;
        queue_print(queue);
    } else if (type == 'T') {
        if (c == "TINSERT" && cmd.size() > 1) cbt_insert(tree, stoi(cmd[1]));
        else if (c == "TCHECK") cout << "Is Complete: " << (cbt_is_complete(tree) ? "TRUE" : "FALSE") << endl;
        cbt_print(tree);
    }
}