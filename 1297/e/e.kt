import java.math.BigInteger

fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readLong(): Long {
    return readLine()!!.toLong()
}

fun readBigInt(): BigInteger {
    return readLine()!!.toBigInteger()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun readLongs(): List<Long> {
    return readLine()!!.split(" ").map(String::toLong)
}

fun readBigInts(): List<BigInteger> {
    return readLine()!!.split(" ").map(String::toBigInteger)
}

class Solution(private val n: Int, private val k: Int) {
    private val adj = Array<MutableSet<Int>>(n + 1) { mutableSetOf() }
    private val leaves = IntArray(n + 1)
    private val ans = mutableSetOf<Int>()
    private var found = false

    private fun outputDFS(u: Int) {
        ans.add(u)
        for (v in adj[u])
            outputDFS(v)
    }

    private fun output() {
        if (ans.isEmpty())
            println("No")
        else {
            println("Yes")
            println(ans.size)
            println(ans.joinToString(" "))
        }
    }

    private fun dfs(u: Int) {
        for (v in adj[u]) {
            adj[v].remove(u)
            dfs(v)
            leaves[u] += leaves[v]
        }
        if (leaves[u] == 0)
            leaves[u] = 1
    }

    private fun rec(u: Int, target: Int) {
        if (found || target == 0) return
        ans.add(u)
        var rest = target
        for (v in adj[u]) {
            val additionalLeaf = if (u == 1) 1 else 0
            if (leaves[v] + additionalLeaf >= target) {
                rec(v, target - additionalLeaf)
                found = true
                return
            }
        }

        for (v in adj[u]) {
            if (rest == 0)
                break
            if (leaves[v] > rest) {
                rec(v, rest)
                break
            } else {
                outputDFS(v)
                rest -= leaves[v]
            }
        }
    }

    fun solve() {
        for (i in 1 until n) {
            val (u, v) = readInts()
            adj[u].add(v)
            adj[v].add(u)
        }

        dfs(1)
        val additionalLeaf = if (adj[1].size == 1) 1 else 0
        val maxLeaves = leaves[1] + additionalLeaf
        if (maxLeaves >= k)
            rec(1, k)
        output()
    }
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val (n, k) = readInts()
        val solution = Solution(n, k)
        solution.solve()
    }
}
