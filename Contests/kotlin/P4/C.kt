fun main() {
    val n = readLine()!!.toInt()
    for(i in 1..n){
        val s = readLine()!!
        var ans = mutableListOf<Pair<Char, Int>>()
        s.forEachIndexed{ i, c ->
            if(c != '0'){
                ans.add(Pair<Char, Int>(c, s.length - i -1))
            }
        }
        println(ans.size)
        ans.forEach{ (c, nz) ->
            print(c)
            var cnt = 0
            while(cnt++ < nz)
                print(0)
            print(' ')
        }
        println()
    }
}