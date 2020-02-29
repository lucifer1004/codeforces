import java.util.*

fun readInt(): Int {
    return readLine()!!.toInt()
}

fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}

data class Edge(val to: Int, val w: Int)

const val INF = 0x3f3f3f3f

fun main() {
    val (n, m, s) = readInts()
    val adj = Array(n + 1) { mutableListOf<Edge>() }
    for (i in 0 until m) {
        val (u, v, w) = readInts()
        adj[u].add(Edge(v, w))
        adj[v].add(Edge(u, w))
    }
    val l = readInt()
    val dist = IntArray(n + 1) { INF }
    val vis = BooleanArray(n + 1) { false }
    dist[s] = 0
    val pq = PriorityQueue(compareBy<Pair<Int, Int>> { it.first }.thenBy { it.second })
    pq.add(Pair(0, s))
    while (pq.isNotEmpty()) {
        val front = pq.poll()
        if (vis[front.second])
            continue
        vis[front.second] = true
        for (edge in adj[front.second])
            if (front.first + edge.w < dist[edge.to]) {
                dist[edge.to] = front.first + edge.w
                pq.add(Pair(dist[edge.to], edge.to))
            }
    }
    var count = 0
    // Cities
    for (i in 1 until n + 1)
        if (dist[i] == l)
            count++
    
    // Roads
    for (i in 1 until n + 1)
        for (edge in adj[i]) {
            if (edge.to < i) continue
            val du = dist[i]
            val dv = dist[edge.to]
            val x1 = l - du
            if (x1 > 0 && x1 < edge.w && edge.w - x1 + dv >= l)
                count++
            val x2 = edge.w + dv - l
            if (x2 > 0 && x2 < edge.w && x2 + du >= l && x2 != x1)
                count++
        }
    println(count)
}
