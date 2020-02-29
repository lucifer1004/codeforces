fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val n = readInt()
    val a = readInts()
    val biggest = a.max()
    val smallest = a.min()
    var bigIndex = 0
    while (a[bigIndex] != biggest)
        bigIndex++
    var smallIndex = n - 1
    while (a[smallIndex] != smallest)
        smallIndex--
    var ans = n - 1 - smallIndex + bigIndex
    println(if (smallIndex > bigIndex) ans else ans - 1)
}
