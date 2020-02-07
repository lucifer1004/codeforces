class Node(val c: Char, val n: Int)

class Solution(private var s: String) {
    fun solve() {
        s += '$'
        var curr = '#'
        var count = 0
        val segments = mutableListOf<Node>()
        for (c in s) {
            if (c == curr)
                count++
            else {
                if (count > 0)
                    segments.add(Node(curr, count))
                curr = c
                count = 1
            }
        }
        val n = segments.size
        if (n % 2 != 1 || segments[n / 2].n < 2) {
            println(0)
            return
        }
        for (i in 0 until n / 2) {
            if (segments[i].c != segments[n - i - 1].c || segments[i].n + segments[n - i - 1].n < 3) {
                println(0)
                return
            }
        }
        println(segments[n / 2].n + 1)
    }
}

fun main() {
    val s = readLine()!!
    val solution = Solution(s)
    solution.solve()
}
