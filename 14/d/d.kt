fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

data class Edge(val u: Int, val v: Int)

class Solution(private val n: Int) {
    private val adj = Array(n + 1) { mutableListOf<Int>() }
    private val roots = mutableListOf<Int>()

    constructor(n: Int, edges: MutableList<Edge>, idx: Int) : this(n) {
        roots.add(edges[idx].u)
        roots.add(edges[idx].v)
        for ((i, edge) in edges.withIndex()) {
            if (i != idx) {
                adj[edge.u].add(edge.v)
                adj[edge.v].add(edge.u)
            }
        }
    }

    private fun findMaxDepth(root: Int): Pair<Int, Int> {
        val depth = IntArray(n + 1) { -1 }
        depth[root] = 0
        val bfs = mutableListOf(root)
        var maxDepth = 0
        var maxi = 0
        while (bfs.isNotEmpty()) {
            val u = bfs.first()
            bfs.removeAt(0)
            for (v in adj[u]) {
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1
                    if (depth[v] > maxDepth) {
                        maxDepth = depth[v]
                        maxi = v
                    }
                    bfs.add(v)
                }
            }
        }
        return Pair(maxi, maxDepth)
    }

    private fun findDiameter(root: Int): Int {
        val diameterEndpoint = findMaxDepth(root).first
        return findMaxDepth(diameterEndpoint).second
    }

    fun solve(): Int {
        val left = findDiameter(roots[0])
        val right = findDiameter(roots[1])
        return left * right
    }
}

fun main() {
    val n = readInt()
    val edges = mutableListOf<Edge>()
    for (i in 0 until n - 1) {
        val (u, v) = readInts()
        edges.add(Edge(u, v));
    }
    var ans = 0
    for (i in 0 until n - 1) {
        val solution = Solution(n, edges, i)
        ans = ans.coerceAtLeast(solution.solve())
    }
    println(ans)
}
