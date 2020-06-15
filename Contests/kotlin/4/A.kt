fun main() {
    val t = readLine()!!.toInt()
    for(i in 1..t){
        var (n, k) = readLine()!!.split(' ').map{it.toLong()}
        var x :Long = n/(1 + k + k*k + k*k*k);
        println("$x ${x*k} ${x*k*k} ${x*k*k*k}");
    }
}

