fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val a = readInts()
        println(a[0] + a[1])
    }
}
