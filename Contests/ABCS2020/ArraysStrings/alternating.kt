import java.io.*
import java.math.*
import java.security.*
import java.text.*
import java.util.*
import java.util.concurrent.*
import java.util.function.*
import java.util.regex.*
import java.util.stream.*
import kotlin.collections.*
import kotlin.comparisons.*
import kotlin.io.*
import kotlin.jvm.*
import kotlin.jvm.functions.*
import kotlin.jvm.internal.*
import kotlin.ranges.*
import kotlin.sequences.*
import kotlin.text.*

// Complete the alternatingCharacters function below.
fun alternatingCharacters(s: String): Int {
    var costAB = 0;
    var costBA = 0;

    val ch = arrayOf('A', 'B');
    var t = 0;
    for(c in s){
        if(c == ch[t])
            t = t xor 1;
        else
            costAB++;
    }

    t = 1;
    for(c in s){
        if(c == ch[t])
            t = t xor 1;
        else
            costBA++;
    }

    return Math.min(costAB, costBA);
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val q = scan.nextLine().trim().toInt()

    for (qItr in 1..q) {
        val s = scan.nextLine()

        val result = alternatingCharacters(s)

        println(result)
    }
}

