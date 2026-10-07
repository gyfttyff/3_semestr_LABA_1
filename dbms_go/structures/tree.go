package structures

import "fmt"

type TNode struct {
	Data  int
	Left  *TNode
	Right *TNode
}

type CBTree struct {
	Root *TNode
}

func NewCBTree() *CBTree {
	return &CBTree{Root: nil}
}

func (t *CBTree) Insert(val int) {
	n := &TNode{Data: val, Left: nil, Right: nil}
	if t.Root == nil {
		t.Root = n
		return
	}
	// BFS через очередь
	queue := []*TNode{t.Root}
	for len(queue) > 0 {
		curr := queue[0]
		queue = queue[1:]
		if curr.Left == nil {
			curr.Left = n
			return
		}
		queue = append(queue, curr.Left)
		if curr.Right == nil {
			curr.Right = n
			return
		}
		queue = append(queue, curr.Right)
	}
}

func (t *CBTree) Search(val int) bool {
	if t.Root == nil {
		return false
	}
	queue := []*TNode{t.Root}
	for len(queue) > 0 {
		curr := queue[0]
		queue = queue[1:]
		if curr.Data == val {
			return true
		}
		if curr.Left != nil {
			queue = append(queue, curr.Left)
		}
		if curr.Right != nil {
			queue = append(queue, curr.Right)
		}
	}
	return false
}

func (t *CBTree) IsComplete() bool {
	if t.Root == nil {
		return true
	}
	queue := []*TNode{t.Root}
	foundGap := false
	for len(queue) > 0 {
		curr := queue[0]
		queue = queue[1:]
		if curr.Left != nil {
			if foundGap {
				return false
			}
			queue = append(queue, curr.Left)
		} else {
			foundGap = true
		}
		if curr.Right != nil {
			if foundGap {
				return false
			}
			queue = append(queue, curr.Right)
		} else {
			foundGap = true
		}
	}
	return true
}

func (t *CBTree) Print() {
	if t.Root == nil {
		fmt.Println("CBTree is empty")
		return
	}
	fmt.Print("CBTree:")
	queue := []*TNode{t.Root}
	for len(queue) > 0 {
		curr := queue[0]
		queue = queue[1:]
		fmt.Printf(" %d", curr.Data)
		if curr.Left != nil {
			queue = append(queue, curr.Left)
		}
		if curr.Right != nil {
			queue = append(queue, curr.Right)
		}
	}
	fmt.Println()
}
