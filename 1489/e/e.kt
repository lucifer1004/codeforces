fun main() {
    val q = readLine()!!.toInt()
    val left = mutableMapOf<Int, Int>()
    val right = mutableMapOf<Int, Int>()
    val idx = mutableMapOf<Int, Int>()
    val leftCount = IntArray(q + 1)
    val rightCount = IntArray(q + 1)
    for (i in 1 until q + 1) {
        val (queryType, idString) = readLine()!!.split(" ")
        val id = idString.toInt()
        leftCount[i] = leftCount[i - 1]
        rightCount[i] = rightCount[i - 1]
        when (queryType) {
            "L" -> {
                idx[id] = i
                left[id] = 0
                right[id] = leftCount[i] + rightCount[i]
                leftCount[i]++
            }
            "R" -> {
                idx[id] = i
                left[id] = leftCount[i] + rightCount[i]
                right[id] = 0
                rightCount[i]++
            }
            else -> {
                println(
                        (left[id]!! + leftCount[i] - leftCount[idx[id]!!]).coerceAtMost(
                                right[id]!! + rightCount[i] - rightCount[idx[id]!!]))
            }
        }
    }
}
