import java.util.*;

fun main(args: Array<String>) {
    val st = Scanner(System.`in`)
    val t = st.nextInt()
    for(i in 1..t){
        var n = st.nextInt() 
        var x: Long = 0
        var y: Long = 0
        for(a in 1..4*n-1){
            var xx = st.nextLong()
            var yy = st.nextLong()
            x = x xor xx;
            y = y xor yy;
        }
        println("$x $y");
    }
}
