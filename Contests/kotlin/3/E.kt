var ans: MutableList<Boolean> = mutableListOf();
var adj: MutableList<MutableList<Int>> = mutableListOf(mutableListOf())
var n:Int=0;
var k:Int = 0;

fun go (u : Int, p : Int){
    ans[u] = true;
    var first = 0;
    adj[u].forEach{nxt ->
        if(nxt != p && first == 0) {
            first++;
            go(nxt, u);
        }
    }
    adj[u].forEach{nxt ->
        if(nxt != p) {
            if(first > 0){
                first--;
            }
            else if(k > 0) {
                k--;
                go(nxt, u);
            }

        }
    }
}

fun main() {
    val t = readLine()!!.toInt()
    for(i in 1..t){
        adj.clear();
        adj = mutableListOf(mutableListOf())
        ans.clear();
        ans.add(false);
        val s = readLine()!!.split(' ').map{x -> x.toInt()}
        n = s[0]
        k = s[1]
        for(u in 1..n){
            adj.add(mutableListOf())
            ans.add(false)
        }
        for(a in 2..n){
            var (i, j) = readLine()!!.split(' ').map{x -> x.toInt()}
            adj[i].add(j)
            adj[j].add(i)
        }
        var f:Int = 0;
        for(u in 1..n){
            if(adj[u].size == 1)
                f = u
        }
        if(k == 1){
            println("Yes");
            println("1");
            println(f);
            continue;
        }
        k -= 2;
        ans[f] = true;
        go(adj[f][0], f);
        if(k == 0){
            println("Yes");
            var cnt = 0;
            for(u in 1..n){
                cnt += if(ans[u] == true) 1 else 0;
            }
            println(cnt);
            for(u in 1..n){
                if(ans[u] == true)
                    print("$u ");
            }
            println()
        }
        else{
            println("No");
        }
    }
}

