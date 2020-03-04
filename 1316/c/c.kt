fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val (n, m, p) = readInts()
    val a = readInts()
    val b = readInts()
    var i = 0
    while (a[i] % p == 0)
        i++
    var j = 0
    while (b[j] % p == 0)
        j++
    println(i + j)
}
