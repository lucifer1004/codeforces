fun readInt(): Int {
    return readLine()!!.toInt()
}

class Solution {
    fun solve() {
        val s = readLine()!!
        val odd = mutableListOf<Char>()
        val even = mutableListOf<Char>()
        for (c in s) {
            if (c.toInt() % 2 == 0)
                even.add(c)
            else
                odd.add(c)
        }
        val ans = mutableListOf<Char>()
        var lo = 0
        var le = 0
        while (lo < odd.size || le < even.size) {
            if (le == even.size || (lo < odd.size && odd[lo] < even[le]))
                ans.add(odd[lo++])
            else 
                ans.add(even[le++])
        }
        println(ans.joinToString(""))
    }
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val solution = Solution()
        solution.solve()
    }
}
