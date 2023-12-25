package main

import (
    "bufio"
    "fmt"
    "os"
)

var all_dirs = [][2]int{
    [2]int{0, 1},
    [2]int{0, -1},
    [2]int{-1, 0},
    [2]int{1, 0},
}
var slopes = []byte("><^v")

var G []string
var n, m int
var best int

func walk(seen map[[2]int]bool, x, y, steps int) {
    if x < 0 || x >= n || y < 0 || y >= m || G[x][y] == '#' { 
        return
    }
    if v, ok := seen[[2]int{x, y}]; ok && v == true {
        return
    }
    seen[[2]int{x, y}] = true
    if x == n - 1 {
        if steps > best {
            best = steps
        }
    }
    var dirs [][2]int
    if G[x][y] == '.' {
        dirs = all_dirs
    } else {
        for i, s := range(slopes) {
            if G[x][y] == s {
                dirs = [][2]int{all_dirs[i]}
            }
        }
    }
    for _, dir := range dirs {
        xx := x + dir[0]
        yy := y + dir[1]
        walk(seen, xx, yy, steps + 1)
    }
    seen[[2]int{x, y}] = false
}

func main() {
    G = make([]string, 0)
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        G = append(G, scanner.Text())
    }
    n = len(G)
    m = len(G[0])
    for y, c := range G[0] {
        if c == '.' {
            walk(make(map [[2]int]bool), 0, y, 0)
        }
    }
    fmt.Println(best)
}
