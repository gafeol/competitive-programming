import java.io.*
import java.util.*
import kotlin.math.*

fun main() {
    var (n, m) = readLine()!!.split(' ').map{it.toInt()}
    for(i in 1..m){
        var (us, vs, cs) = readLine()!!.split(' ')
        var u = us.toInt()
        var v = vs.toInt()
        var c = cs.toLong()
    }

}

// TLE? Melhor printar resposta inteira no fim do que printar aos poucos
// ------------ Data Structures ---------------------
// StringBuilder para usar string com append
// ArrayDeque - https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-deque/
//  - size
//  - add (no fim) / addLast / addFirst
//  - removeFirst (removeFirstOrNull) / removeLast (removeLastOrNull)


