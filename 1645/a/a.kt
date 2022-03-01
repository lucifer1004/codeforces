fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val n = readInt()
        val a = readInts()
        if (a[0] != a[n - 1]) {
            if (a[0] == a[1]) {
                println(n)
            } else {
                println(1)
            }
        } else {
            for (j in 1 until n - 1) {
                if (a[j] != a[0]) {
                    println(j + 1)
                    break
                }
            }
        }
    }
}
