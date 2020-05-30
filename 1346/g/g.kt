import kotlin.system.exitProcess

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

const val MAXN = 1000000

tailrec fun gcd(x: Int, y: Int): Int {
    return if (y == 0) {
        x
    } else {
        gcd(y, x % y)
    }
}

fun main() {
    val (k, n) = readInts()
    val p = readInts()
    val x = readInts()
    val output = { a: Int, b: Int, c: Int, d: Int ->
        println("YES")
        println(listOf(a, b).joinToString(" "))
        println(listOf(c, d).joinToString(" "))
        exitProcess(0)
    }
    if (n == 2)
        output(x[0], p[0], x[1], p[0])
    val can = BooleanArray(MAXN + 1)
    for (i in p)
        can[i] = true
    val solve = { start: Int, delta: Int ->
        var i = 1
        val factors = mutableSetOf<Int>()
        while (i * i <= delta) {
            if (delta % i == 0) {
                if (can[i])
                    factors.add(i)
                if (can[delta / i])
                    factors.add(delta / i)
            }
            i++
        }
        val candidates = mutableListOf<Int>()
        for (a in factors) {
            var ok = true
            for (b in factors)
                if (a % b == 0 && a != b) {
                    ok = false
                    break
                }
            if (ok)
                candidates.add(a)
        }
        for (p1 in candidates) {
            val rest = mutableListOf<Int>()
            for (xi in x)
                if ((xi - start) % p1 != 0)
                    rest.add(xi)
            if (rest.isEmpty())
                output(start, p1, 1, p[0])
            if (rest.size == 1)
                output(start, p1, rest[0], p[0])
            val intervals = mutableListOf<Int>()
            for (j in 0 until rest.size - 1)
                intervals.add(rest[j + 1] - rest[j])
            var y = 0
            for (interval in intervals)
                y = gcd(y, interval)
            i = 1
            while (i * i <= y) {
                if (y % i == 0) {
                    if (can[i])
                        output(start, p1, rest[0], i)
                    if (can[y / i])
                        output(start, p1, rest[0], y / i)
                }
                i++
            }
        }
    }
    solve(x[0], x[1] - x[0])
    solve(x[0], x[2] - x[0])
    solve(x[1], x[2] - x[1])
    println("NO")
}
