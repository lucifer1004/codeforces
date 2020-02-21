fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val (n, k) = readInts()
    val a = readInts()
    val s = sortedMapOf<Int, MutableList<Int>>()
    val q = Array(n) { mutableSetOf<Int>() }
    for ((idx, ai) in a.withIndex()) {
        if (s.containsKey(ai))
            s[ai]!!.add(idx)
        else
            s[ai] = mutableListOf(idx)
    }
    for (i in 0 until k) {
        val (u, v) = readInts()
        q[u - 1].add(v - 1)
        q[v - 1].add(u - 1)
    }

    var left = 0
    val ans = IntArray(n)
    for (key in s.keys) {
        for (ai in s[key]!!) {
            ans[ai] = left
            for (qi in q[ai])
                if (a[qi] < a[ai])
                    ans[ai]--
        }
        left += s[key]!!.size
    }
    println(ans.joinToString(" "))
}
