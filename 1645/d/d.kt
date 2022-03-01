fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val n = readInt()
    val a = readInts().toMutableList()
    a.sort()
    val inc = mutableListOf<Int>()
    val dec = mutableListOf<Int>()
    for (i in 0 until n) {
        if (i == 0 || a[i] != a[i - 1]) {
            inc.add(a[i])
        } else if (i != 1 && a[i] == a[i - 2]) {
            println("NO")
            return
        } else {
            dec.add(a[i])
        }
    }
    dec.reverse()
    println("YES")
    println(inc.size)
    println(inc.joinToString(" "))
    println(dec.size)
    println(dec.joinToString(" "))
}
