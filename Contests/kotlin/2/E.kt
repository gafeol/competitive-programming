import kotlin.collections.ArrayDeque;
// StringBuilder para usar string com append
// TLE? Melhor printar resposta inteira no fim do que printar aos poucos

val MAXN = 200009

fun main() {
    var n = readLine()!!.toInt() 
    var s :MutableList<Int> = mutableListOf(*readLine()!!.split(' ').map{x -> x.toInt()}.toTypedArray())
    var cnt = Array<MutableList<Int>>(MAXN){mutableListOf()}
    for((i, x) in s.withIndex()){
        if(x > MAXN) continue
        cnt[x].add(i)
    }
    var ate = n
    for(i in 1..n){
        if(cnt[i].size != 2){
            ate = i-1
            break
        }
    }

    fun ok(x : Int): Boolean {
        var dq: ArrayDeque<Int> = ArrayDeque<Int>()
        for((i, e) in s.withIndex()){
            if(e > x) continue
            if(dq.isEmpty() || dq.first() != e){
                dq.addLast(e)
            }
            else{
                dq.removeFirst()
            }
        }
        return (dq.isEmpty())
    }


    var l = 0
    var r = ate
    while(l < r){
        var m = (l + r + 1)/2
        if(ok(m))
            l = m
        else
            r = m-1
    }

    ate = l
    for(x in s){
        if(x > ate)
            print("B")
        else{
            print(if(cnt[x].size == 2) "R" else "G")
            cnt[x].removeAt(cnt[x].lastIndex)
        }
    }
}

