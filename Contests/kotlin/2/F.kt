import java.io.*
import java.util.*
import java.math.*

var temp = ArrayDeque<Int>()
var fin = ArrayDeque<Int>()

var piece: MutableMap<Char, ArrayDeque<Pair<Int, Char>>> = mutableMapOf();

fun euler_dfs(at: Char, i : Int) {
    if(i > 0){
        temp.add(i)
    }
    while(!piece[at]!!.isEmpty()){ 
        var (ni, lst) = piece[at]!!.removeFirst()
        euler_dfs(lst, ni)
    }
    if(!temp.isEmpty()){
        fin.add(temp.removeLast())
    }
}

fun main() {
    var n = readLine()!!.toInt() 
    piece['k'] = ArrayDeque<Pair<Int, Char>>()
    piece['o'] = ArrayDeque<Pair<Int, Char>>()
    piece['t'] = ArrayDeque<Pair<Int, Char>>()
    piece['l'] = ArrayDeque<Pair<Int, Char>>()
    piece['i'] = ArrayDeque<Pair<Int, Char>>()
    piece['n'] = ArrayDeque<Pair<Int, Char>>()
    var nxt: MutableMap<Char, Char> = mutableMapOf(
        'k' to 'o',
        'o' to 't',
        't' to 'l',
        'l' to 'i',
        'i' to 'n',
        'n' to 'k'
   )

    for(i in 1..n){
        var s  = readLine()!!
        piece[s[0]]!!.add(Pair(i, nxt[s.last()]!!))
    }
    var at = 'k'
    euler_dfs(at, 0)
    var rev = fin.reversed()
    println(rev.joinToString(separator=" ") { it.toString() })
}

// TLE? Melhor printar resposta inteira no fim do que printar aos poucos
// ------------ Data Structures ---------------------
// StringBuilder para usar string com append
// ArrayDeque - https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-deque/
//  - size
//  - add (no fim) / addLast / addFirst
//  - removeFirst (removeFirstOrNull) / removeLast (removeLastOrNull)


