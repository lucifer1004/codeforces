fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

class UnionFind(private val n: Int) {
    private val parent = IntArray(n) { it }
    private val size = IntArray(n) { 1 }
    private fun find(u: Int): Int {
        return if (parent[u] == u)
            u
        else {
            parent[u] = find(parent[u])
            parent[u]
        }
    }

    fun connect(u: Int, v: Int) {
        val fu = find(u)
        val fv = find(v)
        if (fu != fv) {
            if (size[fu] > size[fv]) {
                parent[fv] = fu
                size[fu] += size[fv]
            } else {
                parent[fu] = fv
                size[fv] += size[fu]
            }
        }
    }

    fun groups(): List<MutableList<Int>> {
        val g = mutableMapOf<Int, MutableList<Int>>()
        for (i in 0 until n) {
            val fi = find(i)
            if (g.containsKey(fi))
                g[fi]!!.add(i)
            else
                g[fi] = mutableListOf(i)
        }
        return g.values.toList()
    }
}

fun main() {
    val (n, m, w) = readInts()
    val weight = readInts()
    val beauty = readInts()
    val uf = UnionFind(n)
    for (i in 0 until m) {
        val (u, v) = readInts()
        uf.connect(u - 1, v - 1)
    }
    val groups = uf.groups()
    var dp = IntArray(w + 1)
    for (group in groups) {
        var tw = 0
        var tb = 0
        val ndp = dp.clone()
        for (member in group) {
            tw += weight[member]
            tb += beauty[member]
            for (i in weight[member] until w + 1)
                ndp[i] = ndp[i].coerceAtLeast(dp[i - weight[member]] + beauty[member])
        }
        for (i in tw until w + 1)
            ndp[i] = ndp[i].coerceAtLeast(dp[i - tw] + tb)
        dp = ndp
    }
    println(dp[w])
}
