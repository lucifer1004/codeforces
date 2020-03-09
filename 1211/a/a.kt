fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val n = readInt()
    val a = readInts()
    val m = sortedMapOf<Int, MutableList<Int>>()
    for ((i, v) in a.withIndex())
        m.getOrPut(v, { mutableListOf() }).add(i + 1)
    if (m.size < 3)
        println("-1 -1 -1")
    else {
        val ans = mutableListOf<Int>()
        for ((i, v) in m.values.withIndex()) {
            if (i >= 3)
                break
            ans.add(v.first())
        }
        println(ans.joinToString(" "))
    }
}
