fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val t = readInt()
    for (caseNum in 1 until t + 1) {
        val (n, k) = readInts()
        var ans = 0
        for (i in 1 until n + 1) {
            val (l, r) = readInts()
            if (k in l..r)
                ans = ans.coerceAtLeast(r - l.coerceAtLeast(k) + 1)
        }
        println(ans)
    }
}
