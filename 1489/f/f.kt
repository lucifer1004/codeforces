fun main() {
  val (n, m, k) = readLine()!!.split(" ").map(String::toInt)
  val a = readLine()!!.split(" ").map(String::toInt)
  var lo = 0
  var hi = n - 1
  while (lo <= hi) {
    val mid = (lo + hi).shr(1)
    var counter = 1
    var current = 0
    for (i in mid until n) {
      if (current + a[i] <= k) {
        current += a[i]
      } else {
        counter++
        current = a[i]
      }
    }
    if (counter > m) {
      lo = mid + 1
    } else {
      hi = mid - 1
    }
  }
  println(n - lo)
}
