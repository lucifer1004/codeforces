import java.util.*

fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readLong(): Long {
    return readLine()!!.toLong()
}

fun readLongs(): List<Long> {
    return readLine()!!.split(" ").map(String::toLong)
}

fun solve() {
    val (n0, money) = readLongs()
    val n = n0.toInt()
    val l = mutableListOf<Long>()
    val r = mutableListOf<Long>()
    var rest = money
    for (i in 0 until n) {
        val (li, ri) = readLongs()
        l.add(li)
        r.add(ri)
        rest -= li
    }
    val sortedL = l.sorted()
    val sortedR = r.sorted()
    var lo = sortedL[n / 2]
    var hi = sortedR[n / 2]
    while (lo <= hi) {
        val pq = PriorityQueue<Long>()
        val mid = (lo + hi) / 2
        var count = 0
        for (i in 0 until n) {
            if (l[i] >= mid)
                count++
            else if (r[i] >= mid)
                pq.add(mid - l[i])
        }
        val need = n / 2 + 1 - count
        if (pq.size < need) {
            hi = mid - 1
            continue
        }
        var extra = 0L
        for (i in 0 until need)
            extra += pq.poll()
        if (extra > rest) 
            hi = mid - 1
        else
            lo = mid + 1
    }
    println(lo - 1)
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1)
       solve()
}
