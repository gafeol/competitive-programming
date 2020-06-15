fun main () {
    val t = readLine()!!.toInt()
    for(i in 1..t){
        var x = readLine()!!.toInt()
        if(x < 1000){
            println(x)
        }
        else if((x+500)/1000 < 1000){
            println("${(x+500)/1000}K")
        }
        else{
            println("${(x+500000)/1000000}M")
        }
    }
}
