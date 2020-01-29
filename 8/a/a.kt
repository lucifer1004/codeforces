fun main() {
    val full = readLine()!!
    val a = readLine()!!
    val b = readLine()!!
    val aReg = a.toRegex()
    val bReg = b.toRegex()
    val find = {
        str: String ->
        val aForward = aReg.find(str)
        if (aForward != null) {
            val bForward = bReg.find(str, aForward.range.last + 1)
            bForward != null
        } else false
    }
    var forward = find(full)
    var backward = find(full.reversed())
    if (forward) {
        if (backward) println("both")
        else println("forward")
    } else {
        if (backward) println("backward")
        else println("fantasy")
    }
}