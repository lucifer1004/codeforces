fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val (n, w) = readInts()
    val a = readInts()
    var lo = 0
    var hi = 0
    var curr = 0
    for (ai in a) {
        curr += ai
        lo = lo.coerceAtMost(curr)
        hi = hi.coerceAtLeast(curr)
    }
    println((w - hi + lo + 1).coerceAtLeast(0))
}
