#pragma once
#include <string>

#include "structures/array.h"
#include "structures/singly_list.h"
#include "structures/doubly_list.h"
#include "structures/stack.h"
#include "structures/queue.h"
#include "structures/CB_tree.h"

void query_process(const std::string& query, 
                   MyArray& arr, 
                   SNode* &flist_head, 
                   DNode* &dlist_head, DNode* &dlist_tail, 
                   MyStack& stack, 
                   MyQueue& que, 
                   TNode* &tree_root);