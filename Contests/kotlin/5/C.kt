import java.io.*
import java.util.*
import java.math.*

fun main() {
    val t = readLine()!!.toInt()
    for(tt in 1..t){
        var (n, k) = readLine()!!.split(' ').map{it.toInt()}
        var s :MutableList<Int> = mutableListOf(*readLine()!!.split(' ').map{it.toInt()}.toTypedArray())
        var ans = 0
        for(i in n-1 downTo 0){
            var q = n-1 - i + 1
            var free = (q/k)
            var sum = 0
            var ate = i + free - 1
            ate = if(ate >= n) n-1 else ate
            for(j in i..ate){
                sum = sum + s[j]
            }
            ans = if(ans < sum) sum else ans
        }
        println(ans)

    }
}

// TLE? Melhor printar resposta inteira no fim do que printar aos poucos
// ------------ Data Structures ---------------------
// StringBuilder para usar string com append
// ArrayDeque - https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-deque/
//  - size
//  - add (no fim) / addLast / addFirst
//  - removeFirst (removeFirstOrNull) / removeLast (removeLastOrNull)


