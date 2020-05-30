fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val (n, m, k) = readInts()
    val dp = IntArray(n + 1) { -1 }
    dp[k] = 0
    for (i in 0 until m) {
        val (x, y) = readInts()
        val check = { p: Int, q: Int ->
            when {
                dp[p] == -1 && dp[q] == -1 -> -1
                dp[p] == -1 -> dp[q]
                dp[q] == -1 -> dp[p] + 1
                else -> (dp[p] + 1).coerceAtMost(dp[q])
            }
        }
        val nx = check(x, y)
        val ny = check(y, x)
        dp[x] = nx
        dp[y] = ny
    }
    println(dp.slice(1..n).joinToString(" "))
}
