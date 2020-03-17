fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

const val INF = Long.MAX_VALUE / 2

fun main() {
    val n = readInt()
    var dp = LongArray(n * 2 + 1) { INF }
    dp[n] = 0
    for (i in 0 until n) {
        val (t, c) = readInts()
        val ndp = LongArray(n * 2 + 1) { INF }
        for (j in 0 until n * 2 + 1) {
            val steal = j - 1
            if (steal >= 0)
                ndp[steal] = ndp[steal].coerceAtMost(dp[j])
            val buy = (j + t).coerceAtMost(2 * n)
            ndp[buy] = ndp[buy].coerceAtMost(dp[j] + c)
        }
        dp = ndp
    }
    var ans = INF
    for (i in n until n * 2 + 1)
        ans = ans.coerceAtMost(dp[i])
    println(ans)
}
