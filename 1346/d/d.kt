fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

data class Edge(val u: Int, val v: Int, val w: Int)

fun main() {
    val t = readInt()
    val answer = mutableListOf<String>()
    for (i in 1 until t + 1) {
        val (n, m) = readInts()
        val lo = IntArray(n + 1)
        val edges = mutableListOf<Edge>()
        for (j in 0 until m) {
            val (u, v, w) = readInts()
            lo[u] = lo[u].coerceAtLeast(w)
            lo[v] = lo[v].coerceAtLeast(w)
            edges.add(Edge(u, v, w))
        }
        var ok = true
        for (edge in edges) {
            if (lo[edge.u].coerceAtMost(lo[edge.v]) != edge.w) {
                ok = false
                break
            }
        }
        if (ok) {
            answer.add("YES")
            answer.add(lo.slice(1..n).joinToString(" "))
        } else
            answer.add("NO")
    }
    println(answer.joinToString("\n"))
}
