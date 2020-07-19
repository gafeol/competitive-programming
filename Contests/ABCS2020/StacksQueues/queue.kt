import java.io.*
import java.util.*

fun main() {
    val t = readLine()!!.toInt()

    var s1 = Stack<Int>();
    var s2 = Stack<Int>();
    for(i in 1..t){
        var s :MutableList<Int> = mutableListOf(*readLine()!!.split(' ').map{x -> x.toInt()}.toTypedArray())
        if(s[0] == 1){
            s1.push(s[1]);
        }
        else if(s[0] == 2){
            if(s2.empty())
                while(!s1.empty())
                    s2.push(s1.pop());
            s2.pop();
        }
        else{
            if(s2.empty())
                while(!s1.empty())
                    s2.push(s1.pop());
            println(s2.peek());
        }
    }
}

