fun main() {
    val n = readLine()!!.toInt()
    val strs = mutableListOf<String>()
    for (i in 0 until n) {
        strs.add(readLine()!!)
    }
    strs.sortBy { it.length }
    for (i in 0 until n - 1) {
        if (strs[i + 1].findAnyOf(listOf(strs[i])) === null) {
            println("NO")
            return
        }
    }

    println("YES")
    println(strs.joinToString("\n"))
}
