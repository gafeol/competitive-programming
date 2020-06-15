fun main() {
    val t = readLine()!!.toInt()
    for(i in 1..t){
        var ans = 0
        var (n, k1, k2) = readLine()!!.split(' ').map{it.toInt()}
        var st = readLine()!!
        var prv = 0
        for(i in 0..n-1){
            if(st[i] == '0'){
                prv = 0
            }
            else{
                var aqui = Math.min(k2 - prv, k1);
                ans += aqui;
                prv = aqui;
            }
        }
        println(ans)
    }
}

