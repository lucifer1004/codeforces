fun main() {
    readLine()!!
    val s = readLine()!!
    var last = 'o'
    var acc = 0
    var ans = 0
    for (c in s + "#") {
        if (c == last) {
            acc++
        } else {
            if (last == 'x') {
                ans += (acc - 2).coerceAtLeast(0)
            }
            acc = 1
            last = c
        }
    }
    println(ans)
}
