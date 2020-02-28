fun readInt(): Int {
    return readLine()!!.toInt()
}

class Solution {
    fun solve() {
        val n = readInt()
        val s = mutableListOf<String>()
        var zero = 0
        var one = 0
        var odd = 0
        var even = 0
        for (i in 0 until n) {
            val si = readLine()!!
            s.add(si)
            si.forEach { if (it == '0') zero++ else one++ }
            if (si.length % 2 == 0)
                even++
            else
                odd++
        }
        println(if (one % 2 == 1 && zero % 2 == 1 && odd == 0) n - 1 else n)
    }
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val solution = Solution()
        solution.solve()
    }
}
