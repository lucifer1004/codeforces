fun main() {
    val t = readLine()!!.toInt()
    for (i in 1 until t + 1) {
        val (n, a, b) = readLine()!!.split(" ").map(String::toLong)
        if (a * 2 <= b) {
            println(n * a)
        } else {
            println(n / 2 * b + n % 2 * a)
        }
    }
}
