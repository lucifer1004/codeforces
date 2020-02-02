fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

class Solution(private val x: Int, private val y: Int) {
    fun solve() {
        val common = x.coerceAtMost(y) - 1
        println(listOf(x - common, y - common, common).joinToString(" "))
    }
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val (x, y) = readInts()
        val solution = Solution(x, y)
        solution.solve()
    }
}
