#pragma once
struct MyStack { int* data; int top, cap; };//вместимость 

void stack_init(MyStack& st);
void stack_push(MyStack& st, int val);
int stack_pop(MyStack& st);
void stack_print(MyStack& st);