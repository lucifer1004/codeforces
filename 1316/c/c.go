package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const maxCapacity = 1024 * 1024 * 10

var scanner *bufio.Scanner
var writer *bufio.Writer

func ioPrepare() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)

	buf := make([]byte, maxCapacity)
	scanner.Buffer(buf, maxCapacity)
}

func solve() {
	var n, m, p int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n, &m, &p)
	ans := 0
	scanner.Scan()
	aStr := strings.Split(scanner.Text(), " ")
	for i, v := range aStr {
		a, _ := strconv.Atoi(v)
		if a%p != 0 {
			ans += i
			break
		}
	}
	scanner.Scan()
	bStr := strings.Split(scanner.Text(), " ")
	for i, v := range bStr {
		b, _ := strconv.Atoi(v)
		if b%p != 0 {
			ans += i
			break
		}
	}

	outputStr := fmt.Sprintf("%d\n", ans)
	writer.WriteString(outputStr)
}

func main() {
	ioPrepare()
	solve()
	writer.Flush()
}
