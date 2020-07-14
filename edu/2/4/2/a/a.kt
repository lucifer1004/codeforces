fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

class SegmentTree(private val a: List<Int>) {
    private val len = a.size * 4
    private val sum = LongArray(len)
    private val ma = LongArray(len)
    private val lm = LongArray(len)
    private val rm = LongArray(len)

    private fun calc(idx: Int) {
        val l = idx shl 1
        val r = l xor 1
        sum[idx] = sum[l] + sum[r]
        ma[idx] = ma[l].coerceAtLeast(ma[r]).coerceAtLeast(rm[l] + lm[r])
        lm[idx] = lm[l].coerceAtLeast(sum[l] + lm[r])
        rm[idx] = rm[r].coerceAtLeast(sum[r] + rm[l])
    }

    fun build(idx: Int, l: Int, r: Int) {
        if (l == r) {
            sum[idx] = a[l - 1].toLong()
            ma[idx] = sum[idx].coerceAtLeast(0)
            lm[idx] = sum[idx].coerceAtLeast(0)
            rm[idx] = sum[idx].coerceAtLeast(0)
        }
        else {
            val mid = (l + r) shr 1
            build(idx shl 1, l, mid)
            build(idx shl 1 xor 1, mid + 1, r)
            calc(idx)
        }
    }

    fun update(idx: Int, pos: Int, v: Int, cl: Int, cr: Int) {
        if (cl == pos && cl == cr) {
            sum[idx] = v.toLong()
            ma[idx] = sum[idx].coerceAtLeast(0)
            lm[idx] = sum[idx].coerceAtLeast(0)
            rm[idx] = sum[idx].coerceAtLeast(0)
            return
        }
        val mid = (cl + cr) shr 1
        if (pos <= mid)
            update(idx shl 1, pos, v, cl, mid)
        else
            update(idx shl 1 xor 1, pos, v, mid + 1, cr)
        calc(idx)
    }

    fun query(): Long {
        return ma[1];
    }
}

fun main() {
    val (n, m) = readInts()
    val st = SegmentTree(readInts())
    st.build(1, 1, n)
    val ans = mutableListOf<Long>()
    ans.add(st.query())
    for (i in 0 until m) {
        val (v1, v2) = readInts()
        st.update(1, v1 + 1, v2, 1, n)
        ans.add(st.query())
    }
    println(ans.joinToString("\n"))
}
