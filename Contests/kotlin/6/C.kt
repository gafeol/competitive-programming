import kotlin.math.*
fun main() {
    val t = readLine()!!.toInt()
    for(nt in 1..t){
        var (n, x, y) = readLine()!!.split(' ').map{it.toInt()}
        if(x > y){
            val aux = y
            y = x
            x = aux
        }
        var res = 10000000
        for(i in x..y){
            val lx = x - 1 + i - 1
            val rx = max(0, i - x) + i - 1
            val ly = max(0, y - i) + n - i
            val ry = n - y + n - i
           res = min(res, max(lx, ly)) 
           res = min(res, max(lx, ry))
           res = min(res, max(rx, ly)) 
           res = min(res, max(rx, ry))
           //println("at $i res $res lx $lx rx $rx ly $ly ry $ry")
        }
        for(i in x+1..y){
            val lx = x - 1 + i
            val rx = max(0, i + 1 - x) + i
            val ly = max(0, y - i) + n - i
            val ry = n - y + n - i
           res = min(res, max(lx, ly)) 
           res = min(res, max(lx, ry))
           res = min(res, max(rx, ly)) 
           res = min(res, max(rx, ry))
           //println("at $i res $res lx $lx rx $rx ly $ly ry $ry")
        }
        for(i in x..y-1){
            val lx = x - 1 + i - 1
            val rx = max(0, i - x) + i - 1
            val ly = max(0, y - i - 1) + n - i -1 
            val ry = n - y + n - i - 1
           res = min(res, max(lx, ly)) 
           res = min(res, max(lx, ry))
           res = min(res, max(rx, ly)) 
           res = min(res, max(rx, ry))
           //println("at $i res $res lx $lx rx $rx ly $ly ry $ry")
        }
        println(res)
    }
}