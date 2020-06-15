fun main() {
    val (n, k) = readLine()!!.split(' ').map{x -> x.toInt()}
    val l = readLine()!!.split(' ').map{x->x.toInt()}
    var mx = 0
    l.forEach{x ->
        mx = if(mx > x*k) mx else x*k;
    }
    if(mx%1000 > 0)
        mx += 1000;
    mx = mx/1000;
    println(mx);
    
}
