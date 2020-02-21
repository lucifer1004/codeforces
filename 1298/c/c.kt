fun readInt(): Int {
    return readLine()!!.toInt()
}

fun main() {
    readInt()
    var s = readLine()!!
    s += "$"
    var ans = 0
    var cnt = 0
    for (char in s) {
        if (char == 'x')
            cnt++
        else {
            if (cnt >= 3)
                ans += cnt - 2;
            cnt = 0
        }
    }
    println(ans)
}
