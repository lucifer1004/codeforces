fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    readInt()
    val a = readInts().toMutableList()
    a.sort()
    var last = -1
    var ans = 0
    for (ai in a) {
        if (ai > 1 && ai - 1 > last) {
            last = ai - 1
            ans++
        } else if (ai > last) {
            last = ai
            ans++
        } else if (ai + 1 > last) {
            last = ai + 1
            ans++
        }
    }
    println(ans)
}
