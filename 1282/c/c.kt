fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

class Solution() {
    fun solve() {
        val (n, t, a, b) = readInts()
        val problemType = readInts()
        val mandatoryTime = readInts()
        val easy = sortedMapOf<Int, Int>()
        val hard = sortedMapOf<Int, Int>()
        var totalEasy = 0
        var totalHard = 0
        for (i in 0 until n) {
            val currentEasy = easy.getOrPut(mandatoryTime[i], { 0 })
            val currentHard = hard.getOrPut(mandatoryTime[i], { 0 })
            if (problemType[i] == 0) {
                easy[mandatoryTime[i]] = currentEasy + 1
                totalEasy++
            }
            else {
                hard[mandatoryTime[i]] = currentHard + 1
                totalHard++
            }
        }
        easy.getOrPut(t + 1, { 0 })
        hard.getOrPut(t + 1, { 0 })
        var ans = 0
        var mandatoryEasy = 0
        var mandatoryHard = 0
        for (entry in easy) {
            val time = entry.key
            if (time > 0) {
                var lastTime = time - 1
                var canSolve = 0
                var timeNeeded = mandatoryEasy.toLong() * a + mandatoryHard.toLong() * b
                if (lastTime.toLong() >= timeNeeded) {
                    val remainingEasy = totalEasy - mandatoryEasy
                    val remainingHard = totalHard - mandatoryHard
                    canSolve += mandatoryEasy + mandatoryHard
                    lastTime -= timeNeeded.toInt()
                    val maxEasy = (lastTime / a).coerceAtMost(remainingEasy)
                    canSolve += maxEasy
                    lastTime -= maxEasy * a;
                    if (maxEasy == remainingEasy) {
                        val maxHard = (lastTime / b).coerceAtMost(remainingHard)
                        canSolve += maxHard
                    }
                    ans = ans.coerceAtLeast(canSolve)
                }
            }
            mandatoryEasy += easy[time]!!
            mandatoryHard += hard[time]!!
        }
        println(ans)
    }
}

fun main() {
    val t = readInt()
    for (i in 1 until t + 1) {
        val solution = Solution()
        solution.solve()
    }
}
