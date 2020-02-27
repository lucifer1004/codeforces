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
        val n = readInt()
        val a = readInts()
        val minPositive = a.fold(10001) { acc, i -> acc.coerceAtMost(if (i > 0) i else acc) }
        val maxNegative = a.fold(-10001) { acc, i -> acc.coerceAtLeast(if (i < 0) i else acc) }
        val ans = IntArray(n) { if (a[it] > 0) 1 else 0 }
        if (minPositive > -maxNegative) {
            var i = 0
            while (a[i] != maxNegative)
                i++
            ans[i] = 1
        } else {
            var i = 0
            while (a[i] != minPositive)
                i++
            ans[i] = 0
        }
        val sum = a.foldIndexed(0) { idx, acc, i -> acc + a[idx] * ans[idx] }
        results.add(sum.toString())
        results.add(ans.joinToString(""))
    }
    println(results.joinToString("\n"))
}
