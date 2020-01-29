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

class Solution(private val n: Int, private val a: List<Int>) {
    fun solve() {
        
    }
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val n = readInt()
        val a = readInts()
        val solution = Solution(n, a)
        solution.solve()
    }
}
