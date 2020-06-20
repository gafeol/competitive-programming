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


val MAXV = 100009;

// Complete the minimumDistances function below.
fun minimumDistances(a: Array<Int>): Int {
    val lst = Array<Int>(MAXV, {-MAXV});
    var res = MAXV;
    a.forEachIndexed{ i, x -> 
        res = Math.min(res, i - lst[x]);
        lst[x] = i;
    }
    res = if(res > a.size) -1 else res;
    return res;
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val n = scan.nextLine().trim().toInt()

    val a = scan.nextLine().split(" ").map{ it.trim().toInt() }.toTypedArray()

    val result = minimumDistances(a)

    println(result)
}

