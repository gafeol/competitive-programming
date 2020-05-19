fun main (){
    var (n, w) = readLine()!!.split(' ').map{x -> x.toInt()}
    var s = readLine()!!.split(' ').map{x -> x.toInt()}
    var mx = 0
    var mn = 0
    var sum = 0
    s.forEachIndexed{i, x ->
        sum += x
        mx = if(sum > mx) sum else mx
        mn = if(sum < mn) sum else mn
    }
    mx -= mn;
    println(if((w - mx + 1) > 0) (w - mx + 1) else 0);
}