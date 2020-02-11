fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val (n, x0) = readInts()
    var left = 0
    var right = 1000
    for (i in 0 until n) {
        var (a, b) = readInts()
        if (a > b) {
            val tmp = a
            a = b
            b = tmp
        }
        left = left.coerceAtLeast(a)
        right = right.coerceAtMost(b)
        if (left > right) {
            println(-1)
            return
        }
    }
    println(
        when {
            x0 < left -> left - x0
            x0 > right -> x0 - right
            else -> 0
        }
    )
}
