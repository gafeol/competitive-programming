import java.io.*
import java.util.*
import java.math.*




fun main() {
    var (n, k, x) = readLine()!!.split(' ').map{it.toInt()}
    var s :MutableList<Long> = mutableListOf(*readLine()!!.split(' ').map{it.toLong()}.toTypedArray())

    fun check(mxSum: Long): Boolean {
        var t: PriorityQueue<Long>  = PriorityQueue<Long>(Collections.reverseOrder())
        var sum: Long = 0
        var used = 0
        for(e in s){
            t.add(e)
            sum = sum + e
            if(sum > mxSum){
                var apg = t.poll()
                sum = sum - apg
                used = used + 1
            }

            if(t.size == x){
                sum = 0 
                t.clear()
            }
        }
        return (used <= k)
    }

    var l = 0.toLong()
    var r = (100000.toLong())*100001

    while(l < r){
        var m = (l + r)/2;
        if(check(m))
            r = m
        else
            l = m + 1
    }
    println(l)
}

// TLE? Melhor printar resposta inteira no fim do que printar aos poucos
// ------------ Data Structures ---------------------
// StringBuilder para usar string com append
// ArrayDeque - https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-deque/
//  - size
//  - add (no fim) / addLast / addFirst
//  - removeFirst (removeFirstOrNull) / removeLast (removeLastOrNull)


