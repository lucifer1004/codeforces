fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    readInt()
    val a = readInts().reversed().toSet().toList().reversed()
    println(a.size)
    println(a.joinToString(" "))
}
