package main

import (
	"fmt"
	"os"

	"dbms_go/structures"
)

func main() {
	filename := ""
	query := ""

	// Парсинг аргументов
	args := os.Args[1:]
	for i := 0; i < len(args); i++ {
		if args[i] == "--file" && i+1 < len(args) {
			filename = args[i+1]
			i++
		} else if args[i] == "--query" && i+1 < len(args) {
			query = args[i+1]
			i++
		}
	}

	// Инициализация структур
	arr := structures.NewArray()
	flist := structures.NewSinglyList()
	dlist := structures.NewDoublyList()
	stack := structures.NewStack()
	que := structures.NewQueue()
	tree := structures.NewCBTree()

	// Загрузка
	if filename != "" {
		StorageLoad(filename, arr, flist, dlist, stack, que, tree)
	}

	// Выполнение команды
	if query != "" {
		QueryProcess(query, arr, flist, dlist, stack, que, tree)
		if filename != "" {
			StorageSave(filename, arr, flist, dlist, stack, que, tree)
		}
	} else {
		fmt.Println(`Usage: dbms_go.exe --file data.txt --query "TINSERT 5"`)
	}
}
