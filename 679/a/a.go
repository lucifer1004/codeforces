package main

import (
	"bufio"
	"fmt"
	"os"
)

const maxCapacity = 1024

var scanner *bufio.Scanner
var writer *bufio.Writer

func ioPrepare() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)

	buf := make([]byte, maxCapacity)
	scanner.Buffer(buf, maxCapacity)
}

func solve() {
	primes := []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}
	count := 0
	prime := 0
	for _, i := range primes {
		fmt.Println(i)
		scanner.Scan()
		result := scanner.Text()
		if result == "yes" {
			prime = i
			count++
		}
	}
	if count == 0 {
		fmt.Println("prime")
	} else if count >= 2 {
		fmt.Println("composite")
	} else {
		num := prime * prime
		if num > 100 {
			fmt.Println("prime")
		} else {
			fmt.Println(num)
			scanner.Scan()
			result := scanner.Text()
			if result == "yes" {
				fmt.Println("composite")
			} else {
				fmt.Println("prime")
			}
		}
	}
}

func main() {
	ioPrepare()
	solve()
}
