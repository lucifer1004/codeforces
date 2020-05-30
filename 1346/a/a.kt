fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val (n, k) = readInts()
        val n1 = n / (1 + k + k * k + k * k * k)
        println(listOf(n1, n1 * k, n1 * k * k, n1 * k * k * k).joinToString(" "))
    }
}
