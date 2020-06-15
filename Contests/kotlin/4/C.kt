fun main() {
    val t = readLine()!!.toInt()
    for(i in 1..t){
        var (n, k, x, y) = readLine()!!.split(' ').map{it.toLong()}
        var s :MutableList<Long> = mutableListOf(*readLine()!!.split(' ').map{x -> x.toLong()}.toTypedArray())
        s.sortWith(compareBy({-it}));
        var soma:Long = "0".toLong()
        var mx:Long = "0".toLong()
        for(i in 0..n-1){
            soma += s[i.toInt()]
            mx = Math.max(mx, s[i.toInt()])
        }

        if(mx <= k){
            println("0");
            continue;
        }
        
        var res:Long = "0".toLong()
        for(i:Long in 0..n-1){
            if(s[i.toInt()] > k){
                res += x;
            }
        }

        var cus:Long = "0".toLong();
        for(i:Long in 0..n-1){
            if((soma+n-1)/n <= k){
                break;
            }
            soma -= s[i.toInt()]
            cus += x;
        }
        println(Math.min(res, cus+y));
    }
}

