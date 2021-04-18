import java.io.*
import java.util.*
import kotlin.math.*
import kotlin.*

fun main() {
    var n = readLine()!!.toInt() 
    var s : String = readLine()!!
    var res = 0
    var cnt = 0
    for(i in 0..n-1){
        if(s[i] == 'x'){
            cnt++
            if(cnt >= 3){
                res++ 
            }
        }
        else{
            cnt = 0
        }
    }
    println(res)
}

// TLE? Melhor printar resposta inteira no fim do que printar aos poucos
// ------------ Data Structures ---------------------
// StringBuilder para usar string com append
// ArrayDeque - https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-deque/
//  - size
//  - add (no fim) / addLast / addFirst
//  - removeFirst (removeFirstOrNull) / removeLast (removeLastOrNull)


