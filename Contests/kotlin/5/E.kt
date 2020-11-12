import java.io.*
import java.util.*
import java.math.*
import kotlin.math.*

fun main() {
    val t = readLine()!!.toInt()
    for(tt in 1..t){
        var n = readLine()!!.toInt() 
        var s :MutableList<Int> = mutableListOf(*readLine()!!.split(' ').map{it.toInt()}.toTypedArray())
        var ss :MutableList<Int> = mutableListOf(*readLine()!!.split(' ').map{it.toInt()}.toTypedArray())
        var ans = 0
        for(k in 0..n-1){
            var mn = 2000000
            for(i in 0..n-1){
                var j = (i+k)%n
                mn = min(mn, abs(s[i] - ss[j]))
            }
            ans = max(ans, mn)
        }

        for(k in 0..n-1){
            var mn = 2000000
            for(i in 0..n-1){
                var j = (i+k)%n
                mn = min(mn, abs(s[i] - ss[j]))
            }
            if(mn == ans){
                for(i in 0..n-1){
                    var j = (i+k)%n
                    print("${j+1} ")
                }
                println()
                break
            }
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


