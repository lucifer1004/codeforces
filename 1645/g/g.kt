fun readInt(): Int {
    return readLine()!!.toInt()
}

@kotlin.ExperimentalStdlibApi
fun main() {
    val n = readInt()
    val s = readLine()!!
    val t = readLine()!!
    val sum = IntArray(n + 1)
    for (i in n - 1 downTo 0) {
        val si = s[i].code - 'a'.code
        val ti = t[i].code - 'a'.code
        sum[n - i - 1] += si + ti
        if (sum[n - i - 1] >= 26) {
            sum[n - i - 1] -= 26
            sum[n - i]++
        }
    }

    for (i in n downTo 0) {
        if (sum[i] % 2 == 1) {
            sum[i - 1] += 26
        }     
        sum[i] /= 2
    }

    for (i in n - 1 downTo 0) {
        print((sum[i] + 'a'.code).toChar())
    }
}
