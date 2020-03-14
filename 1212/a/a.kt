fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    var (n, k) = readInts()
    while (k > 0) {
        k--
        if (n % 10 != 0)
            n--
        else
            n /= 10
    }
    println(n)
}
