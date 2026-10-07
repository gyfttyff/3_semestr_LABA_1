
#include <iostream>
#include <string>
#include "storage.h"
#include "query_processor.h"
using namespace std;

int main(int argc, char* argv[]) { //количество аргументов, массив аргументов
    string filename = ""; 
    string query = "";
    
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "--file" && i + 1 < argc) filename = argv[++i]; // если текущий элемент файл
        else if (string(argv[i]) == "--query" && i + 1 < argc) query = argv[++i];
    }

    MyArray arr; array_init(arr);
    
    SNode* flist_head; slist_init(flist_head);
    
    DNode* dlist_head; 
    DNode* dlist_tail; 
    dlist_init(dlist_head, dlist_tail);
    
    MyStack stack; stack_init(stack);
    MyQueue que; queue_init(que);
    
    TNode* tree_root; cbt_init(tree_root);

    // Загрузка из файла
    if (!filename.empty()) {
        storage_load(filename, arr, flist_head, dlist_head, dlist_tail, stack, que, tree_root);
    }

    // Выполнение команды
    if (!query.empty()) {
        query_process(query, arr, flist_head, dlist_head, dlist_tail, stack, que, tree_root);
        
        // Сохранение в файл
        if (!filename.empty()) {
            storage_save(filename, arr, flist_head, dlist_head, stack, que, tree_root);
        }
    } else {
        cout << "Usage: dbms.exe --file data.txt --query \"TINSERT mytree 5\"" << endl;
    }
    
    return 0;
}