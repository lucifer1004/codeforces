fun readInt(): Int {
    return readLine()!!.toInt()
}

class Solution(private val s: String, private val t: String) {
    fun solve() {
        val lenS = s.length
        val lenT = t.length
        if (lenS < lenT) {
            println("NO")
            return
        }
        var si = 0
        var ti = 0
        while (si < lenS && ti < lenT) {
            if (s[si] == t[ti]) {
                si++
                ti++
                continue
            }
            if (t[ti] == '+' && si + 1 < lenS && s.substring(si..si + 1) == "--") {
                si += 2
                ti++
                continue
            }
            println("NO")
            return
        }
        if (si == lenS && ti == lenT)
            println("YES")
        else
            println("NO")
    }
}

fun main() {
    val cases = readInt()
    for (i in 1 until cases + 1) {
        val s = readLine()!!
        val t = readLine()!!
        val solution = Solution(s, t)
        solution.solve()
    }
}
