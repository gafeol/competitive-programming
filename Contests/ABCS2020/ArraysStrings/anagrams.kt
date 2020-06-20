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

// Complete the makingAnagrams function below.
fun makingAnagrams(s1: String, s2: String): Int {
    var charCount: MutableMap<Char, Int> = mutableMapOf();
    for(c in s1)
        charCount.set(c, charCount.getOrDefault(c, 0) + 1);
    for(c in s2)
        charCount.set(c, charCount.getOrDefault(c, 0) - 1);

    var res = 0;
    for(c in s1){
       res += Math.abs(charCount.getOrDefault(c, 0)); 
       charCount.remove(c);
    }
    for(c in s2){
       res += Math.abs(charCount.getOrDefault(c, 0)); 
       charCount.remove(c);
    }

    return res;
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val s1 = scan.nextLine()

    val s2 = scan.nextLine()

    val result = makingAnagrams(s1, s2)

    println(result)
}

