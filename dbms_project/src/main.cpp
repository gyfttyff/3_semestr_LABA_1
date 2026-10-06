#include <iostream>
#include <string>
#include "storage.h"
#include "query_processor.h"
using namespace std;

int main(int argc, char* argv[]) {
    string filename = ""; string query = "";
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "--file" && i + 1 < argc) filename = argv[++i]; // если текущий аргумент "--file", то следующий за ним (argv[i+1]) — это имя файла. Сохраняем его в filename. ++i увеличивает счётчик, чтобы пропустить следующий элемент
        else if (string(argv[i]) == "--query" && i + 1 < argc) query = argv[++i];
    }

    MyArray arr; array_init(arr); // cоздаём все структуры данных и инициализируем их
    SinglyList flist; slist_init(flist);
    DoublyList dlist; dlist_init(dlist);
    MyStack stack; stack_init(stack);
    MyQueue queue; queue_init(queue);
    CBT tree; cbt_init(tree);

    if (!filename.empty()) storage_load(filename, arr);

    if (!query.empty()) {
        query_process(query, arr, flist, dlist, stack, queue, tree);
        if (!filename.empty()) storage_save(filename, arr);
    } else {
        cout << "Usage: dbms.exe --file data.txt --query \"TINSERT mytree 5\"" << endl;
    }
    return 0;
}