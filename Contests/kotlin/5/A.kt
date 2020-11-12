import java.io.*
import java.util.*
import java.math.*

fun max(a:Long, b:Long): Long{
    if( a> b){
        return a;
    }
    return b;
}

fun main() {
    val t = readLine()!!.toInt()
    for(tt in 1..t){
        var n = readLine()!!.toInt() 
        var s :MutableList<Long> = mutableListOf(*readLine()!!.split(' ').map{it.toLong()}.toTypedArray())

        var ans:Long = 0
        for(i in 0..n-1){
            var sum:Long= 0
            for(j in 0..n-1){
                if(s[j] >= s[i]){
                    sum += s[i]
                }
            }
            ans = max(ans, sum)
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


