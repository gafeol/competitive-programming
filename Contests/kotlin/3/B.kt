fun main () {
    var t = readLine()!!.toInt()
    while(t-- > 0) {
        val n = readLine()!!.toInt()

        var q: MutableMap<Int, Int> = mutableMapOf();
        for (i in 1..n) {
            val (a, b) = readLine()!!.split(' ').map { x -> x.toInt() }
            q.put(a, 1 + q.getOrDefault(a, 0));
            q.put(b + 1, -1 + q.getOrDefault(b + 1, 0));
        }
        q = q.toSortedMap();
        var soma = 0
        var res = -1
        q.forEach { k, v ->
            soma += v
            if(soma == 1){
                res= k
            }
        }
        println(res)
    }
}