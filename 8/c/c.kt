fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun dist(a: Pair<Int, Int>, b: Pair<Int, Int>): Int {
    val dx = a.first - b.first
    val dy = a.second - b.second
    return dx * dx + dy * dy
}

class Solution(private val origin: Pair<Int, Int>, private val items: MutableList<Pair<Int, Int>>) {
    private val n = items.size
    private val dp = IntArray(1 shl n) { Int.MAX_VALUE }
    private val pre = IntArray(1 shl n) { -1 }

    private fun match(idx: Int) {
        var i = 0
        while (idx and (1 shl i) != 0)
            i++
        val update = { newValue: Int, newIdx: Int ->
            if (dp[newIdx] > newValue) {
                dp[newIdx] = newValue
                pre[newIdx] = idx
                match(newIdx)
            }
        }
        if (i < n) update(dp[idx] + dist(items[i], origin), idx + (1 shl i))

        for (j in i + 1 until n) {
            if (idx and (1 shl j) != 0) continue
            update(dp[idx] + dist(items[i], items[j]), idx + (1 shl i) + (1 shl j))
        }
    }

    fun solve() {
        dp[0] = 0
        for (i in 0 until n)
            dp[0] += dist(items[i], origin)
        match(0)
        println(dp[(1 shl n) - 1])
        val path = mutableListOf(0)
        var curr = (1 shl n) - 1
        while (curr != -1) {
            if (pre[curr] != -1) {
                val diff = curr - pre[curr]
                for (i in 0 until n) {
                    if (diff and (1 shl i) != 0)
                        path.add(i + 1)
                }
                path.add(0)
            }
            curr = pre[curr]
        }
        println(path.joinToString(" "))
    }
}

fun main() {
    val (x, y) = readInts()
    val origin = Pair(x, y)
    val n = readInt()
    val items = mutableListOf<Pair<Int, Int>>()
    for (i in 0 until n) {
        val (xi, yi) = readInts()
        items.add(Pair(xi, yi))
    }
    val solution = Solution(origin, items)
    solution.solve()
}
