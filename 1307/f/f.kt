import java.util.*

fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

const val MAX_LEVEL = 20

class Tree(private val n: Int, private val k: Int) {
    private val adj = Array<MutableList<Int>>(n * 2) { mutableListOf() }
    private val dist = IntArray(n * 2) { -1 }
    private val uf = IntArray(n * 2) { i -> i }
    private val depth = IntArray(n * 2) { -1 }
    private val f = Array<IntArray>(n * 2) { IntArray(MAX_LEVEL) }

    private fun find(a: Int): Int {
        if (uf[a] == a) return a
        uf[a] = find(uf[a])
        return uf[a]
    }

    private fun connect(a: Int, b: Int) {
        val fa = find(a)
        val fb = find(b)
        if (fa != fb)
            uf[fa] = fb
    }

    private fun la(a: Int, delta: Int): Int {
        var u = a
        for (i in MAX_LEVEL - 1 downTo 0)
            if (delta.and(1.shl(i)) != 0)
                u = f[u][i]
        return u
    }

    private fun lca(a: Int, b: Int): Int {
        var u = if (depth[a] < depth[b]) b else a
        var v = a + b - u
        val delta = depth[u] - depth[v]
        u = la(u, delta)
        for (i in MAX_LEVEL - 1 downTo 0)
            if (f[u][i] != f[v][i]) {
                u = f[u][i]
                v = f[v][i]
            }
        return if (u == v) u else f[u][0]
    }

    private fun dfs(u: Int, parent: Int) {
        depth[u] = depth[parent] + 1
        f[u][0] = parent
        for (i in 1 until MAX_LEVEL) {
            f[u][i] = f[f[u][i - 1]][i - 1]
            if (f[u][i] == 0)
                break
        }
        for (v in adj[u])
            if (v != parent)
                dfs(v, u)
    }

    fun build() {
        for (i in 1 until n) {
            val (u, v) = readInts()
            adj[u].add(n + i)
            adj[n + i].add(u)
            adj[v].add(n + i)
            adj[n + i].add(v)
        }
        dfs(1, 0)
        val stops = readInts()
        val q: Queue<Int> = LinkedList<Int>()
        for (stop in stops) {
            q.add(stop)
            dist[stop] = 0
        }
        while (q.isNotEmpty()) {
            val u = q.poll()
            if (dist[u] == k)
                break
            for (v in adj[u]) {
                connect(u, v)
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1
                    q.add(v)
                }
            }
        }
    }

    fun query(u: Int, v: Int): Boolean {
        val w = lca(u, v)
        val left = depth[u] - depth[w]
        val right = depth[v] - depth[w]
        if (left + right <= 2 * k)
            return true
        val nu = if (k <= left) la(u, k) else la(v, left + right - k)
        val nv = if (k <= right) la(v, k) else la(u, left + right - k)
        return find(nu) == find(nv)
    }
}

fun main() {
    val (n, k, r) = readInts()
    val tree = Tree(n, k)
    tree.build()
    val q = readInt()
    val ans = mutableListOf<String>()
    for (i in 0 until q) {
        val (u, v) = readInts()
        ans.add(if (tree.query(u, v)) "YES" else "NO")
    }
    println(ans.joinToString("\n"))
}
