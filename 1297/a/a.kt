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

const val K = 1000
const val M = 1000000

class Solution(private val n: Int) {
    fun solve() {
        if (n <= 999)
            println(n)
        else {
            if (n <= 999499) {
                var k = n / K
                if ((k + 1) * K - n <= n % K)
                    k++
                println("${k}K")
            } else {
                var m = n / M
                if ((m + 1) * M - n <= n % M)
                    m++
                println("${m}M")
            }
        }
    }
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val n = readInt()
        val solution = Solution(n)
        solution.solve()
    }
}
