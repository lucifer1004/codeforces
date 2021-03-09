fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map(String::toInt)
    val ans = mutableListOf<Int>()
    val s = mutableSetOf<Int>()
    for (i in n - 1 downTo 0) {
        if (!s.contains(a[i])) {
            s.add(a[i])
            ans.add(a[i])
        }
    }
    println(ans.size)
    println(ans.reversed().joinToString(" "))
}
