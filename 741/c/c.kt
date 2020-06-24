import kotlin.collections.ArrayDeque

fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

@kotlin.ExperimentalStdlibApi
class Graph(private val n: Int) {
    private val adj = Array(n) { mutableSetOf<Int>() }
    val color = IntArray(n)
    fun connect(u: Int, v: Int) {
        adj[u].add(v)
        adj[v].add(u)
    }
    fun color() {
        for (i in 0 until n) {
            if (color[i] == 0) {
                val q = ArrayDeque<Int>()
                color[i] = 1
                q.add(i)
                while (q.isNotEmpty()) {
                    val u = q.removeFirst()
                    for (v in adj[u]) {
                        if (color[v] == 0) {
                            color[v] = 3 - color[u]
                            q.add(v)
                        }
                    }
                }
            }
        }
    }

}

@kotlin.ExperimentalStdlibApi
fun main() {
    val n = readInt()
    val g = Graph(n * 2)
    for (i in 0 until n)
        g.connect(2 * i, 2 * i + 1)
    val pairs = mutableListOf<Pair<Int, Int>>()
    for (i in 0 until n) {
        val (u, v) = readInts()
        pairs.add(Pair(u - 1, v - 1))
        g.connect(u - 1, v - 1)
    }
    g.color()
    val ans = mutableListOf<String>()
    for (pair in pairs)
        ans.add(listOf(g.color[pair.first], g.color[pair.second]).joinToString(" "))
    println(ans.joinToString("\n"))
}
