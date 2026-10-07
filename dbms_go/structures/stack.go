package structures

import "fmt"

type MyStack struct {
	Data []int
}

func NewStack() *MyStack {
	return &MyStack{Data: make([]int, 0)}
}

func (s *MyStack) Push(val int) {
	s.Data = append(s.Data, val)
}

func (s *MyStack) Pop() int {
	if len(s.Data) == 0 {
		return -1
	}
	val := s.Data[len(s.Data)-1]
	s.Data = s.Data[:len(s.Data)-1]
	return val
}

func (s *MyStack) Print() {
	fmt.Print("Stack:")
	for i := len(s.Data) - 1; i >= 0; i-- {
		fmt.Printf(" %d", s.Data[i])
	}
	fmt.Println()
}
