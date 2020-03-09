import java.util.*

fun readLongs(): List<Long> {
    return readLine()!!.split(" ").map(String::toLong)
}

data class IceCream(val cost: Long, var num: Long)

fun main() {
    val (n, k) = readLongs()
    var num = 0L
    var sum = 0L
    val pq = PriorityQueue<IceCream>(compareByDescending { it.cost })
    for (i in 0 until n) {
        val (a, b, c) = readLongs()
        num += b
        sum += a * c
        if (b > a)
            pq.add(IceCream(c, b - a))
        while (num > k && pq.isNotEmpty()) {
            val expensive = pq.poll()
            val surplus = (num - k).coerceAtMost(expensive.num)
            if (surplus < expensive.num)
                pq.add(IceCream(expensive.cost, expensive.num - surplus))
            num -= surplus
        }
    }
    while (pq.isNotEmpty()) {
        val expensive = pq.poll()
        sum += expensive.cost * expensive.num
    }
    println(if (num != k) -1 else sum)
}
