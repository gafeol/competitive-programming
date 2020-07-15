import java.io.*
import java.math.*
import java.text.*
import java.util.*
import java.util.regex.*

/*
 * Complete the swapNodes function below.
 */

var ar: Array<Array<Int>> = arrayOf();

fun inv(u: Int, h: Int, k: Int): Unit {
    if(u == -1)
        return ;
    if(h%k == 0){
        ar[u-1][0] = ar[u-1][1].also { ar[u-1][1] = ar[u-1][0] };
    }
    inv(ar[u-1][0], h+1, k);
    inv(ar[u-1][1], h+1, k);
}

var arr: Array<Int> = arrayOf();
var arrSz = 0;

fun add(x: Int){
    arr[arrSz] = x;
    arrSz++;
}

fun inorder(u: Int): Unit {
    if(u == -1) return ;
    inorder(ar[u-1][0]);
    add(u);
    inorder(ar[u-1][1]);
}

fun swapNodes(indexes: Array<Array<Int>>, queries: Array<Int>): Array<Array<Int>> {
     ar = indexes;
     var ans = Array<Array<Int>>(queries.size, { Array<Int>(indexes.size, { 0 }) });
     for(i in 0..queries.size-1){
         inv(1,1, queries[i]);
         arr = Array<Int>(indexes.size) { 0 }
         arrSz = 0;
         inorder(1);
         ans[i] = arr;
     }
     return ans;
 }

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val n = scan.nextLine().trim().toInt()

    val indexes = Array<Array<Int>>(n, { Array<Int>(2, { 0 }) })

    for (indexesRowItr in 0 until n) {
        indexes[indexesRowItr] = scan.nextLine().split(" ").map{ it.trim().toInt() }.toTypedArray()
    }

    val queriesCount = scan.nextLine().trim().toInt()

    val queries = Array<Int>(queriesCount, { 0 })
    for (queriesItr in 0 until queriesCount) {
        val queriesItem = scan.nextLine().trim().toInt()
        queries[queriesItr] = queriesItem
    }

    val result = swapNodes(indexes, queries)

    println(result.map{ it.joinToString(" ") }.joinToString("\n"))
}

