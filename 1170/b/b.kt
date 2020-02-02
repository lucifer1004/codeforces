import java.util.Collections

fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

class Solution(private val n: Int, private val a: List<Int>) {
    fun solve() {
        val largestTwo = linkedSetOf<Pair<Int, Int>>()
        var badDays = 0
        for ((idx, num) in a.withIndex()) {
            if (largestTwo.size < 2) {
                largestTwo.add(Pair(num, idx))
                continue
            }
            val smaller =
                Collections.min(largestTwo) { x: Pair<Int, Int>, y: Pair<Int, Int> ->
                    return@min x.first - y.first
                }
            if (smaller.first > num)
                badDays++
            else {
                largestTwo.remove(smaller)
                largestTwo.add(Pair(num, idx))
            }
        }
        println(badDays)
    }
}

fun main() {
    val n = readInt()
    val a = readInts()
    val solution = Solution(n, a)
    solution.solve()
}
