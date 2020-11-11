import java.io.*
import java.util.*
import java.math.*

fun main() {
    val t = readLine()!!.toInt()
    for(tt in 1..t){
        var (n, m) = readLine()!!.split(' ').map{ it.toInt() }
        println(n + m)
    }
}

