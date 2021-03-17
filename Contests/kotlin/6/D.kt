import kotlin.math.*
fun maxVal(ini : Long, days : Int) : Long  {
    if(log(ini.toDouble(), 10.0) + log(((1.toLong() shl days) -1) + 0.0, 10.0) >= log(3000000000000000000.0, 10.0))
        return 3000000000000000000
    return (ini*((1.toLong() shl days) - 1))
}
fun main () {
    val t = readLine()!!.toInt()
    for(i in 1..t){
        var (n, k) = readLine()!!.split(' ').map{it.toLong()}
        var fst = true
        if(n > 61){
            k -= (n-61) 
            n = 61
            fst = false
        }
        var prv = 1.toLong()
        while(n > 0){
            var l = prv
            var r = prv*2
            if(fst){
                fst = false
                l = 1
                r = 1000000000000000000.toLong()
            }
            while(l < r){
                var m = (l + r)/2        
                //println("maxval de m $m com $n dias eh ${maxVal(m, n.toInt())}")
                if(maxVal(m, n.toInt()) >= k){
                    r = m
                }
                else{
                    l = m+1
                }
            }
            //println("choose l $l now n $n k $k")
            k -= l
            n--
            prv = l
        }
        println(prv)
    }
}