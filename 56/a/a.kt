fun readInt(): Int {
    return readLine()!!.toInt()
}

fun main() {
    val n = readInt()
    val alcohol =
        setOf("ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE")
    var ans = 0
    for (i in 0 until n) {
        val line = readLine()!!
        val ch = line[0]
        if (ch in '0'..'9') {
            val num = line.toInt()
            if (num < 18)
                ans++
        } else if (line in alcohol)
            ans++
    }
    println(ans)
}
