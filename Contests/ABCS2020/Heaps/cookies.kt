import java.io.*
import java.math.*
import java.util.*

var v: MutableList<Long> = mutableListOf();

fun heapify(){
    for(i in 0..v.size-1){
        var u = i;
        while(u > 0 && v[(u-1)/2] > v[u]){
            v[(u-1)/2] = v[u].also { v[u] = v[(u-1)/2] }
            u = (u-1)/2;
        }
    } 
}

fun pop(): Long {
    val x = v[0]; 
    v[0] = v.last().also { v[v.size - 1] = v[0]}
    v.removeAt(v.size-1);
    var i = 0;
    while(i < v.size){
        var o = i*2+1;
        if(o+1 < v.size && v[o+1] < v[o])
            o++;
        if(o >= v.size || v[o] >= v[i])
            break;
        v[i] = v[o].also{v[o] = v[i]}
        i = o;
    }
    //println(v)
    return x;
}

fun push(x: Long) {
    v.add(x);
    var i = v.size-1;
    while(i > 0 && v[(i-1)/2] > v[i]){
        v[(i-1)/2] = v[i].also{ v[i] = v[(i-1)/2]}
        i = (i-1)/2;
    }
}

fun cookies(k: Long, A: Array<Long>): Int {
    v = A.toMutableList();
    heapify();

    var ans = 0;
    while(v.size >= 2 && v[0] < k){
        var x  = pop();
        var y = pop();
        //println("x $x y $y push ${x + 2*y}");
        push(x + 2.toLong()*y);
        ans++
    }
    if(v[0] >= k)
        return ans;
    else
        return -1;
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val nk = scan.nextLine().split(" ")

    val k = nk[1].trim().toLong()

    val A = scan.nextLine().split(" ").map{ it.trim().toLong() }.toTypedArray()

    val result = cookies(k, A)

    println(result)
}

