fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

val dx = mapOf(Pair('L', -1), Pair('R', 1), Pair('U', 0), Pair('D', 0))
val dy = mapOf(Pair('L', 0), Pair('R', 0), Pair('U', -1), Pair('D', 1))
var ans = mutableListOf<String>()

class Solution {
    fun solve() {
        val (r, c) = readInts()
        val colors = mutableListOf<String>()
        val directions = mutableListOf<String>()
        for (i in 0 until r) {
            val row = readLine()!!
            colors.add(row)
        }
        for (i in 0 until r) {
            val row = readLine()!!
            directions.add(row)
        }
        val vis = Array(r) { BooleanArray(c) }
        val pos = Array(r) { IntArray(c) }
        val belong = Array(r) { IntArray(c) }
        val loops = mutableListOf<BooleanArray>()
        for (i in 0 until r)
            for (j in 0 until c) {
                if (vis[i][j])
                    continue
                var group = loops.size
                vis[i][j] = true
                belong[i][j] = group
                val path = mutableListOf<Pair<Int, Int>>()
                path.add(Pair(i, j))
                var ni = i + dy[directions[i][j]]!!
                var nj = j + dx[directions[i][j]]!!
                while (true) {
                    val p = Pair(ni, nj)
                    if (vis[ni][nj]) {
                        val step = path.size
                        var start = 0
                        var length = 0
                        if (belong[ni][nj] == group) {
                            for ((idx, it) in path.withIndex())
                                if (it.first == ni && it.second == nj) {
                                    start = idx
                                    break
                                }
                            length = step - start
                            loops.add(BooleanArray(length))
                        } else {
                            start = step - pos[ni][nj]
                            group = belong[ni][nj]
                            length = loops[group].size
                        }
                        for (k in 0 until step) {
                            val (mi, mj) = path[k]
                            pos[mi][mj] = (k - start) % length;
                            if (pos[mi][mj] < 0)
                                pos[mi][mj] += length;
                            belong[mi][mj] = group;
                            if (colors[mi][mj] == '0')
                                loops[group][pos[mi][mj]] = true;
                        }
                        break
                    }
                    vis[ni][nj] = true
                    path.add(p)
                    belong[ni][nj] = group
                    val rawi = ni
                    ni += dy[directions[ni][nj]]!!
                    nj += dx[directions[rawi][nj]]!!
                }
            }
        var sum = 0
        var black = 0
        for (loop in loops) {
            sum += loop.size
            for (cell in loop)
                black += if (cell) 1 else 0
        }
        ans.add("$sum $black")
    }
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val solution = Solution()
        solution.solve()
    }
    println(ans.joinToString("\n"))
}
