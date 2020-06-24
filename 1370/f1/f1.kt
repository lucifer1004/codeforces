fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun query(nodes: MutableList<Int>): List<Int> {
    println("? ${nodes.size} ${nodes.joinToString(" ")}")
    return readInts()
}

fun output(u: Int, v: Int) {
    println("! $u $v")
    readLine()!!
}

class Solution {
    private var maxDepth = 0
    private val depth = mutableListOf<Int>()
    private val parent = mutableListOf<Int>()
    private val adj = mutableListOf<MutableList<Int>>()

    private fun dfs(u: Int, p: Int) {
        parent[u] = p
        depth[u] = if (p == 0) 0 else depth[p] + 1
        maxDepth = maxDepth.coerceAtLeast(depth[u])
        for (v in adj[u]) {
            if (v != p)
                dfs(v, u)
        }
    }

    fun solve() {
        val n = readInt()
        for (i in 0 until n + 1) {
            adj.add(mutableListOf())
            depth.add(0)
            parent.add(0)
        }
        for (i in 0 until n - 1) {
            val (u, v) = readInts()
            adj[u].add(v)
            adj[v].add(u)
        }
        val (root, minDist) = query((1 until n + 1).toMutableList());
        dfs(root, 0)
        val nodes = Array(maxDepth + 1) { mutableListOf<Int>()}
        for (i in 1 until n + 1)
            nodes[depth[i]].add(i)
        var lo = (minDist + 1) / 2
        var hi = maxDepth
        while (lo <= hi) {
            val mid = (lo + hi) shr 1
            val (_, dist) = query(nodes[mid]);
            if (dist > minDist)
                hi = mid - 1
            else
                lo = mid + 1
        }
        val (u, _) = query(nodes[hi])
        var current = u
        while (current != root) {
            nodes[depth[current]] = nodes[depth[current]].filter { it != current }.toMutableList()
            current = parent[current]
        }
        val (v, _) = query(nodes[minDist - hi])
        output(u, v)
    }
}

fun main() {
    val t = readInt()
    for (i in 0 until t) {
        val solution = Solution()
        solution.solve()
    }
}