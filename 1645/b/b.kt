fun readInt(): Int {
    return readLine()!!.toInt()
}

fun main() {
    val n = readInt()
    val s = readLine()!!
    val ans = mutableListOf<Char>()
    var i = 1
    var ptr = 0
    while (ptr < n) {
        ans.add(s[ptr])
        ptr += i
        i++
    }
    println(ans.joinToString(""))
}
