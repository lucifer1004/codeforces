fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val n = readInt()
    val a = readInts()
    var mv = -1
    for ((i, v) in a.withIndex()) {
        if (mv == -1 || v >= a[mv])
            mv = i
    }
    println((a[mv].toLong() - 1) * n + mv + 1)
}
