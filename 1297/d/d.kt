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

fun main() {
    val t = readInt()
    val results = mutableListOf<String>()
    for (caseNum in 1 until t + 1) {
        val (n, k) = readInts()
        val oa = readInts()
        var a = List(n) { Pair(oa[it], it) }
        a = a.sortedWith(compareBy({ it.first }, { it.second }))
        val target = IntArray(n) { a.last().first }
        for (i in n - 2 downTo 0)
            target[i] = target[i + 1] - 1
        val bonus = IntArray(n)
        var remain = k
        for (i in n - 2 downTo 0) {
            bonus[i] = remain.coerceAtMost(target[i] - a[i].first)
            remain -= bonus[i]
            if (remain == 0)
                break
        }
        if (remain > 0) {
            val base = remain / n
            for (i in 0 until n)
                bonus[i] += base
            val right = remain % n
            for (i in 0 until right)
                bonus[n - i - 1]++
        }
        val rawBonus = IntArray(n)
        for (i in 0 until n)
            rawBonus[a[i].second] = bonus[i]
        results.add(rawBonus.joinToString(" "))
    }
    println(results.joinToString("\n"))
}
