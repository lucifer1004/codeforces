package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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

func solve(caseNum int) {
	var n int
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)

	outputStr := fmt.Sprintf("%d\n", n)
	writer.WriteString(outputStr)
}

func main() {
	ioPrepare()
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < t; i++ {
		solve(i)
	}

	writer.Flush()
}
