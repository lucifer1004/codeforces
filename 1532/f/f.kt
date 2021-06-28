fun readInt(): Int {
    return readLine()!!.toInt()
}

fun main() {
    val n = readInt()
    val sub = Array<MutableList<String>>(n) { mutableListOf() }
    val order = Array<MutableList<Int>>(n) { mutableListOf() }
    for (i in 0 until 2 * n - 2) {
        val str = readLine()!!
        sub[str.length].add(str)
        order[str.length].add(i)
    }
    
    val ans = CharArray(2 * n - 2)

    for (i in 0 until 2) {
        val pre = sub[n - 1][i]
        val suf = sub[n - 1][1 - i]
        if (pre.substring(1) != suf.substring(0, n - 2)) {
            continue
        }
        val orig = pre + suf.substring(n - 2)
        var valid = true
        for (j in 1 until n) {
            val (s, t) = sub[j]
            if (s == orig.substring(0, j) && t == orig.substring(n - j)) {
                ans[order[j][0]] = 'P'
                ans[order[j][1]] = 'S'
            } else if (t == orig.substring(0, j) && s == orig.substring(n - j)) {
                ans[order[j][0]] = 'S'
                ans[order[j][1]] = 'P'
            } else {
                valid = false
                break
            }
        }
        
        if (valid) {
            println(ans.joinToString(""))
            return
        }
    }
}
