fun main() {
  class UnionFind(private val n: Int) {
    val parent = IntArray(n) { it }
    val size = IntArray(n) { 1 }

    fun find(u: Int): Int {
      if (parent[u] == u) return u
      parent[u] = find(parent[u])
      return parent[u]
    }

    fun merge(u: Int, v: Int) {
      val pu = find(u)
      val pv = find(v)
      if (pu == pv) return
      if (size[pu] >= size[pv]) {
        parent[pv] = pu
        size[pu] += size[pv]
      } else {
        parent[pu] = pv
        size[pv] += size[pu]
      }
    }

    fun groups(): List<List<Int>> {
      val ans = mutableMapOf<Int, MutableList<Int>>()
      for (i in 0 until n) {
        ans.putIfAbsent(find(i), mutableListOf())
        ans[find(i)]!!.add(i)
      }
      return ans.values.map { it.toList() }
    }
  }

  val (n, m) = readLine()!!.split(" ").map(String::toInt)
  val a: List<Pair<Long, Int>> =
      readLine()!!.split(" ").mapIndexed { idx, it -> Pair(it.toLong(), idx) }
  val startPoint = a.minByOrNull { it.first }!!
  val adj = Array<MutableList<Pair<Int, Long>>>(n) { mutableListOf() }
  for (i in 0 until m) {
    val (u0, v0, w) = readLine()!!.split(" ").map(String::toLong)
    val u = u0.toInt() - 1
    val v = v0.toInt() - 1
    adj[u].add(Pair(v, w))
    adj[v].add(Pair(u, w))
  }

  val minEdge = Array(n) { Pair(a[it].first + startPoint.first, it) }
  minEdge[startPoint.second] = Pair(0, startPoint.second)
  val vis = BooleanArray(n)
  val pq = minEdge.toSortedSet(compareBy<Pair<Long, Int>> { it.first }.thenBy { it.second })
  var ans = 0L
  for (i in 0 until n) {
    val (dist, u) = pq.first()!!
    pq.remove(pq.first()!!)
    ans += dist
    vis[u] = true
    for ((v, length) in adj[u]) {
      if (!vis[v] && length < minEdge[v].first) {
        pq.remove(minEdge[v])
        minEdge[v] = Pair(length, v)
        pq.add(minEdge[v])
      }
    }
  }

  println(ans)
}
