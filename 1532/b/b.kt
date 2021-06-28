fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readLongs(): List<Long> {
    return readLine()!!.split(" ").map(String::toLong)
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val (a, b, k) = readLongs()
        var ans = (a - b) * (k / 2);
        if (k % 2 == 1L) {
            ans += a;
        }
        println(ans);
    }
}
