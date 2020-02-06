fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun readLongs(): List<Long> {
    return readLine()!!.split(" ").map(String::toLong)
}

fun gcd(a: Long, b: Long): Long {
    return if (b == 0L)
        a
    else
        gcd(b, a % b)
}

const val MOD: Long = 1000000007L

class Solution(private val n: Int, private val beauty: List<Long>) {
    private val parent = IntArray(n)
    private val adj = Array<MutableList<Int>>(n) { mutableListOf() }
    private val distinctResults = Array<MutableMap<Long, Long>>(n) { mutableMapOf()}
    private var sum: Long = 0
    private fun dfs(i: Int) {
        distinctResults[i][beauty[i]] = 1
        if (parent[i] != i) {
            for (result in distinctResults[parent[i]]) {
                val newValue = gcd(beauty[i], result.key)
                if (distinctResults[i].containsKey(newValue))
                    distinctResults[i][newValue] = distinctResults[i][newValue]!! + result.value
                else
                    distinctResults[i][newValue] = result.value
            }
        }
        for (result in distinctResults[i])
            sum += result.key * result.value % MOD
        sum %= MOD
        for (child in adj[i]) {
            if (distinctResults[child].isNotEmpty()) continue
            parent[child] = i
            dfs(child)
        }
    }

    fun solve() {
        for (i in 0 until n - 1) {
            var (u, v) = readInts()
            u--
            v--
            adj[u].add(v)
            adj[v].add(u)
        }
        dfs(0)
        println(sum)
    }
}

fun main() {
    val n = readInt()
    val beauty = readLongs()
    val solution = Solution(n, beauty)
    solution.solve()
}
