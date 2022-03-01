fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val (n, k) = readInts()
    val original = IntArray(31)
    var sum = 0
    for (i in 0 until 31) {
        if (n.and(1.shl(i)) != 0) {
            original[i] = 1
            sum++
        }
    }

    if (sum > k || n < k) {
        println("NO")
        return
    }

    var ptr = 30
    while (sum < k) {
        if (original[ptr] == 0) {
            ptr--
        } else {
            original[ptr]--
            original[ptr - 1] += 2
            sum++
        }
    }

    println("YES")
    for (i in 0 until 31) {
        repeat(original[i]) {
            print(1.shl(i))
            print(" ")
        }
    }
}
