fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val n = readInt()
    val a = readInts().sorted()
    var r = 2
    while (r < n - 1 && a[r + 1] == a[2])
        r++
    val nums = (r + 1).toLong()
    println(when {
        a[2] == a[0] -> nums * (nums - 1) * (nums - 2) / 6
        a[2] == a[1] -> (nums - 1) * (nums - 2) / 2
        else -> nums - 2
    })
}
