fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun searchLastNonGreater(a: List<Int>, x: Int) {
    var l = 0
    var r = a.size - 1
    while (l <= r) {
        val mid = (l + r) / 2
        if (a[mid] <= x)
            l = mid + 1
        else
            r = mid - 1
    }
    println(r + 1)
}

fun main() {
    readInts()
    val a = readInts()
    val q = readInts()
    for (i in q) 
        searchLastNonGreater(a, i)
}
