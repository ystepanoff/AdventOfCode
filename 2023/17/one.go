package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

type Item struct {
	heat  int
	p     complex128
	d     complex128
	index int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].heat < pq[j].heat
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = j
	pq[j].index = i
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil
	item.index = -1
	*pq = old[0 : n-1]
	return item
}

func main() {
	G := make(map[complex128]int)
	scanner := bufio.NewScanner(os.Stdin)
	end := complex(0, 0)
	for i := 0; scanner.Scan(); i++ {
		for j, c := range scanner.Text() {
			p := complex(float64(i), float64(j))
			G[p] = int(c - '0')
			if real(p) > real(end) || imag(p) > imag(end) {
				end = p
			}
		}
	}

	q := make(PriorityQueue, 0)
	heap.Init(&q)
	heap.Push(&q, &Item{heat: 0, p: 0, d: 1})
	heap.Push(&q, &Item{heat: 0, p: 0, d: 1i})

	seen := make(map[[2]complex128]bool)

	for q.Len() > 0 {
		item := (heap.Pop(&q)).(*Item)
		if item.p == end {
			fmt.Println(item.heat)
			break
		}
		key := [2]complex128{item.p, item.d}
		if _, ok := seen[key]; ok {
			continue
		}
		seen[key] = true

		for _, new_d := range [2]complex128{-1i / item.d, 1i / item.d} {
			for s := 1; s <= 3; s++ {
				new_p := item.p + new_d*complex(float64(s), 0)
				if _, ok := G[new_p]; ok {
					w := item.heat
					for i := 1; i <= s; i++ {
						w += G[item.p+new_d*complex(float64(i), 0)]
					}
					heap.Push(&q, &Item{heat: w, p: new_p, d: new_d})
				}
			}
		}
	}
}
