var n = 0
var m = 0
var k = 0

fun check(ii : Int, s : MutableList<Long>) : Boolean {
    var uses = 0
    var sum = 0.toLong()
    var i = ii
    while(i < s.size){
        if(sum + s[i] <= k.toLong()){
            sum += s[i]
        }
        else{
            sum = s[i]
            uses++
        }
        i++
    }
    if(sum > 0)
        uses++

    return (uses <= m)
}


fun main() {
    readLine()!!.split(' ').map{it.toInt()}.let {
        n = it[0]
        m = it[1]
        k = it[2]
    }
    var s :MutableList<Long> = mutableListOf(*readLine()!!.split(' ').map{it.toLong()}.toTypedArray())
    var l = 0
    var r = n-1
    while(l < r){
        val mid = (l + r)/2
        if(check(mid, s)){
            r = mid
        }
        else {
            l = mid+1
        }
    }
    println(n - l)
}

// TLE? Melhor printar resposta inteira no fim do que printar aos poucos
// ------------ Data Structures ---------------------
// StringBuilder para usar string com append
// ArrayDeque - https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-deque/
//  - size
//  - add (no fim) / addLast / addFirst
//  - removeFirst (removeFirstOrNull) / removeLast (removeLastOrNull)


