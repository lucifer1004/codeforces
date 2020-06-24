fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readLongs(): List<Long> {
    return readLine()!!.split(" ").map(String::toLong)
}

fun main() {
    val n = readInt()
    val a = readLongs()
    val odd = a.count { it % 2L == 1L }
    var can = true
    if (odd % 2 == 1)
        can = false
    val hi = a.max()!!
    val sum = a.sum()
    val rest = sum - hi
    if (hi > rest)
        can = false
    println(if (can) "YES" else "NO")
}
