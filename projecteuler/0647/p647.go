package main

import (
	"fmt"
)

func F(k int, n int) int {
	sum := 0
	for p := 3; p * p <= n; p += 2 {
		if (p - 1) * (4 - k) % (k - 2) == 0 {
			q := (p - 1) * (4 - k) / 2 / (k - 2)
			A := p * p
			B := q * (q * (k - 2) + 4 - k) / 2
			if (A > B && A <= n) || (A < B && B <= n) {
				sum += A + B
			}
		}
	}
	return sum
}

func SF(n int) int {
	sum := 0
	for k := 3; ; k += 2 {
		if f := F(k, n); f != 0 {
			sum += f
		} else {
			break
		}
	}
	return sum
}

func main() {
	fmt.Println(SF(1000000000000))
}
