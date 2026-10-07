package structures

import "fmt"

type MyArray struct {
	Data []int
}

func NewArray() *MyArray {
	return &MyArray{Data: make([]int, 0)}
}

func (a *MyArray) Push(val int) {
	a.Data = append(a.Data, val)
}

func (a *MyArray) Del(index int) {
	if index < 0 || index >= len(a.Data) {
		return
	}
	// Сдвигаем элементы влево
	a.Data = append(a.Data[:index], a.Data[index+1:]...)
}

func (a *MyArray) Print() {
	fmt.Print("Array:")
	for _, v := range a.Data {
		fmt.Printf(" %d", v)
	}
	fmt.Println()
}
