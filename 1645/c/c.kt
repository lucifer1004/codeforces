fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val n = readInt()
    val a = readInts().toMutableList()
    a.sort()
    val ans = (0 until n step 2).map { a[it + 1] - a[it] }.sum()
    println(ans)
}
