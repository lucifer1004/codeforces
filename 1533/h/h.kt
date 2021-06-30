import java.util.*

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val (n, m) = readInts()
    val mat = Array(n) { IntArray(m) }
    for (i in 0 until n) {
        val s = readLine()!!
        for (j in 0 until m)
            mat[i][j] = s[j].toInt() - 'A'.toInt()
    }

    val ans = LongArray(5)
    val memo = LongArray(32)
    for (k in 1 until 32) {
        val pc = Integer.bitCount(k)

        val f = Array(n) { IntArray(m) }
        for (i in 0 until n)
            for (j in 0 until m) {
                if (1.shl(mat[i][j]).and(k) != 0) {
                    f[i][j] = 1
                    if (i > 0)
                        f[i][j] += f[i - 1][j]
                }
            }

        var cnt = 0L
        for (i in 0 until n) {
            val stk = mutableListOf<Pair<Int, Int>>()
            val row = f[i].toMutableList()
            row.add(0)
            for (j in 0 until m + 1) {
                var cpos = j
                while (stk.isNotEmpty() && row[j] < stk.last().first) {
                    val (height, pos) = stk.removeAt(stk.size - 1)
                    val width = j - pos
                    val deltaHeight = if (stk.isNotEmpty()) {
                        height - stk.last().first.coerceAtLeast(row[j])
                    } else {
                        height - row[j]
                    }
                    cnt += 1L * width * (width + 1) / 2 * deltaHeight
                    cpos = pos
                }

                if (stk.isEmpty() || row[j] > stk.last().first)
                    stk.add(Pair(row[j], cpos))
            }
        }

        memo[k] = cnt
        for (i in 1 until k) {
            if (i.and(k) == i) {
                val pc1 = Integer.bitCount(i)
                if ((pc - pc1) % 2 == 0)
                    cnt += memo[i]
                else
                    cnt -= memo[i]
            }
        }

        ans[pc - 1] += cnt
    }

    println(ans.joinToString(" "))
}
