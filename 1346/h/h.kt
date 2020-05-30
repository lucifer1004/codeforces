fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val (n, m) = readInts()
    val start = mutableListOf<Pair<Int, Int>>()
    val terminal = Array(2000001) { mutableListOf<Int>() }
    for (i in 0 until n) {
        val (x, y) = readInts()
        start.add(Pair(x, y))
    }
    for (i in 0 until m) {
        val (x, y) = readInts()
        terminal[x + y].add(x)
    }
    for (i in 1 until 2000001)
        terminal[i].sort()
    val ans = mutableListOf<Int>()
    val bSearch = { list: MutableList<Int>, value: Int ->
        var lo = 0
        var hi = list.size - 1
        while (lo <= hi) {
            val mid = (lo + hi) / 2
            if (list[mid] >= value)
                hi = mid - 1
            else
                lo = mid + 1
        }
        lo
    }
    for ((l, r) in start) {
        var lo = Int.MAX_VALUE
        if (terminal[l + r].isNotEmpty()) {
            val idx = bSearch(terminal[l + r], l)
            if (idx < terminal[l + r].size)
                lo = lo.coerceAtMost((terminal[l + r][idx] - l) * 2)
        }
        if (l + r + 2 <= 2000000 && terminal[l + r - 2].isNotEmpty() && terminal[l + r + 2].isNotEmpty()) {
            var ac = Int.MAX_VALUE
            var bc = Int.MAX_VALUE
            val a = bSearch(terminal[l + r - 2], l)
            if (a < terminal[l + r - 2].size)
                ac = (terminal[l + r - 2][a] - l) * 2 + 2
            val b = bSearch(terminal[l + r + 2], l + 2)
            if (b < terminal[l + r + 2].size)
                bc = (terminal[l + r + 2][b] - l) * 2 - 2
            lo = lo.coerceAtMost(ac.coerceAtLeast(bc))
        }
        ans.add(
            if (lo == Int.MAX_VALUE) {
                -1
            } else {
                lo / 2
            }
        )
    }
    println(ans.joinToString(" "))
}
