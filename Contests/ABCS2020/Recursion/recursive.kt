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

fun digitSum(x: Long): Long = if(x == 0.toLong()) 0 else (x%10) + digitSum(x/10);
fun go(x: Long): Long = if(x < 10) x else go(digitSum(x));
// Complete the superDigit function below.
fun superDigit(n: String, k: Long): Long {
    var soma = n.sumBy{ it.toInt() - '0'.toInt() };
    return go(k*soma);
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)
    val nk = scan.nextLine().split(" ")
    val n = nk[0]
    val k = nk[1].trim().toInt()
    val result = superDigit(n, k.toLong())
    println(result)
}

