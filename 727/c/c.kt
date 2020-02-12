fun readInt(): Int {
    return readLine()!!.toInt()
}

fun main() {
    val n = readInt()
    val ans = IntArray(n)
    println("? 1 2")
    val ab = readInt()
    println("? 1 3")
    val ac = readInt()
    println("? 2 3")
    val bc = readInt()
    val abc = (ab + ac + bc) / 2
    ans[0] = abc - bc
    ans[1] = abc - ac
    ans[2] = abc - ab
    for (i in 3 until n) {
        println("? " + listOf(1, i + 1).joinToString(" "))
        val ax = readInt()
        ans[i] = ax - ans[0]
    }
    println("! " + ans.joinToString(" "))
}
