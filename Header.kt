import java.io.*
import java.util.*
import java.math.*

fun main() {
    val t = readLine()!!.toInt()
    for(tt in 1..t){
        var n = readLine()!!.toInt() 
        var s :MutableList<Int> = mutableListOf(*readLine()!!.split(' ').map{it.toInt()}.toTypedArray())
    }
}

// TLE? Melhor printar resposta inteira no fim do que printar aos poucos
// ------------ Data Structures ---------------------
// StringBuilder para usar string com append
// ArrayDeque - https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-deque/
//  - size
//  - add (no fim) / addLast / addFirst
//  - removeFirst (removeFirstOrNull) / removeLast (removeLastOrNull)

