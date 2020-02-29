fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

const val MAXN = 200000

fun main() {
    val (n, k) = readInts()
    val l = mutableListOf<Int>()
    val r = mutableListOf<Int>()
    val startAt = Array(MAXN + 1) { mutableListOf<Int>() }
    val endAt = Array(MAXN + 1) { mutableListOf<Int>() }
    for (i in 0 until n) {
        val (li, ri) = readInts()
        l.add(li)
        r.add(ri)
        startAt[li].add(i)
        endAt[ri].add(i)
    }
    val pq = sortedSetOf(compareByDescending<Pair<Int, Int>> { it.first }.thenBy { it.second })
    val ans = mutableListOf<Int>()
    for (i in 1 until MAXN + 1) {
        for (seg in startAt[i])
            pq.add(Pair(r[seg], seg))
        while (pq.size > k) {
            val longest = pq.first()
            pq.remove(longest)
            ans.add(longest.second)
        }
        for (seg in endAt[i])
            pq.remove(Pair(r[seg], seg))
    }
    println(ans.size)
    println(ans.map { it + 1 }.joinToString(" "))
}
