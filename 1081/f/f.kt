fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun query(l: Int, r: Int): Int {
    println("? $l $r")
    return readInt()
}

fun main() {
    val (n, t) = readInts()
    if (n == 1) {
        println("! $t")
        return
    }
    val s = IntArray(n + 1)
    s[n] = t
    val add = n % 2
    for (i in 1 until n) {
        var left = 0
        var right = 0
        var current = t
        var delta = 0
        // Query left
        while (!(left == 1 && right == 0)) {
            val result = query(i, i + add)
            delta = result - current
            current = result
            if ((i + add - delta) % 2 == 0)
                left = left.xor(1)
            else
                right = right.xor(1)
        }
        s[i + add] = (i + add - (current - t)) / 2
        // Restore
        while (!(left == 0 && right == 0)) {
            val result = query(i, i + add)
            delta = result - current
            current = result
            if ((i + add - delta) % 2 == 0)
                left = left.xor(1)
            else
                right = right.xor(1)
        }
    }
    if (add == 1) {
        // Extra query when n is odd
        // (2, n)
        var left = 0
        var right = 0
        var current = t
        var delta = 0
        while (!(left == 1 && right == 0)) {
            val result = query(2, n)
            delta = result - current
            current = result
            if (delta % 2 == 0)
                left = left.xor(1)
            else
                right = right.xor(1)
        }
        s[1] = t - (n - 1 - (current - t)) / 2;
    }
    val a = IntArray(n) { s[it + 1] - s[it] }
    println("! ${a.joinToString("")}")
}