import java.io.*
import java.util.*

fun main() {
    val t = readLine()!!.toInt()
    var st = Stack<Int>();
    var mx = Stack<Int>();
    mx.push(0);
    for(i in 1..t){
        var s :MutableList<Int> = mutableListOf(*readLine()!!.split(' ').map{x -> x.toInt()}.toTypedArray())
        if(s[0] == 1){
            st.push(s[1]);
            mx.push(Math.max(s[1], mx.peek()));
        }
        else if(s[0] == 2){
            st.pop();
            mx.pop();
        }
        else{
            println(mx.peek());
        }
    }
}

