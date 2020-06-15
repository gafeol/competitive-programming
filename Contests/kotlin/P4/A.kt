fun main() {
    var n = readLine()!!.toInt()
    for (i in 1..n){
        var (a, b) = readLine()!!.split(' ').map{x -> x.toInt()}
        println(a+b)
    }
}