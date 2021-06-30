fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val n = readInt()
    val a = readInts().sorted()
    val b = readInts().sorted()
    val pre = IntArray(n + 1)
    pre[0] = Int.MIN_VALUE
    for (i in 1 until n + 1) {
        val delta = b[i - 1] - a[i - 1]
        pre[i] = pre[i - 1].coerceAtLeast(delta)
    }

    val suf = IntArray(n + 1)
    suf[0] = Int.MIN_VALUE
    for (i in 1 until n + 1) {
        val delta = b[n + 1 - i] - a[n - i]
        suf[i] = suf[i - 1].coerceAtLeast(delta)
    }

    val m = readInt()
    val ans = readInts().map {
        var lo = 0
        var hi = n - 1
        while (lo <= hi) {
            val mid = (lo + hi) / 2
            if (a[mid] < it)
                lo = mid + 1
            else
                hi = mid - 1
        }

        pre[lo].coerceAtLeast(suf[n - lo]).coerceAtLeast(b[lo] - it)
    }.joinToString(" ")

    println(ans)
}
