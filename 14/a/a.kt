fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val (n, m) = readInts()
    val mat = mutableListOf<String>()
    for (i in 0 until n) {
        val str = readLine()!!
        mat.add(str)
    }
    var left = m
    var right = -1
    var top = n
    var bottom = -1
    for (i in 0 until n)
        for (j in 0 until m)
            if (mat[i][j] != '.') {
                left = left.coerceAtMost(j)
                right = right.coerceAtLeast(j)
                top = top.coerceAtMost(i)
                bottom = bottom.coerceAtLeast(i)
            }
    for (i in top until bottom + 1)
        println(mat[i].substring(left, right + 1))
}
