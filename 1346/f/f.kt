import kotlin.math.abs

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val (n, m, q) = readInts()
    val mat = mutableListOf<MutableList<Int>>()
    for (i in 0 until n) {
        mat.add(readInts().toMutableList())
    }
    val ans = mutableListOf<Long>()
    val row = LongArray(n)
    val col = LongArray(m)
    var sum = 0L
    for (i in 0 until n) {
        for (j in 0 until m) {
            row[i] += mat[i][j].toLong()
            col[j] += mat[i][j].toLong()
            sum += mat[i][j]
        }
    }
    val solveOnce = { arr: LongArray, s: Long ->
        val mid = (s + 1) / 2
        var count = 0L
        var target = -1
        for ((idx, ai) in arr.withIndex()) {
            count += ai
            if (count >= mid) {
                target = idx
                break
            }
        }
        var cost = 0L
        for ((idx, ai) in arr.withIndex())
            cost += ai * abs(target - idx)
        cost
    }
    val solve = { solveOnce(row, sum) + solveOnce(col, sum) }
    ans.add(solve())
    for (i in 0 until q) {
        val (x, y, z) = readInts()
        val delta = (z - mat[x - 1][y - 1]).toLong()
        row[x - 1] += delta
        col[y - 1] += delta
        sum += delta
        mat[x - 1][y - 1] = z
        ans.add(solve())
    }
    println(ans.joinToString(" "))
}
