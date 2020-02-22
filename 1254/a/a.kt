fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val alphabet = mutableListOf<Char>()
    for (c in 'z' downTo 'a')
        alphabet.add(c)
    for (c in 'Z' downTo 'A')
        alphabet.add(c)
    for (c in '9' downTo '0')
        alphabet.add(c)

    val t = readInt()
    for (testCase in 0 until t) {
        val (r, c, k) = readInts()
        val field = mutableListOf<String>()
        var rice = 0
        for (i in 0 until r) {
            val row = readLine()!!
            field.add(row)
            for (cell in row)
                if (cell == 'R')
                    rice++
        }
        val target = IntArray(k) { rice / k }
        val ans = Array(r) { CharArray(c) }
        for (i in 0 until rice % k)
            target[i]++
        var currRice = 0
        var currCow = 0
        for (i in 0 until r) {
            for (j0 in 0 until c) {
                val j = if (i % 2 == 0) j0 else c - j0 - 1
                if (field[i][j] == 'R')
                    currRice++
                if (currRice > target[currCow]) {
                    currRice -= target[currCow]
                    currCow++
                }
                ans[i][j] = alphabet[currCow]
            }
        }
        println(ans.joinToString("\n") { arr -> arr.joinToString("") })
    }
}
