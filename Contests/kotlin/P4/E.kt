val p4 = arrayOf(2, 4, 1, 3)

fun main() {
    val t = readLine()!!.toInt()
    for(i in 1..t){
        var n = readLine()!!.toInt()
        if(n < 4){
            println("-1")            
            continue;
        }
        var cnt = 0
        if((n-5)%4 == 0){
            print("2 4 1 5 3");
            cnt = 5
        }
        if((n-6)%4 == 0){
            print("1 4 2 6 3 5")
            cnt = 6
        }
        if((n-7)%4 == 0){
            print("5 1 3 6 2 4 7")
            cnt = 7
        }
        while(cnt < n){
            for(i in 0..3){
                print(" ${p4[i]+cnt}")
            }
            cnt += 4
        }
        println()
    }
}
