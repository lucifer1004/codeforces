fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readLongs(): List<Long> {
    return readLine()!!.split(" ").map(String::toLong)
}

fun main() {
    val n = readInt()
    val a = readLongs()
    val ans = mutableListOf<Int>()
    val cnt = mutableMapOf<Long, Int>()
    var sum = 0L
    for (i in 0 until n) {
        sum += a[i]
        cnt[a[i]] = cnt.getOrDefault(a[i], 0) + 1
    }
    for (i in 0 until n) {
        val rem = sum - a[i]
        if (rem % 2 == 0L) {
            val half = rem / 2
            val freq = cnt.getOrDefault(half, 0)
            if ((a[i] == half && freq >= 2) || (a[i] != half && freq >= 1)) {
                ans.add(i + 1)
            }
        }
    }
    println(ans.size)
    println(ans.joinToString(" "))
}
