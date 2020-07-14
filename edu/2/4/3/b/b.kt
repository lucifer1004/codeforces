fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

class SegmentTree(private val n: Int) {
    private val len = n * 4
    private val sum = IntArray(len)

    private fun calc(idx: Int) {
        val l = idx shl 1
        val r = l xor 1
        sum[idx] = sum[l] + sum[r]
    }

    fun build(idx: Int, l: Int, r: Int) {
        if (l == r) {
            sum[idx] = 1
        } else {
            val mid = (l + r) shr 1
            build(idx shl 1, l, mid)
            build(idx shl 1 xor 1, mid + 1, r)
            calc(idx)
        }
    }

    fun update(idx: Int, pos: Int, cl: Int, cr: Int) {
        if (cl == pos && cl == cr) {
            sum[idx] = 0
            return
        }
        val mid = (cl + cr) shr 1
        if (pos <= mid)
            update(idx shl 1, pos, cl, mid)
        else
            update(idx shl 1 xor 1, pos, mid + 1, cr)
        calc(idx)
    }

    fun query(idx: Int, k: Int, cl: Int, cr: Int): Int {
        if (cl == cr)
            return cr;
        val mid = (cl + cr) shr 1
        val l = idx shl 1
        val r = l xor 1
        return if (sum[l] >= k)
            query(l, k, cl, mid)
        else
            query(r, k - sum[l], mid + 1, cr)
    }
}

fun main() {
    val n = readInt()
    val st = SegmentTree(n)
    st.build(1, 1, n)
    val a = readInts()
    val ans = IntArray(n)
    for (i in n - 1 downTo 0) {
        ans[i] = st.query(1, i + 1 - a[i], 1, n)
        st.update(1, ans[i], 1, n)
    }
    println(ans.joinToString(" "))
}
