import java.util.*

fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

const val INF = 0x3f3f3f3f;

fun main() {
    val (n, m) = readInts()
    val out = Array(n + 1) { mutableListOf<Int>() }
    val into = Array(n + 1) { mutableListOf<Int>() }
    for (i in 0 until m) {
        val (u, v) = readInts()
        out[u].add(v)
        into[v].add(u)
    }
    val q: Queue<Int> = LinkedList<Int>()
    val k = readInt()
    val p = readInts()
    q.add(p.last())
    val dist = IntArray(n + 1) { INF }
    val pre = Array(n + 1) { mutableSetOf<Int>() }
    dist[p.last()] = 0
    while (q.isNotEmpty()) {
        val u = q.poll()
        for (v in into[u]) {
            if (dist[u] + 1 < dist[v]) {
                pre[v].clear()
                pre[v].add(u)
                dist[v] = dist[u] + 1
                q.add(v)
            } else if (dist[u] + 1 == dist[v])
                pre[v].add(u)
        }
    }
    var lo = 0
    var hi = 0
    for (i in 0 until k - 1) {
        val u = p[i]
        val v = p[i + 1]
        if (pre[u].contains(v) && pre[u].size > 1)
            hi++
        if (!pre[u].contains(v)) {
            lo++
            hi++
        }
    }
    println(listOf(lo, hi).joinToString(" "))
}
