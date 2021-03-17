fun main() {
    val t = readLine()!!.toInt()
    for(i in 1..t){
        var (x, y) = readLine()!!.split(' ').map{it.toLong()}
        var dez = 1000000000.toLong()
        var cnt = 0.toLong()
        while(dez >= 1){
            if(y >= x*dez) {
                cnt += y/(x*dez)
                y = y%(x*dez)
            }
            dez /= 10
        }
        cnt += y
        println(cnt)
    }
}