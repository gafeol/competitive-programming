fun test(lista : IntArray) : Boolean {
    if(lista[0] == lista[2] && lista[1] + lista[3] == lista[0])
        return true
    return false
}

fun main(){
    val t = readLine()!!.toInt()
    for(i in 1..t){
        var (a, b) = readLine()!!.split(' ').map{x -> x.toInt()}
        var (c, d) = readLine()!!.split(' ').map{x -> x.toInt()}
        if(test(intArrayOf(a, b, c, d)) or test(intArrayOf(b, a, c, d)) or test(intArrayOf(a, b, d, c)) or test(intArrayOf(b, a, d, c)))
            println("Yes")
        else
            println("No")
    }
}