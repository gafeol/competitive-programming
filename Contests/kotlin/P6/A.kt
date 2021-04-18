import java.io.*
import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    var s :MutableList<Int> = mutableListOf(*readLine()!!.split(' ').map{it.toInt()}.toTypedArray())
    var cnt : MutableMap<Int, Int> = mutableMapOf()
    s.forEach{cnt[it] = cnt.getOrDefault(it, 0) + 1}
    println(cnt.size)
    for(i in 0..n-1){
        if(cnt[s[i]] == 1)
            print("${s[i]} ")
        cnt[s[i]] = cnt.get(s[i])!! - 1
    }
    println()
}

// TLE? Melhor printar resposta inteira no fim do que printar aos poucos
// ----------- Data Structures ---------------------
// StringBuilder para usar string com append
// ArrayDeque - https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-deque/
//  - size
//  - add (no fim) / addLast / addFirst
//  - removeFirst (removeFirstOrNull) / removeLast (removeLastOrNull)


