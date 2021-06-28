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
        println((0 until n).map { (it % k + 'a'.toInt()).toChar() }.joinToString("")) // Should use 'a'.code in higher version of Kotlin
    }
}
