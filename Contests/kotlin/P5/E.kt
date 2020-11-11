fun main() {
    val t = readLine()!!.toInt()
    for(tt in 1..t){
        var (n, k) = readLine()!!.split(' ').map{it.toLong()} 
        val line = readLine()!!
        var oneCount = 0.toLong()
        var res = StringBuilder()
        for(c in line){
           if(c == '0'){
               if(oneCount > k){
                   var rp = oneCount - k
                   res.append("1".repeat(rp.toInt()))
                   oneCount = k
               }
               res.append(c)
               k -= oneCount
           }
           else{
               oneCount++
           }
        }
        res.append("1".repeat(oneCount.toInt()))
        println(res)
    }
}

