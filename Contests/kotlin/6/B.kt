import java.util.Stack
import kotlin.math.*

fun main()  {
    val t = readLine()!!.toInt()
    for(nt in 1..t){
        val q = Stack<Int>()
        val (n, k) = readLine()!!.split(' ').map{it.toInt()}
        val s = readLine()!!
        var next = Array<Int>(n, {0})
        for(i in 0..n-1){
            if(s[i] == '('){
                q.push(i)
            }
            else{
                val pos = q.peek()
                next[pos] = i
                q.pop()
            }
        }
        var extra = 0
        var i = 0
        var res = 0
        while(i < n){
            res++
            extra += (next[i] - i+1)/2 - 1
            i = next[i]
            i++
        }
        println(res + min(extra, k))
    }
}