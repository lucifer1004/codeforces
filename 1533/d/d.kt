fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val (n, m) = readInts()
    val patterns = mutableSetOf<String>()
    for (i in 0 until n)
        patterns.add(readLine()!!)

    val q = readInt()
    val queries = mutableListOf<String>()
    for (i in 0 until q)
        queries.add(readLine()!!)

    println(queries.map { 
        val from = mutableSetOf<String>()
        for (i in 0 until m + 1) {
            val raw = it.substring(0, i) + it.substring(i + 1, m + 1)
            if (patterns.contains(raw))
                from.add(raw)
        }
        from.size
    }.joinToString("\n"))
}
