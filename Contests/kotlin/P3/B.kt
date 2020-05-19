//Remove duplicates
//https://codeforces.com/problemset/problem/978/A

fun readInts() = readLine()!!.split(' ').map { it.toInt() }

fun main(){
    val n = readInts()
    var s = readInts()
    var lst : MutableMap<Int, Int> = mutableMapOf<Int, Int>()

    s.forEachIndexed{ index, value -> (
        lst.put(value, index)
    )}
    println(lst.size)
    s.forEachIndexed{ index, value -> (
        if(lst.get(value) == index){
            print("$value ")
        }
    )}
    println()
}