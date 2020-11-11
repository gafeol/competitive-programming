import java.io.*
import java.util.*
import java.math.*

fun main() {
    val t = readLine()!!.toInt()
    for(tt in 1..t){
        var n = readLine()!!.toInt() 
        var s :MutableList<Int> = mutableListOf(*readLine()!!.split(' ').map{x -> x.toInt()}.toTypedArray())
        var sum = 0
        for(x in s){
            sum += x 
        }
        println((sum+n-1)/n)
    }
}

