#pragma once
#include <string>

#include "structures/array.h"
#include "structures/singly_list.h"
#include "structures/doubly_list.h"
#include "structures/stack.h"
#include "structures/queue.h"
#include "structures/CB_tree.h"

void storage_load(const std::string& filename, 
                  MyArray& arr, 
                  SNode* &flist_head, 
                  DNode* &dlist_head, DNode* &dlist_tail, 
                  MyStack& stack, 
                  MyQueue& que, 
                  TNode* &tree_root);

void storage_save(const std::string& filename, 
                  MyArray& arr, 
                  SNode* flist_head, 
                  DNode* dlist_head, 
                  MyStack& stack, 
                  MyQueue& que, 
                  TNode* tree_root);