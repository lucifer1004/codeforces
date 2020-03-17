fun readInt(): Int {
    return readLine()!!.toInt()
}

data class Team(var name: String) {
    var points = 0
    var scored = 0
    var conceded = 0
}

fun main() {
    val n = readInt()
    val teams = mutableListOf<Team>()
    val lookup = mutableMapOf<String, Int>()
    for (i in 0 until n) {
        val name = readLine()!!
        teams.add(Team(name))
        lookup[name] = i
    }
    for (i in 0 until n * (n - 1) / 2) {
        val info = readLine()!!
        val (names, scores) = info.split(" ")
        val (a, b) = names.split("-")
        val (ag, bg) = scores.split(":").map(String::toInt)
        val at = lookup[a]!!
        val bt = lookup[b]!!
        when {
            ag > bg -> teams[at].points += 3
            ag < bg -> teams[bt].points += 3
            else -> {
                teams[at].points += 1
                teams[bt].points += 1
            }
        }
        teams[at].scored += ag
        teams[at].conceded += bg
        teams[bt].scored += bg
        teams[bt].conceded += ag
    }
    teams.sortWith(
        compareByDescending<Team> { it.points }
            .thenByDescending { it.scored - it.conceded }
            .thenByDescending { it.scored })
    val winners = mutableListOf<String>()
    for (i in 0 until n / 2)
        winners.add(teams[i].name)
    winners.sort()
    println(winners.joinToString("\n"))
}