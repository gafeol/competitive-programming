fun main() {
    val t = readLine()!!.toInt()
    for(i in 1..t){
        var (n, k) = readLine()!!.split(' ').map{x->x.toInt()}
        var s :MutableList<Int> = mutableListOf(*readLine()!!.split(' ').map{x -> x.toInt()}.toTypedArray())
        var sl: MutableList<Pair<Int, Int>> = mutableListOf()
        s.forEachIndexed{i, x ->
            sl.add(Pair<Int, Int>(x, i));
            s[i] = 0;
        }
        var sortedList :MutableList<Pair<Int, Int>> = mutableListOf(*sl.sortedWith(compareBy({-it.first}, {it.second})).toTypedArray());
        for(i in 1..sortedList.size-1){
            val idx = sortedList[i].second;
            val sum = Math.min(sortedList[i-1].first - sortedList[i].first - 1, k);
            //println("Soma $sum em $idx (${sortedList[i].first}) para alcancar ${sortedList[i-1].first}");
            s[idx] += sum
            sortedList[i] = Pair<Int, Int>(sortedList[i].first + sum, sortedList[i].second);
            k -= sum;
        }
        val sum = k/n;
        k -= sum*n;
        for(i in 0..s.size-1){
            s[i] += sum
        }
        sortedList.forEach{x ->
            val i = x.second;
            if(k > 0) {
                s[i]++;
                k--;
            }
        }
        for(i in 0..n-1){
            print("${s[i]} ");
        }
        println();
    }
}

