fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val t = readInt()
    for (caseNum in 1 until t + 1) {
        val (n, k) = readInts()
        val s = readLine()!!
        var like = 0
        for (i in 0 until n)
            if (s[i] == '1')
                like++

        if (like == 0) {
            println(0)
            continue
        }

        var ans = 1
        if (s[0] == '1')
            like--
        var remain = (1 until n).toMutableList()
        var pos = 0
        while (like > 0) {
            val len = remain.size
            val stop = (pos + k - 1) % len
            val newRemain = mutableListOf<Int>()
            for (i in 0 until len)
                if (i != stop)
                    newRemain.add(remain[i])
            ans++
            if (s[remain[stop]] == '1')
                like--
            if (len > 1)
                pos = stop % (len - 1)
            remain = newRemain
        }

        println(ans)
    }
}
