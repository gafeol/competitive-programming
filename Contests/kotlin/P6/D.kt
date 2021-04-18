import java.io.*
import java.util.*
import kotlin.math.*

fun main() {
    val n = readLine()!!.toInt()

    var words = MutableList<Pair<Int, String>>(n, { Pair(0, "") })
    for(i in 0..n-1){
        val s = readLine()!!
        words[i] = Pair(s.length, s)
    }
    var orderedWords = words.sortedWith(compareBy({it.first}, {it.second}))

    for(i in 1..n-1){
        if(!orderedWords[i].second.contains(orderedWords[i-1].second)){
            println("NO")
            return 
        }
    }
    println("YES")
    orderedWords.forEach{ println(it.second) }

}

// TLE? Melhor printar resposta inteira no fim do que printar aos poucos
// ------------ Data Structures ---------------------
// StringBuilder para usar string com append
// ArrayDeque - https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-deque/
//  - size
//  - add (no fim) / addLast / addFirst
//  - removeFirst (removeFirstOrNull) / removeLast (removeLastOrNull)


