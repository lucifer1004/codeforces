// Did not pass all tests because of slow I/O

fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

class Solution(private val n: Int, private val k: Int, private val a: List<Int>) {
    fun solve() {
        var curr = 0L
        val ans = mutableListOf<Int>()
        for (right in 0 until n) {
            curr += a[right].toLong()
            if (curr % 2 == 1L && ans.size < k) {
                ans.add(right + 1)
                curr = 0
            }
        }
        if (ans.size == k && curr % 2 == 0L) {
            ans[k - 1] = n
            println("YES")
            println(ans.joinToString(" "))
        } else
            println("NO")

    }
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val (n, k) = readInts()
        val a = readInts()
        val solution = Solution(n, k, a)
        solution.solve()
    }
}
