package main

import (
	"fmt"
	"math"
)

var N = int(math.Pow10(16))

func check(x int, y int) bool {
	return x * x + x * y + 41 * y * y <= N
}

func main() {
	L := int(math.Sqrt(4 * float64(N) / 163))
	total := 0
	for y := -L; y <= L; y++ {
		s := int(math.Sqrt(4 * float64(N) - 163 * float64(y * y)))
		l := int(-s - y) / 2
		r := int(s - y) / 2
		total += r - l + 1
		if !check(l, y) { total-- }
		if !check(r, y) { total-- }
	}
	fmt.Println(total - 1)
}
