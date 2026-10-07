package main

import (
	"fmt"
	"strconv"
	"strings"

	"dbms_go/structures"
)

func QueryProcess(query string, arr *structures.MyArray, flist *structures.SinglyList, dlist *structures.DoublyList, stack *structures.MyStack, que *structures.MyQueue, tree *structures.CBTree) {
	cmd := strings.Fields(query)
	if len(cmd) == 0 {
		return
	}
	c := cmd[0]
	var typeChar byte
	if len(c) > 0 {
		typeChar = c[0]
	}

	switch typeChar {
	case 'M':
		if c == "MPUSH" && len(cmd) > 2 {
			val, _ := strconv.Atoi(cmd[2])
			arr.Push(val)
		} else if c == "MDEL" && len(cmd) > 1 {
			idx, _ := strconv.Atoi(cmd[1])
			arr.Del(idx)
		}
		arr.Print()

	case 'F':
		if c == "FPUSH" && len(cmd) > 2 {
			val, _ := strconv.Atoi(cmd[2])
			flist.PushTail(val)
		} else if c == "FDEL" && len(cmd) > 1 {
			val, _ := strconv.Atoi(cmd[1])
			flist.Del(val)
		}
		flist.Print()

	case 'L':
		if c == "LPUSH" && len(cmd) > 2 {
			val, _ := strconv.Atoi(cmd[2])
			dlist.PushTail(val)
		} else if c == "LDEL" && len(cmd) > 1 {
			val, _ := strconv.Atoi(cmd[1])
			dlist.Del(val)
		}
		dlist.Print()

	case 'S':
		if c == "SPUSH" && len(cmd) > 1 {
			val, _ := strconv.Atoi(cmd[1])
			stack.Push(val)
		} else if c == "SPOP" {
			fmt.Println("SPOP:", stack.Pop())
		}
		stack.Print()

	case 'Q':
		if c == "QPUSH" && len(cmd) > 1 {
			val, _ := strconv.Atoi(cmd[1])
			que.Push(val)
		} else if c == "QPOP" {
			fmt.Println("QPOP:", que.Pop())
		}
		que.Print()

	case 'T':
		if c == "TINSERT" && len(cmd) > 1 {
			val, _ := strconv.Atoi(cmd[1])
			tree.Insert(val)
		} else if c == "TCHECK" {
			fmt.Println("Is Complete:", tree.IsComplete())
		}
		tree.Print()

	case 'P':
		if c == "PRINT" {
			arr.Print()
			flist.Print()
			dlist.Print()
			stack.Print()
			que.Print()
			tree.Print()
		}
	}
}
