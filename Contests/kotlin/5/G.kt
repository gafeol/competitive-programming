import java.io.*
import java.util.*
import java.math.*
import kotlin.math.*

fun main() {

    var (n, k) = readLine()!!.split(' ').map{it.toInt()}
    var s :MutableList<Long> = mutableListOf(*readLine()!!.split(' ').map{it.toLong()}.toTypedArray())
    s.sort()

    var sum: MutableList<Long>  = mutableListOf()  
    var csum: Long = 0
    for(x in s){
        csum = csum + x
        sum.add(csum)
    }

    val dp = Array(410) { LongArray(210) { -1 } }

    fun go(i: Int, k:Int): Long {
        if(i == n){
            dp[i][k] = 0.toLong()
            return dp[i][k]
        }
        if(dp[i][k] != -1.toLong()){
            return dp[i][k];
        }
        dp[i][k] = go(i+1, k)
        for(usa in 1..k){
            var j = i + 2*usa -1
            if(j >= n) break
            var soma = sum[j] - sum[j - usa]
            var sub = sum[i+usa-1] - (if(i > 0) sum[i-1] else 0)
            //println("no i $i k $k usa  $usa soma $soma sub $sub go ${go(j+1, k-usa)}")
            dp[i][k] = max(dp[i][k], go(j+1, k - usa) + soma - sub)
        }
        return dp[i][k]
    }
    println(go(0, k))
}

// TLE? Melhor printar resposta inteira no fim do que printar aos poucos
// ------------ Data Structures ---------------------
// StringBuilder para usar string com append
// ArrayDeque - https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-deque/
//  - size
//  - add (no fim) / addLast / addFirst
//  - removeFirst (removeFirstOrNull) / removeLast (removeLastOrNull)


