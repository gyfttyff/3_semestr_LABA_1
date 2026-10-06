#pragma once
struct MyQueue { 
    int* data; 
    int head, tail, count, cap; // первый, хвост, длина очереди, вместимость  
 };
void queue_init(MyQueue& q);
void queue_push(MyQueue& q, int val);
int queue_pop(MyQueue& q);
void queue_print(MyQueue& q);