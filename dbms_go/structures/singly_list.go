package structures

import "fmt"

type SNode struct {
	Data int
	Next *SNode
}

type SinglyList struct {
	Head *SNode
}

func NewSinglyList() *SinglyList {
	return &SinglyList{Head: nil}
}

func (l *SinglyList) PushTail(val int) {
	n := &SNode{Data: val, Next: nil}
	if l.Head == nil {
		l.Head = n
		return
	}
	c := l.Head
	for c.Next != nil {
		c = c.Next
	}
	c.Next = n
}

func (l *SinglyList) Del(val int) {
	if l.Head == nil {
		return
	}
	// Удаляем голову
	if l.Head.Data == val {
		l.Head = l.Head.Next
		return
	}
	// Ищем узел перед удаляемым
	c := l.Head
	for c.Next != nil && c.Next.Data != val {
		c = c.Next
	}
	if c.Next != nil {
		c.Next = c.Next.Next
	}
}

func (l *SinglyList) Print() {
	fmt.Print("SinglyList:")
	c := l.Head
	for c != nil {
		fmt.Printf(" %d", c.Data)
		c = c.Next
	}
	fmt.Println()
}
