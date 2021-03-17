import kotlin.math.*
lateinit var nxt : Array<Int>
lateinit var tot : Array<Int>
lateinit var s : List<Int>

fun solve(l : Int, r : Int): Int {
    //println("solve l $l r $r")
    if(l > r){
        return 0
    }
    else if(l == r){
        return 1
    }
    var res = 0
    var i = l
    while(i <= r){
        //println("i $i nxt ${nxt[i]} res $res")
        if(nxt[i] >= 0 && nxt[i]-1 <= r){
            res = max(res, solve(i+1, nxt[i]-2) + tot[s[i]])
        }
        else{
            res = max(res, 1)
        }
        if(nxt[i] == -1){
            i = i+1
        }
        else{
            i = nxt[i]
        }
    }
    return res
}

fun main () {
    val t = readLine()!!.toInt()
    for(nt in 1..t){
        val n = readLine()!!.toInt()
        s = readLine()!!.split(' ').map{it.toInt()}
        val cnt = Array<Int>(n+1, {0})
        tot = Array<Int>(n+1, {0})
        val pos = Array<Int>(n+1, {0})
        nxt = Array<Int>(n+1, {-1})
        for(x in s){
            tot[x]++
        }
        for(i in 0..n-1){
            val x = s[i]
            if(tot[x] == 1){
                nxt[i] = i+1
            }
            else{
                if(cnt[x] == 0){
                    pos[x] = i
                }
                else{
                    nxt[pos[x]] = i+1
                }
                cnt[x]++
            }
        }
        println(solve(0, n-1))
    }
}