import java.io.*
import java.util.*
import kotlin.math.*

fun main() {
    val pos : MutableMap<Int, Pair<Int, Int>> = mutableMapOf()
    var sz = Array<Int>(2, {0})
    var n = readLine()!!.toInt() 
    for(i in 1..n){
        var (pc, ids) = readLine()!!.split(' ')
        var p = pc[0]
        var id = ids.toInt()
        if(p == '?'){
            println(min(sz[1 - pos[id]!!.first] + pos[id]!!.second, sz[pos[id]!!.first] - pos[id]!!.second - 1))
        }
        else if(p == 'R'){
            pos[id] = Pair(1, sz[1])
            sz[1]++
        }
        else {
            pos[id] = Pair(0, sz[0])
            sz[0]++
        }
    }
}

// TLE? Melhor printar resposta inteira no fim do que printar aos poucos
// ------------ Data Structures ---------------------
// StringBuilder para usar string com append
// ArrayDeque - https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-deque/
//  - size
//  - add (no fim) / addLast / addFirst
//  - removeFirst (removeFirstOrNull) / removeLast (removeLastOrNull)


