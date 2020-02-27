import java.math.BigInteger
import java.util.*
import kotlin.math.max

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

class Solution {
    fun solve() {
        val (n, m) = readInts()
        val a = mutableListOf<Int>()
        val b = mutableListOf<Int>()
        for (i in 0 until n) {
            val (ai, bi) = readInts()
            a.add(ai)
            b.add(bi)
        }
        val s = a.toSet().union(b.toSet()).toSortedSet()
        s.add(Int.MAX_VALUE)
        val sl = s.toIntArray()
        val dict = mutableMapOf<Int, Int>()
        val end = Array<MutableList<Pair<Int, Int>>>(s.size) { mutableListOf() }
        var idx = 0
        for (si in s)
            dict[si] = idx++
        for (i in 0 until n)
            end[dict[a[i]]!!].add(Pair(dict[b[i]]!!, i))
        val schedule = IntArray(n)
        val pq = PriorityQueue<Pair<Int, Int>>(compareBy({ it.first }, { it.second }))
        for (i in 0 until s.size - 1) {
            for (movie in end[i])
                pq.add(movie)
            for (t in sl[i] until sl[i + 1]) {
                for (j in 0 until m) {
                    if (pq.isNotEmpty()) {
                        val top = pq.poll()
                        schedule[top.second] = t
                    }
                    if (pq.isEmpty())
                        break
                }
                if (pq.isEmpty())
                    break
            }
        }
        var maxDelay = 0
        for (i in 0 until n)
            maxDelay = maxDelay.coerceAtLeast(schedule[i] - b[i])
        println(maxDelay)
        println(schedule.joinToString(" "))
    }
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val solution = Solution()
        solution.solve()
    }
}
