fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

class Edge(val to: Int, val cost: Long)

class Tree(private val n: Int) {
    private val adj = Array<MutableList<Edge>>(n + 1) { mutableListOf() }
    private val size = LongArray(n + 1)
    private var lo: Long = 0
    private var hi: Long = 0
    fun add(u: Int, v: Int, cost: Long) {
        adj[u].add(Edge(v, cost))
        adj[v].add(Edge(u, cost))
    }

    fun dfs(root: Int) {
        size[root] = 1
        for (edge in adj[root]) {
            if (size[edge.to] == 0L) {
                dfs(edge.to)
                size[root] += size[edge.to]
                lo += size[edge.to] % 2 * edge.cost
                hi += size[edge.to].coerceAtMost(n - size[edge.to]) * edge.cost
            }
        }
    }

    fun solve() {
        dfs(1)
        println(listOf(lo, hi).joinToString(" "))
    }
}

class Solution() {
    fun solve() {
        val n = readInt()
        val tree = Tree(2 * n)
        for (i in 0 until 2 * n - 1) {
            val (u, v, cost) = readInts()
            tree.add(u, v, cost.toLong())
        }
        tree.solve()
    }
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val solution = Solution()
        solution.solve()
    }
}
