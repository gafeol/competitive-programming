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


var mem: MutableMap<Pair<Int, Int>, Int> = mutableMapOf();

fun expo(base: Int, e: Int): Int{
    if(e == 0) return 1;
    var ans = expo(base, e/2);
    ans *= ans;
    if((e and 1) == 1)
        ans *= base;
    return ans;
}

// Complete the powerSum function below.
fun powerSum(X: Int, N: Int, lst:Int = 1): Int {
    if(X == 0) return 1;
    if(mem.contains(Pair(X, lst)))
        return mem.get(Pair(X,lst))!!;
    var i = lst;
    var ans = 0;
    var e = expo(i, N);
    while(e <= X){
        ans += powerSum(X-e, N, i+1);
        i++;
        e = expo(i, N);
    }
    mem.put(Pair(X, lst), ans);
    return ans;
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)
    val X = scan.nextLine().trim().toInt()
    val N = scan.nextLine().trim().toInt()
    val result = powerSum(X, N)
    println(result)
}

