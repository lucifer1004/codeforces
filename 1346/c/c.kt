fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readLongs(): List<Long> {
    return readLine()!!.split(" ").map(String::toLong)
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val (n, k, x, y) = readLongs()
        val a = readLongs().sortedByDescending { it }
        var sum = a.sum()
        var ans = Long.MAX_VALUE
        if (sum <= k * n)
            ans = y
        for ((idx, num) in a.withIndex()) {
            if (num <= k) {
                ans = ans.coerceAtMost(x * idx.toLong())
                break
            }
            sum -= num
            if (sum <= k * n)
                ans = ans.coerceAtMost(x * (idx + 1).toLong() + if (idx.toLong() != n - 1) {y} else {0})
        }
        println(ans)
    }
}
