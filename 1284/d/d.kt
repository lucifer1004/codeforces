import java.util.PriorityQueue
 
fun readInt(): Int {
    return readLine()!!.toInt()
}
 
fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}
 
fun main() {
    val n = readInt()
    val sa = mutableListOf<Int>()
    val sb = mutableListOf<Int>()
    val ea = mutableListOf<Int>()
    val eb = mutableListOf<Int>()
    for (i in 0 until n) {
        val (sai, eai, sbi, ebi) = readInts()
        sa.add(sai)
        ea.add(eai)
        sb.add(sbi)
        eb.add(ebi)
    }
    val pairComparator = compareBy<Pair<Int, Int>>({ it.first }, { it.second })
    val check = { sx: MutableList<Int>, ex: MutableList<Int>, sy: MutableList<Int>, ey: MutableList<Int> ->
        val t = sortedSetOf<Int>()
        for (i in 0 until n) {
            t.add(sx[i])
            t.add(ex[i])
        }
        val tl = t.toList()
        val lut = mutableMapOf<Int, Int>()
        for ((i, ti) in tl.withIndex())
            lut[ti] = i
        val m = t.size
        val startAt = Array(m) { mutableListOf<Int>() }
        for (i in 0 until n)
            startAt[lut[sx[i]]!!].add(i)
        var ok = true
        val pq = PriorityQueue(pairComparator)
        val counterStart = sortedSetOf(pairComparator)
        val counterEnd = sortedSetOf(pairComparator)
        for (i in 0 until m) {
            for (j in startAt[i]) {
                pq.add(Pair(lut[ex[j]]!!, j))
                counterStart.add(Pair(sy[j], j))
                counterEnd.add(Pair(ey[j], j))
            }
            if (pq.isNotEmpty()) {
                val lastStart = counterStart.last().first
                val firstEnd = counterEnd.first().first
                if (lastStart > firstEnd) {
                    ok = false
                    break
                }
            }
            while (pq.isNotEmpty() && pq.peek().first == i) {
                val idx = pq.poll().second
                counterStart.remove(Pair(sy[idx], idx))
                counterEnd.remove(Pair(ey[idx], idx))
            }
        }
        ok
    }
    val result = check(sa, ea, sb, eb) && check(sb, eb, sa, ea)
    println(if (result) "YES" else "NO")
}