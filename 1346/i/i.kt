fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun readLongs(): List<Long> {
    return readLine()!!.split(" ").map(String::toLong)
}

fun mul(a: Array<LongArray>, b: Array<LongArray>): Array<LongArray> {
    val n = a.size
    val ans = Array(n) { LongArray(n) { Long.MAX_VALUE } }
    for (i in 1 until n)
        for (j in 1 until n)
            for (k in 1 until n)
                ans[i][j] = ans[i][j].coerceAtMost(a[i][k] + b[k][j])
    return ans
}

const val MAXD = 51

@kotlin.ExperimentalStdlibApi
fun main() {
    val (n, m, _, s) = readInts()
    val a = readInts()
    var sum = 0L
    for (ai in a)
        sum += ai
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (i in 0 until m) {
        val (u, v) = readInts()
        adj[u].add(v)
    }
    val dist = Array(n + 1) { LongArray(n + 1) }
    val maxCollection = Array(n + 1) { LongArray(n * n + 1) }
    val value = LongArray(1.shl(n))
    for (status in 1 until 1.shl(n)) {
        for (i in 0 until n)
            if (status.and(1.shl(i)) > 0)
                value[status] += a[i].toLong()
    }

    for (i in 1 until n + 1) {
        val vis = Array(n + 1) { BooleanArray(1.shl(n)) }
        val steps = Array(n + 1) { IntArray(1.shl(n)) }
        vis[i][1.shl(i - 1)] = true
        val queue = ArrayDeque<Pair<Int, Int>>()
        queue.add(Pair(i, 1.shl(i - 1)))
        maxCollection[i][0] = a[i - 1].toLong()
        while (queue.isNotEmpty()) {
            val (curr, status) = queue.removeFirst()
            for (nxt in adj[curr]) {
                val nxtStatus = status.or(1.shl(nxt - 1))
                if (!vis[nxt][nxtStatus]) {
                    vis[nxt][nxtStatus] = true
                    steps[nxt][nxtStatus] = steps[curr][status] + 1
                    maxCollection[i][steps[nxt][nxtStatus]] =
                        maxCollection[i][steps[nxt][nxtStatus]].coerceAtLeast(value[nxtStatus])
                    queue.add(Pair(nxt, nxtStatus))
                }
            }
        }
        for (j in 1 until n + 1)
            dist[i][j] = steps[j][1.shl(n) - 1].toLong()
    }
    for (i in 1 until n + 1)
        for (j in 1 until n * n + 1)
            maxCollection[i][j] = maxCollection[i][j].coerceAtLeast(maxCollection[i][j - 1])
    val bSearch = { start: Int, rem: Long ->
        var l = 0
        var r = n * n
        while (l <= r) {
            val mid = (l + r) / 2;
            if (maxCollection[start][mid] < rem)
                l = mid + 1
            else
                r = mid - 1
        }
        l.toLong()
    }

    val memo = Array(MAXD) { Array(n + 1) { LongArray(n + 1) } }
    memo[0] = dist
    for (i in 1 until MAXD)
        memo[i] = mul(memo[i - 1], memo[i - 1])

    val c = readLongs()
    val query = { target: Long ->
        var lo = Long.MAX_VALUE
        val rep = target / sum
        val rem = target % sum
        var init = false
        var d = Array(n + 1) { LongArray(n + 1) }
        for (i in MAXD - 1 downTo 0) {
            if (rep.and(1L.shl(i)) > 0)
                if (init) {
                    d = mul(d, memo[i])
                } else {
                    init = true
                    d = memo[i]
                }
        }
        if (rep == 0L) {
            lo = lo.coerceAtMost(bSearch(s, rem))
        } else
            for (end in 1 until n + 1) {
                lo = lo.coerceAtMost(d[s][end] + bSearch(end, rem))
            }
        lo
    }
    val ans = mutableListOf<Long>()
    for (ci in c)
        ans.add(query(ci))
    println(ans.joinToString("\n"))
}
