fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val n = readInt()
    val a = readInts().sorted()
    var ans = 0
    for (i in 0 until n / 2) {
        ans += a[i * 2 + 1] - a[i * 2]
    }
    println(ans)
}
