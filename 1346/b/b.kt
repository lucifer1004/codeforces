fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val (n, k1, k2) = readInts()
        var s = readLine()!!
        s += '0'
        var ans = 0
        var count = 0
        for (c in s) {
            if (c == '0') {
                if (count > 0) {
                    ans += if (count % 2 == 0) {
                        (k1 * count).coerceAtMost(k2 * count / 2)
                    } else {
                        (k1 * count).coerceAtMost(k2 * (count / 2) + k1)
                    }
                }
                count = 0
            } else
                count++
        }
        println(ans)
    }
}
