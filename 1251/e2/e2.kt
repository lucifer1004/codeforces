import java.util.*

fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun solve() {
    val n = readInt()
    val p = mutableListOf<Int>()
    val m = mutableListOf<Int>()
    val vote = Array(n + 1) { mutableSetOf<Int>() }
    for (i in 0 until n) {
        val (mi, pi) = readInts()
        m.add(mi)
        p.add(pi)
        vote[mi].add(i)
    }
    val votersToBuy = PriorityQueue<Int>()
    val prev = IntArray(n + 1)
    for (i in 0 until n)
        prev[i + 1] = prev[i] + vote[i].size
    var minCost = 0L
    var currentVoter = 0
    for (i in n downTo 0) {
        for (voter in vote[i])
            votersToBuy.add(p[voter])
        while (prev[i] + currentVoter < i) {
            minCost += votersToBuy.poll()
            currentVoter++
        }
    }
    println(minCost)
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1)
        solve()
}
