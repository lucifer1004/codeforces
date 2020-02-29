import kotlin.math.abs

fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

data class Heater(val x: Int, val y: Int, val r: Int)

fun main() {
    val (xa, ya, xb, yb) = readInts()
    val l = xa.coerceAtMost(xb)
    val r = xa.coerceAtLeast(xb)
    val d = ya.coerceAtMost(yb)
    val u = ya.coerceAtLeast(yb)
    val n = readInt()
    val heaters = mutableListOf<Heater>()
    for (i in 0 until n) {
        val (xi, yi, ri) = readInts()
        heaters.add(Heater(xi, yi, ri))
    }
    val check = {x: Int, y: Int ->
        var ok = false
        for (heater in heaters) {
            val dx = abs(x - heater.x)
            val dy = abs(y - heater.y)
            if (dx * dx + dy * dy <= heater.r * heater.r) {
                ok = true
                break
            }
        }
        if (ok) 1 else 0
    }
    var count = 0
    for (i in l until r)
        count += check(i, u)
    for (i in u downTo d + 1)
        count += check(r, i)
    for (i in r downTo l + 1)
        count += check(i, d)
    for (i in d until u)
        count += check(l, i)
    println(2 * (r - l + u - d) - count)
}
