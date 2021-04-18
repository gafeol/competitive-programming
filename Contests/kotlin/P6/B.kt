import java.io.*
import java.util.*
import kotlin.math.*

fun main() {
    val t = readLine()!!.toInt()
    for(tt in 1..t){
        var (n, p, pp) = readLine()!!.split(' ').map{it.toLong()}
        pp = min(pp, p*2)
        println((n/2)*pp + (n and 1)*p)
    }
}

// TLE? Melhor printar resposta inteira no fim do que printar aos poucos
// ------------ Data Structures ---------------------
// StringBuilder para usar string com append
// ArrayDeque - https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-deque/
//  - size
//  - add (no fim) / addLast / addFirst
//  - removeFirst (removeFirstOrNull) / removeLast (removeLastOrNull)


