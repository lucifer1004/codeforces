fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

typealias Edge = Pair<Pair<Int, Int>, Pair<Int, Int>>

fun main() {
    var left = Int.MAX_VALUE
    var right = Int.MIN_VALUE
    var top = Int.MIN_VALUE
    var bottom = Int.MAX_VALUE
    val dict = mutableSetOf<Edge>()
    for (i in 0 until 4) {
        val (x1, y1, x2, y2) = readInts()
        if (x1 == x2 && y1 == y2) {
            println("NO")
            return
        }
        left = left.coerceAtMost(x1.coerceAtMost(x2))
        right = right.coerceAtLeast(x1.coerceAtLeast(x2))
        top = top.coerceAtLeast(y1.coerceAtLeast(y2))
        bottom = bottom.coerceAtMost(y1.coerceAtMost(y2))
        dict.add(Pair(Pair(x1, y1), Pair(x2, y2)))
        dict.add(Pair(Pair(x2, y2), Pair(x1, y1)))
    }

    if (left == right || top == bottom) {
        println("NO")
        return
    }

    val LT = Pair(left, top)
    val LB = Pair(left, bottom)
    val RT = Pair(right, top)
    val RB = Pair(right, bottom)
    val topEdge = Pair(LT, RT)
    val bottomEdge = Pair(LB, RB)
    val leftEdge = Pair(LT, LB)
    val rightEdge = Pair(RT, RB)
    println(
        if (
            dict.contains(topEdge) &&
            dict.contains(bottomEdge) &&
            dict.contains(leftEdge) &&
            dict.contains(rightEdge)
        )
            "YES"
        else
            "NO"
    )
}
