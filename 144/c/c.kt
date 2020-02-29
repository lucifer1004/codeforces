fun main() {
    val s = readLine()!!
    val t = readLine()!!
    val k = t.length
    val dt = mutableMapOf<Char, Int>()
    for (c in t)
        dt[c] = dt.getOrDefault(c, 0) + 1
    val ds = mutableMapOf<Char, Int>()
    var count = 0
    val check = {
        var questionMark = ds.getOrDefault('?', 0)
        var ok = true
        for (c in 'z' downTo 'a') {
            val cs = ds.getOrDefault(c, 0)
            val ct = dt.getOrDefault(c, 0)
            if (cs > ct) {
                ok = false
                break
            }
            if (cs + questionMark >= ct)
                questionMark -= ct - cs
            else {
                ok = false
                break
            }
        }
        if (ok) 1 else 0
    }
    for (i in s.indices) {
        ds[s[i]] = ds.getOrDefault(s[i], 0) + 1
        if (i >= k)
            ds[s[i - k]] = ds[s[i - k]]!! - 1
        count += check()
    }
    println(count)
}
