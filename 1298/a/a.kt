fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val nums = readInts()
    val (ab, ac, bc, abc) = nums.sorted()
    val a = abc - bc
    val b = abc - ac
    val c = abc - ab
    println(listOf(a, b, c).joinToString(" "))
}
