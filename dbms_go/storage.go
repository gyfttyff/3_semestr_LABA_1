package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"

	"dbms_go/structures"
)

func StorageLoad(filename string, arr *structures.MyArray, flist *structures.SinglyList, dlist *structures.DoublyList, stack *structures.MyStack, que *structures.MyQueue, tree *structures.CBTree) {
	file, err := os.Open(filename)
	if err != nil {
		fmt.Println("File not found, starting empty")
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.SplitN(line, ":", 2)
		if len(parts) != 2 {
			continue
		}
		prefix := parts[0]
		values := strings.TrimSpace(parts[1])
		if values == "" {
			continue
		}
		vals := strings.Fields(values)
		for _, v := range vals {
			val, err := strconv.Atoi(v)
			if err != nil {
				continue
			}
			switch prefix {
			case "ARRAY":
				arr.Push(val)
			case "SLIST":
				flist.PushTail(val)
			case "DLIST":
				dlist.PushTail(val)
			case "STACK":
				stack.Push(val)
			case "QUEUE":
				que.Push(val)
			case "TREE":
				tree.Insert(val)
			}
		}
	}
	fmt.Println("Loaded from", filename)
}

func StorageSave(filename string, arr *structures.MyArray, flist *structures.SinglyList, dlist *structures.DoublyList, stack *structures.MyStack, que *structures.MyQueue, tree *structures.CBTree) {
	file, err := os.Create(filename)
	if err != nil {
		fmt.Println("Error saving file")
		return
	}
	defer file.Close()

	writer := bufio.NewWriter(file)

	// Массив
	fmt.Fprint(writer, "ARRAY:")
	for _, v := range arr.Data {
		fmt.Fprintf(writer, " %d", v)
	}
	fmt.Fprintln(writer)

	// Односвязный список
	fmt.Fprint(writer, "SLIST:")
	c := flist.Head
	for c != nil {
		fmt.Fprintf(writer, " %d", c.Data)
		c = c.Next
	}
	fmt.Fprintln(writer)

	// Двусвязный список
	fmt.Fprint(writer, "DLIST:")
	c2 := dlist.Head
	for c2 != nil {
		fmt.Fprintf(writer, " %d", c2.Data)
		c2 = c2.Next
	}
	fmt.Fprintln(writer)

	// Стек
	fmt.Fprint(writer, "STACK:")
	for i := len(stack.Data) - 1; i >= 0; i-- {
		fmt.Fprintf(writer, " %d", stack.Data[i])
	}
	fmt.Fprintln(writer)

	// Очередь
	fmt.Fprint(writer, "QUEUE:")
	for i := 0; i < que.Count; i++ {
		fmt.Fprintf(writer, " %d", que.Data[(que.Head+i)%que.Cap])
	}
	fmt.Fprintln(writer)

	// Дерево
	fmt.Fprint(writer, "TREE:")
	if tree.Root != nil {
		queue := []*structures.TNode{tree.Root}
		for len(queue) > 0 {
			curr := queue[0]
			queue = queue[1:]
			fmt.Fprintf(writer, " %d", curr.Data)
			if curr.Left != nil {
				queue = append(queue, curr.Left)
			}
			if curr.Right != nil {
				queue = append(queue, curr.Right)
			}
		}
	}
	fmt.Fprintln(writer)

	writer.Flush()
	fmt.Println("Saved to", filename)
}
