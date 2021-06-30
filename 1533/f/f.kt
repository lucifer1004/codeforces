fun main() {
    val s = readLine()!!
    val n = s.length
    val ans = IntArray(n)
    val p = IntArray(n + 1)
    val q = IntArray(n + 1)
    for (i in 1 until n + 1) {
        p[i] = p[i - 1]
        q[i] = q[i - 1]
        if (s[i - 1] == '0')
            p[i]++
        else
            q[i]++
    }

    fun run(limit: Int): Int {
        var ans = 0
        var ptr = 0
        while (ptr < n) {
            var lo = ptr + 1
            var hi = n
            while (lo <= hi) {
                val mid = (lo + hi) / 2
                val zero = p[mid] - p[ptr]
                val one = q[mid] - q[ptr]
                if (zero > limit && one > limit)
                    hi = mid - 1
                else
                    lo = mid + 1
            }
            ans++
            ptr = hi
        }
        return ans
    }

    fun solve(l: Int, r: Int) {
        if (l > r)
            return
        if (ans[l] == 0)
            ans[l] = run(l + 1)
        if (ans[r] == 0)
            ans[r] = run(r + 1)
        if (ans[l] == ans[r])
            return
        val mid = (l + r) / 2
        solve(l, mid)
        solve(mid + 1, r)
    }

    solve(0, n - 1)

    for (i in 1 until n) {
        if (ans[i] == 0)
            ans[i] = ans[i - 1]
    }

    println(ans.joinToString(" "))
}
