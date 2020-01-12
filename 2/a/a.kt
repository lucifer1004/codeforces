import java.util.Scanner

class Transaction(name: String, score: Int) {
    val name = name
    val score = score
}

fun main() {
    val scanner = Scanner(System.`in`)
    val n = scanner.nextInt()
    val scoreBoard = mutableMapOf<String, Int>()
    val history = mutableListOf<Transaction>()
    scanner.nextLine()
    for (i in 0 until n) {
        val (name, rawScore) = scanner.nextLine().split(' ')
        val score = rawScore.toInt()
        scoreBoard[name] = scoreBoard.getOrDefault(name, 0) + score
        history.add(Transaction(name, score))
    }
    var highestScore = (-1e9).toInt()
    val winners = mutableSetOf<String>()
    for ((name, score) in scoreBoard) {
        if (score > highestScore) {
            winners.clear()
            winners.add(name)
            highestScore = score
        } else if (score == highestScore) {
            winners.add(name)
        }
    }
    scoreBoard.clear()
    for (transaction in history) {
        val newScore = scoreBoard.getOrDefault(transaction.name, 0) + transaction.score
        if (newScore >= highestScore && winners.contains(transaction.name)) {
            println(transaction.name)
            return
        }
        scoreBoard[transaction.name] = newScore
    }
}
