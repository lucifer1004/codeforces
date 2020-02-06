fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

class Solution(private val n: Int, private val a: List<Int>) {
    fun solve() {
        if (n == 1 || (n == 2 && a[0] == a[1])) {
            println(-1)
            return
        }
        var lo = Int.MAX_VALUE
        var loIndex = -1
        for ((i, value) in a.withIndex()) {
            if (value < lo) {
                lo = value
                loIndex = i
            }
        }
        println(1)
        println(loIndex + 1)
    }
}

fun main() {
    val n = readInt()
    val a = readInts()
    val solution = Solution(n, a)
    solution.solve()
}
