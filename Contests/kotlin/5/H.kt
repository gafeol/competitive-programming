import java.io.*
import java.util.*
import java.math.*
import kotlin.math.*

fun main() {
    val c = Array(1501) { LongArray(1501) { -1 } }
    var (n, m, k) = readLine()!!.split(' ').map{it.toInt()}
    var A :MutableList<Long> = mutableListOf(*readLine()!!.split(' ').map{it.toLong()}.toTypedArray())
    var B :MutableList<Long> = mutableListOf(*readLine()!!.split(' ').map{it.toLong()}.toTypedArray())

    for(i in 0..n-1){
        var line :MutableList<Long> = mutableListOf(*readLine()!!.split(' ').map{it.toLong()}.toTypedArray())
        for(j in 0..m-1){
            c[i][j] = line[j]
            if(j > 0)
                c[i][j] = max(c[i][j], c[i][j-1])
            if(i > 0)
                c[i][j] = max(c[i][j], c[i-1][j])
        }
    }

    var ans: MutableList<Pair<Long, Long>> = mutableListOf()
    var i = 0
    var j = 0
    var act: Pair<Long, Long>  = Pair(-1.toLong(), -1.toLong())
    while(i < n || j < m){
        var cus = c[i][j] 
    }
}
