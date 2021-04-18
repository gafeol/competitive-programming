import kotlin.math.*

fun main () {
    val t = readLine()!!.toInt()
    for(nt in 1..t){
        val n = readLine()!!.toInt()
        var s = readLine()!!.split(' ').map{it.toInt()}
        val cnt = Array<Int>(n+1, {0})
        var tot = Array<Int>(n+1, {0})
        val pos = Array<Int>(n+1, {0})
        for(x in s){
            tot[x]++
        }
        var v : MutableList<Pair<Int, Int>> = mutableListOf()
        for(i in 0..n-1){
            val x = s[i]
            if(tot[x] == 1){
                v.add(Pair(i, i))
            }
            else{
                if(cnt[x] == 0){
                    pos[x] = i
                }
                else{
                    v.add(Pair(pos[x], i))
                }
                cnt[x]++
            }
        }
        var sortedV = v.sortedWith(compareBy({it.first}, {it.second}))
        var q = Array<Int>(n+1, {0})
        q[0] = 100000000
        var sz = 1
        var res = 0
        for(i in 0..sortedV.size-1){
            var x = sortedV[i].second
            var l = 0
            var r = sz-1
            while(l < r){
                var m = (1 + l + r)/2
                if(q[m] >= x){
                    l = m
                }
                else{
                    r = m-1
                }
            }
            if(sortedV[i].first == sortedV[i].second){
                res = max(res, l*2 + 1)

            }
            else {

                res = max(res, (l+1)*2 + if(sortedV[i].first != sortedV[i].second -1) 1 else 0)
                q[l+1] = x
                sz = max(sz, l+2)
            }
        }

        println(res)
    }
}
