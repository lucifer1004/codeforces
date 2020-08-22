fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun searchFirstNonSmaller(a: List<Int>, x: Int): Int {
    var l = 0
    var r = a.size - 1
    while (l <= r) {
        val mid = (l + r) / 2
        if (a[mid] < x)
            l = mid + 1
        else
            r = mid - 1
    }
    return l
}

fun searchLastNonGreater(a: List<Int>, x: Int): Int {
    var l = 0
    var r = a.size - 1
    while (l <= r) {
        val mid = (l + r) / 2
        if (a[mid] <= x)
            l = mid + 1
        else
            r = mid - 1
    }
    return r
}

fun main() {
    readInts()
    val a = readInts().sorted()
    val (q) = readInts()
    for (i in 0 until q) {
      val (l, r) = readInts()
      val left = searchFirstNonSmaller(a, l)
      val right = searchLastNonGreater(a, r)
      print("${right - left + 1} ")
    }
}
