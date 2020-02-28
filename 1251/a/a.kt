fun readInt(): Int {
    return readLine()!!.toInt()
}

class Solution {
    fun solve() {
        val str = readLine()!!
        var current = '$'
        var count = 0
        val work = sortedSetOf<Char>()
        for (c in "${str}#") {
            if (c == current)
                count++
            else {
                if (count % 2 == 1)
                    work.add(current)
                current = c
                count = 1
            }
        }
        println(work.joinToString(""))
    }
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val solution = Solution()
        solution.solve()
    }
}
