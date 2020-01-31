fun readInt(): Int {
    return readLine()!!.toInt()
}

class Solution(private val n: Int, d: Int, e: Int) {
    private val dollar = d
    private val euro = e * 5
    private var remain = n
    fun solve() {
        var i = 0
        while (i * euro <= n) {
            remain = remain.coerceAtMost((n - i * euro) % dollar)
            i++
        }
        println(remain)
    }
}

fun main() {
    val n = readInt()
    val d = readInt()
    val e = readInt()
    val solution = Solution(n, d, e)
    solution.solve()
}
