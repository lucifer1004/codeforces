fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

fun main() {
    val n = readInt()
    val a = readInts()
    val sum = LongArray(n)
    sum[0] = a[0].toLong()
    for (i in 1 until n)
        sum[i] = sum[i - 1] + a[i].toLong()
    if (sum[n - 1] == 1L) {
        println(-1)
        return
    }

    val primes = mutableListOf(2, 3, 5, 7, 11, 13)
    for (i in 8 until 500001) {
        val k = i * 2 + 1;
        var j = 0;
        var isPrime = true
        while (primes[j] * primes[j] <= k) {
            if (k % primes[j] == 0) {
                isPrime = false
                break
            }
            j++
        }
        if (isPrime)
            primes.add(k)
    }
    var ans = Long.MAX_VALUE
    var rest = sum[n - 1]
    for (prime in primes) {
        if (rest % prime == 0L) {
            var curr = 0L
            for (s in sum) {
                val rem = s % prime
                curr += rem.coerceAtMost(prime - rem)
            }
            ans = ans.coerceAtMost(curr)
            while (rest % prime == 0L)
                rest /= prime
        }
        if (prime * prime >= rest)
            break
    }
    if (rest != 1L) {
        var curr = 0L
        for (s in sum) {
            val rem = s % rest
            curr += rem.coerceAtMost(rest - rem)
        }
        ans = ans.coerceAtMost(curr)
    }
    println(ans)
}
