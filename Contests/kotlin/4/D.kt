fun main() {
    val t = readLine()!!.toInt()
    for(i in 1..t){
        var (n, m) = readLine()!!.split(' ').map{it.toInt()}
        var ans:MutableList<Int> = mutableListOf(0)
        for(i in 1..n)
            ans.add(0);
        var ar:MutableList<Pair<Int, Pair<Int,Int> > > = mutableListOf()
        for(i in 0..m-1){
            var (i, j, k) = readLine()!!.split(' ').map{it.toInt()}
            ar.add(Pair<Int, Pair<Int, Int>>(k, Pair<Int, Int>(i, j)));
        }
        ar.sortWith(compareBy({-it.first}, {it.second.first}, {it.second.second}));
        var ok = true;
        ar.forEach{ p ->
            var k = p.first; 
            var u = p.second.first;
            var v = p.second.second;
            if(ans[u] > k && ans[v] > k){
                //println("False pq u $u ${ans[u]} v $v ${ans[v]}");
                ok = false;
            }
            if(ans[u] < k){
                if(ans[u] != 0){
                    //println("false pq u $u era ${ans[u]} e agora quer $k");
                    ok = false;
                }
                ans[u] = k;
            }
            if(ans[v] < k){
                if(ans[v] != 0){
                    //println("false pq u $v era ${ans[v]} e agora quer $k");
                    ok = false;
                }
                ans[v] = k;
            }
        }
        println(if(ok) "YES" else "NO");
        if(ok){
            for(i in 1..n){
                print("${ans[i]} ")
            }
            println();
        }
    }
}

