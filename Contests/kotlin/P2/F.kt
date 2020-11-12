import java.io.*
import java.util.*
import java.math.*

// StringBuilder para usar string com append
// TLE? Melhor printar resposta inteira no fim do que printar aos poucos

fun abs(x: Int) : Int {
    if(x < 0) return -x;
    return x;
}

fun main() {
    var str = readLine()!!
    var n = str.length
    var ans:Long = 0
    var curr = 0
    for(i in 0..n-1){
        ans += abs(curr - (str[i] - '0'))*((n-i).toLong())
        curr = str[i] - '0'
    }
    println(ans)
}

