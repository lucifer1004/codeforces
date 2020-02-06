fun readLongs(): List<Long> {
    return readLine()!!.split(" ").map(String::toLong)
}

class Solution() {
    fun solve() {
        val (n, x, y) = readLongs()
        val a = readLine()!!
        var successiveZeroIntervals = 0L
        var count = 0L
        for (c in a) {
            if (c == '1') {
                if (count > 0) {
                    successiveZeroIntervals++
                    count = 0
                }
            } else
                count++
        }
        if (count > 0)
            successiveZeroIntervals++
        val ans = (successiveZeroIntervals * y).coerceAtMost(y + (successiveZeroIntervals - 1) * x)
        println(ans.coerceAtLeast(0))
    }
}

fun main() {
    val solution = Solution()
    solution.solve()
}
