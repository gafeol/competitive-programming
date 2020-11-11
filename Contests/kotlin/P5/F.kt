import java.io.*
import java.util.*
import java.math.*

// StringBuilder para usar string com append
// TLE? Melhor printar resposta inteira no fim do que printar aos poucos

fun main() {
    var (n, m, d) = readLine()!!.split(' ').map{it.toInt()}
    var s :MutableList<Int> = mutableListOf(*readLine()!!.split(' ').map{x -> x.toInt()}.toTypedArray())

    var ans = Array<Int>(n){0}
    var sum = 0
    for(x in s)
        sum += x

    var lst = -1
    var i = 0
    var pos = 0
    while(pos < n){
        if(pos + sum == n || pos - lst == d){
            if(i == m){
                println("NO")
                return 
            }
            sum -= s[i]
            while(s[i] > 0){
                ans[pos] = i+1
                s[i]--
                pos++
            }
            i++
            lst = pos-1
        }
        else
            pos++
    }
    println("YES")
    for(x in ans){
        print(x)
        print(" ")
    }
    println()
}

