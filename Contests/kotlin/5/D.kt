import java.io.*
import java.util.*
import java.math.*

fun <T, U> pairComparator(
    firstComparator: Comparator<T>, 
    secondComparator: Comparator<U>
): Comparator<Pair<T, U>> = 
         compareBy(firstComparator) { p: Pair<T, U> -> p.first }
          .thenBy(secondComparator) { p: Pair<T, U> -> p.second }

fun main() {
    val t = readLine()!!.toInt()
    for(tt in 1..t){
        var n = readLine()!!.toInt() 
        var s :MutableList<Int> = mutableListOf(*readLine()!!.split(' ').map{it.toInt()}.toTypedArray())
        var dd: MutableList<Pair<Int, Int>> = mutableListOf()
        for((i, x) in s.withIndex()){
            dd.add(Pair(x, i))
        }
        var dx = dd.sortedWith(pairComparator(naturalOrder(), naturalOrder()))
        var d = ArrayDeque<Pair<Int, Int>>()
        for(p in dx)
            d.add(p)
        var old = 0
        while(!d.isEmpty()){
            //println("First ${d.first().first} ${d.first().second} LSt ${d.last().first} ${d.last().second}")
            if(d.first()!!.first <= old){
                var (_, i) = d.removeFirst()
                i = i + 1
                print("$i ")
                old = 1
            }
            else{
                var (_, i) = d.removeLast()
                i = i + 1
                print("$i ")
                old = old + 1
            }
        }
        println()
    }
}

// TLE? Melhor printar resposta inteira no fim do que printar aos poucos
// ------------ Data Structures ---------------------
// StringBuilder para usar string com append
// ArrayDeque - https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-deque/
//  - size
//  - add (no fim) / addLast / addFirst
//  - removeFirst (removeFirstOrNull) / removeLast (removeLastOrNull)


