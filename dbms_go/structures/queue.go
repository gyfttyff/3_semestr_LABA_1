package structures

import "fmt"

type MyQueue struct {
	Data  []int
	Head  int
	Tail  int
	Count int
	Cap   int
}

func NewQueue() *MyQueue {
	return &MyQueue{
		Data:  make([]int, 2),
		Head:  0,
		Tail:  0,
		Count: 0,
		Cap:   2,
	}
}

func (q *MyQueue) Push(val int) {
	if q.Count == q.Cap {
		// Расширяем очередь
		newCap := q.Cap * 2
		newData := make([]int, newCap)
		for i := 0; i < q.Count; i++ {
			newData[i] = q.Data[(q.Head+i)%q.Cap]
		}
		q.Data = newData
		q.Head = 0
		q.Tail = q.Count
		q.Cap = newCap
	}
	q.Data[q.Tail] = val
	q.Tail = (q.Tail + 1) % q.Cap
	q.Count++
}

func (q *MyQueue) Pop() int {
	if q.Count == 0 {
		return -1
	}
	val := q.Data[q.Head]
	q.Head = (q.Head + 1) % q.Cap
	q.Count--
	return val
}

func (q *MyQueue) Print() {
	fmt.Print("Queue:")
	for i := 0; i < q.Count; i++ {
		fmt.Printf(" %d", q.Data[(q.Head+i)%q.Cap])
	}
	fmt.Println()
}
