fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

class Solution(private val n: Int, private val b: Int, private val a: List<Int>) {
    fun solve() {
        var even = 0
        var odd = 0
        val possibleCuts = mutableListOf<Int>()
        for (i in a.indices) {
            if (a[i] % 2 == 0)
                even++
            else
                odd++
            if (even == odd && i + 1 < a.size)
                possibleCuts.add(kotlin.math.abs(a[i] - a[i + 1]))
        }
        if (even != odd)
            println(0)
        else {
            val possibleCutsArray = possibleCuts.toIntArray()
            possibleCutsArray.sort()
            var ans = 0
            var sum = 0
            for (cost in possibleCutsArray)
                if (sum + cost <= b) {
                    sum += cost
                    ans++
                }
            println(ans)
        }
    }
}

fun main() {
    val (n, b) = readInts()
    val a = readInts()
    val solution = Solution(n, b, a)
    solution.solve()
}
