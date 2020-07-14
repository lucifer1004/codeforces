fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

class SegmentTree(private val a: List<Int>) {
    private val len = a.size * 4
    private val max = IntArray(len)

    private fun calc(idx: Int) {
        val l = idx shl 1
        val r = l xor 1
        max[idx] = max[l].coerceAtLeast(max[r])
    }

    fun build(idx: Int, l: Int, r: Int) {
        if (l == r) {
            max[idx] = a[l - 1]
        } else {
            val mid = (l + r) shr 1
            build(idx shl 1, l, mid)
            build(idx shl 1 xor 1, mid + 1, r)
            calc(idx)
        }
    }

    fun update(idx: Int, pos: Int, v: Int, cl: Int, cr: Int) {
        if (cl == pos && cl == cr) {
            max[idx] = v
            return
        }
        val mid = (cl + cr) shr 1
        if (pos <= mid)
            update(idx shl 1, pos, v, cl, mid)
        else
            update(idx shl 1 xor 1, pos, v,mid + 1, cr)
        calc(idx)
    }

    fun query(idx: Int, k: Int, cl: Int, cr: Int): Int {
        if (cl == cr && max[idx] >= k)
            return cr - 1
        val mid = (cl + cr) shr 1
        val l = idx shl 1
        val r = l xor 1
        return when {
            max[idx] < k -> -1
            max[l] >= k -> query(l, k, cl, mid)
            else -> query(r, k, mid + 1, cr)
        }
    }
}

fun main() {
    val (n, m) = readInts()
    val st = SegmentTree(readInts())
    st.build(1, 1, n)
    val ans = mutableListOf<Int>()
    for (i in 0 until m) {
        val op = readInts()
        if (op[0] == 1) {
            st.update(1, op[1] + 1, op[2], 1, n)
        } else {
            ans.add(st.query(1, op[1], 1, n))
        }
    }
    println(ans.joinToString("\n"))
}
