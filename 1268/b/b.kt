fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readLongs(): List<Long> {
    return readLine()!!.split(" ").map(String::toLong)
}

class Solution(private val n: Int, private val a: List<Long>) {
    fun solve() {
        var black = 0L
        var white = 0L
        for ((idx, col) in a.withIndex()) {
            if (idx % 2 == 0) {
                black += col / 2
                white += col / 2 + col % 2
            } else {
                black += col / 2 + col % 2
                white += col / 2
            }
        }
        println(black.coerceAtMost(white))
    }
}

fun main() {
    val n = readInt()
    val a = readLongs()
    val solution = Solution(n, a)
    solution.solve()
}
