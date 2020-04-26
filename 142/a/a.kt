fun readInt(): Int {
    return readLine()!!.toInt()
}

fun main() {
    val n = readInt()
    var lo = Long.MAX_VALUE
    var hi = 0L
    val factors = sortedSetOf<Int>()
    var a = 0
    while (a * a <= n) {
        a++
        if (n % a != 0)
            continue
        factors.add(a)
        factors.add(n / a)
    }
    for (a in factors) {
        for (b in factors) {
            if (b * b > n / a)
                continue
            if (n / a % b != 0)
                continue
            val c = n / a / b
            val curr = (a + 1).toLong() * (b + 2).toLong() * (c + 2).toLong()
            lo = lo.coerceAtMost(curr)
            hi = hi.coerceAtLeast(curr)
        }
    }
    print(mutableListOf(lo - n, hi - n).joinToString(" "))
}
