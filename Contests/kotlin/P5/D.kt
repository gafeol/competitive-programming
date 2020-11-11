import java.io.*
import java.util.*
import java.math.*

fun main() {
    val t = readLine()!!.toInt()
    for(tt in 1..t){
        var (n, _, b) = readLine()!!.split(' ').map{ it.toInt()}
        for(i in 0..n-1){
            print(('a' + i%b))
        }
        println()
    }
}

