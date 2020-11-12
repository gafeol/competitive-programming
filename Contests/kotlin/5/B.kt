import java.io.*
import java.util.*
import java.math.*

fun main() {
    val t = readLine()!!.toInt()
    for(tt in 1..t){
        var s :String = readLine()!!

        var ok: Boolean = false
        var lstC = 'w'
        var ans = 0
        for(c in s){
            if(c == 'w')
                ans = ans+1
            else{
                if(lstC != 'v' || ok == true){
                    ok = false
                }
                else{
                    ans = ans + 1
                    ok = true
                }
            }
            lstC = c;
        }
        println(ans); 
    }
}

// TLE? Melhor printar resposta inteira no fim do que printar aos poucos
// ------------ Data Structures ---------------------
// StringBuilder para usar string com append
// ArrayDeque - https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-deque/
//  - size
//  - add (no fim) / addLast / addFirst
//  - removeFirst (removeFirstOrNull) / removeLast (removeLastOrNull)


