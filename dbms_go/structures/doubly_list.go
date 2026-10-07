package structures

import "fmt"

type DNode struct {
	Data int
	Prev *DNode
	Next *DNode
}

type DoublyList struct {
	Head *DNode
	Tail *DNode
}

func NewDoublyList() *DoublyList {
	return &DoublyList{Head: nil, Tail: nil}
}

func (l *DoublyList) PushTail(val int) {
	n := &DNode{Data: val, Prev: l.Tail, Next: nil}
	if l.Tail == nil {
		l.Head = n
		l.Tail = n
		return
	}
	l.Tail.Next = n
	l.Tail = n
}

func (l *DoublyList) Del(val int) {
	c := l.Head
	for c != nil {
		if c.Data == val {
			if c.Prev != nil {
				c.Prev.Next = c.Next
			} else {
				l.Head = c.Next
			}
			if c.Next != nil {
				c.Next.Prev = c.Prev
			} else {
				l.Tail = c.Prev
			}
			return
		}
		c = c.Next
	}
}

func (l *DoublyList) Print() {
	fmt.Print("DoublyList:")
	c := l.Head
	for c != nil {
		fmt.Printf(" %d", c.Data)
		c = c.Next
	}
	fmt.Println()
}
