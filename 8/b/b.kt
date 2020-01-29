fun main() {
    val cmd = readLine()!!
    val direction = mutableMapOf(
        'L' to Pair(-1, 0),
        'R' to Pair(1, 0),
        'U' to Pair(0, -1),
        'D' to Pair(0, 1)
    )
    val path = mutableListOf(Pair(0, 0))
    var x = 0
    var y = 0
    var i = 0
    for (step in cmd) {
        x += direction[step]!!.first
        y += direction[step]!!.second
        i++
        if (path.contains(Pair(x, y))) {
            println("BUG")
            return
        }
        path.add(Pair(x, y))
    }
    val bfs = mutableListOf(Pair(Pair(0, 0), 0))
    val visited = mutableSetOf<Pair<Int, Int>>()
    while (bfs.isNotEmpty()) {
        val front = bfs.first()
        if (front.first == Pair(x, y) && front.second < cmd.length) {
            println("BUG")
            return
        }
        bfs.removeAt(0)
        for (d in direction.values) {
            val nx = front.first.first + d.first
            val ny = front.first.second + d.second
            val cell = Pair(nx, ny)
            if (!visited.contains(cell) && path.contains(cell)) {
                val ns = front.second + 1
                visited.add(Pair(nx, ny))
                bfs.add(Pair(Pair(nx, ny), ns))
            }
        }
    }
    println("OK")
}
