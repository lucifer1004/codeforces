fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

class UnionFind(private val n: Int) {
    private val f = IntArray(n) { it }
    private val s = IntArray(n) { 1 }

    private fun find(a: Int): Int {
        if (f[a] == a)
            return a;
        f[a] = find(f[a]);
        return f[a];
    }

    fun connect(a: Int, b: Int) {
        val fa = find(a)
        val fb = find(b)
        if (fa != fb) {
            if (s[fa] > s[fb]) {
                f[fb] = fa
                s[fa] += s[fb]
            } else {
                f[fa] = fb
                s[fb] += s[fa]
            }
        }
    }

    fun solve(k: Int) {
        var happy = 0
        for (i in 1 until n) {
            if (find(i) == i)
                happy += s[i] - 1
        }
        val sad = k - happy
        println(sad)
    }
}

fun main() {
    val (n, k) = readInts()
    val uf = UnionFind(n + 1)
    for (i in 0 until k) {
        val (x, y) = readInts()
        uf.connect(x, y)
    }
    uf.solve(k)
}
