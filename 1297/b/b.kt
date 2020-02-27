import java.math.BigInteger
import java.util.*

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

fun main() {
    val t = readInt()
    for (caseNum in 1 until t + 1) {
        val n = readInt()
        val a = mutableListOf<Int>()
        val b = mutableListOf<Int>()
        for (i in 0 until n) {
            val (ai, bi) = readInts()
            a.add(ai)
            b.add(bi)
        }
        val s = a.toSet().union(b.toSet()).union(b.map { it + 1 }.toSet()).toSortedSet()
        val sl = s.toIntArray()
        val dict = mutableMapOf<Int, Int>()
        var idx = 0
        for (si in s)
            dict[si] = idx++
        val end = Array<MutableList<Int>>(s.size) { mutableListOf() }
        for (i in 0 until n)
            end[dict[a[i]]!!].add(dict[b[i]]!!)
        val active = PriorityQueue<Int>()
        var ok = false
        for (i in 0 until s.size) {
            for (endTime in end[i])
                active.add(endTime)
            if (active.size == 1) {
                println(sl[i])
                ok = true
                break
            }
            while (active.isNotEmpty() && active.peek() == i)
                active.poll()
        }
        if (!ok)
            println(-1)
    }
}
