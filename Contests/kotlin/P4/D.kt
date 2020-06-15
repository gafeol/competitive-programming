fun main () {
    val t = readLine()!!.toInt()
    for (tt in 1..t){
        readLine()!!.toInt()
        val s = readLine()!!.split(' ').map{x -> x.toInt()}
        var i: Int = 0
        var j: Int = s.size-1
        var som: Int = 0
        var ans = mutableListOf(0, 0)
        var turn = 0
        var turns = 0
        while(i <= j){
            var atu : Int = 0
            while((i <= j) and (atu <= som)){
                var aux = if(turn == 0) s[i] else s[j];
                ans[turn] += aux;
                atu += aux;
                i += if(turn == 0) 1 else 0
                j -= if(turn == 1) 1 else 0
            }
            som = atu
            turn = turn xor 1
            turns++
        }
        println("$turns ${ans[0]} ${ans[1]}")
    }
}