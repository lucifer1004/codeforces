fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun maxDepth(nodes: Int): Int {
    return nodes * (nodes - 1) / 2;
}

fun minDepth(nodes: Int): Int {
    var level = 0
    var num = 1
    var rest = nodes
    var sum = 0
    while (rest > 0) {
        sum += num.coerceAtMost(rest) * level
        level++
        rest -= num
        num = num.shl(1)
    }
    return sum
}

const val MAXN = 5002
val parent = IntArray(MAXN)
val max = IntArray(MAXN)
val min = IntArray(MAXN)
var rest = 0

fun dfs(p: Int, l: Int, r: Int, target: Int) {
    val nodes = r - l + 1
    rest -= nodes
    if (nodes == 0)
        return
    if (nodes == 1) {
        parent[l] = p
        return
    }
    var left = 0
    var right = nodes / 2 + 1
    while (left <= right) {
        val mid = (left + right) / 2
        val another = nodes - mid
        val lo = (target - nodes - max[mid]).coerceAtLeast(min[another])
        val hi = (target - nodes - min[mid]).coerceAtMost(max[another])
        if (lo <= hi) {
            if (mid > 0) {
                parent[l] = p
                dfs(l, l + 1, l + mid - 1, target - nodes - lo)
            }
            if (another > 0) {
                parent[l + mid] = p
                dfs(l + mid, l + mid + 1, r, lo)
            }
            return
        } else {
            if (target - nodes - max[mid] > max[another])
                right = mid - 1
            else if (target - nodes - min[mid] < min[another])
                left = mid + 1
        }
    }
}

fun main() {
    for (i in 0 until MAXN) {
        min[i] = minDepth(i)
        max[i] = maxDepth(i)
    }

    val t = readInt()
    val ans = mutableListOf<String>()
    for (caseNum in 0 until t) {
        val (n, d) = readInts()
        parent.fill(0)
        rest = d
        dfs(1, 2, n, d)
        if (rest != 0 || parent.count { it != 0 } != n - 1)
            ans.add("NO")
        else {
            ans.add("YES")
            ans.add(parent.slice(2..n).joinToString(" "))
        }
    }
    println(ans.joinToString("\n"))
}
