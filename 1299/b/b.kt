fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

class Solution() {
    fun solve() {
        val n = readInt()
        val vertices = mutableListOf<List<Int>>()
        for (i in 0 until n) {
            val a = readInts()
            vertices.add(a)
        }
        if (n % 2 == 1)
            println("No")
        else {
            val k = n / 2
            val mx = vertices[0][0] + vertices[k][0]
            val my = vertices[0][1] + vertices[k][1]
            for (i in 1 until k) {
                val mx1 = vertices[i][0] + vertices[i + k][0]
                val my1 = vertices[i][1] + vertices[i + k][1]
                if (mx1 != mx || my1 != my) {
                    println("No")
                    return
                }
            }
            println("Yes")
        }
    }
}

fun main() {
    val solution = Solution()
    solution.solve()
}
