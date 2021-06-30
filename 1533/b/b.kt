fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val t = readInt()
    for (caseNum in 1 until t + 1) {
        val n = readInt()
        val x = readInts()
        var crash = false
        for (i in 0 until n - 1)
            if ((x[i + 1] - x[i]) % 2 == 0) {
                crash = true
                break
            }
        if (crash) {
            println("YES")
        } else {
            println("NO")
        }
    }
}
