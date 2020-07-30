import java.util.*;
import java.io.*;
import java.math.*;

var mnHeap: MutableList<Long> = mutableListOf();
var mxHeap: MutableList<Long> = mutableListOf();

fun mxHeapify(){
    for(i in 0..mxHeap.size-1){
        var u = i;
        while(u > 0 && mxHeap[(u-1)/2] <= mxHeap[u]){
            mxHeap[(u-1)/2] = mxHeap[u].also { mxHeap[u] = mxHeap[(u-1)/2] }
            u = (u-1)/2;
        }
    } 
}

fun mnHeapify(){
    for(i in 0..mnHeap.size-1){
        var u = i;
        while(u > 0 && mnHeap[(u-1)/2] > mnHeap[u]){
            mnHeap[(u-1)/2] = mnHeap[u].also { mnHeap[u] = mnHeap[(u-1)/2] }
            u = (u-1)/2;
        }
    } 
}

fun mxPop(): Long {
    val x = mxHeap[0]; 
    mxHeap[0] = mxHeap.last().also { mxHeap[mxHeap.size - 1] = mxHeap[0]}
    mxHeap.removeAt(mxHeap.size-1);
    var i = 0;
    while(i < mxHeap.size){
        var o = i*2+1;
        if(o+1 < mxHeap.size && mxHeap[o+1] > mxHeap[o])
            o++;
        if(o >= mxHeap.size || mxHeap[o] <= mxHeap[i])
            break;
        mxHeap[i] = mxHeap[o].also{mxHeap[o] = mxHeap[i]}
        i = o;
    }
    return x;
}

fun mnPop(): Long {
    val x = mnHeap[0]; 
    mnHeap[0] = mnHeap.last().also { mnHeap[mnHeap.size - 1] = mnHeap[0]}
    mnHeap.removeAt(mnHeap.size-1);
    var i = 0;
    while(i < mnHeap.size){
        var o = i*2+1;
        if(o+1 < mnHeap.size && mnHeap[o+1] < mnHeap[o])
            o++;
        if(o >= mnHeap.size || mnHeap[o] >= mnHeap[i])
            break;
        mnHeap[i] = mnHeap[o].also{mnHeap[o] = mnHeap[i]}
        i = o;
    }
    //println(v)
    return x;
}

fun mxPush(x: Long) {
    mxHeap.add(x);
    var i = mxHeap.size-1;
    while(i > 0 && mxHeap[(i-1)/2] < mxHeap[i]){
        mxHeap[(i-1)/2] = mxHeap[i].also{ mxHeap[i] = mxHeap[(i-1)/2]}
        i = (i-1)/2;
    }
}

fun mnPush(x: Long) {
    mnHeap.add(x);
    var i = mnHeap.size-1;
    while(i > 0 && mnHeap[(i-1)/2] > mnHeap[i]){
        mnHeap[(i-1)/2] = mnHeap[i].also{ mnHeap[i] = mnHeap[(i-1)/2]}
        i = (i-1)/2;
    }
}

fun runningMedian(a: Array<Int>): Array<Double> {
    var l = MutableList<Double>(0, { 0.toDouble() });
    for(x in a){
        mxPush(x.toLong());
        if(mxHeap.size >= mnHeap.size+2){
            val x = mxPop(); 
            mnPush(x);
        }
        //println(mxHeap);
        //println(mnHeap);
        if(mnHeap.size > 0 && mxHeap[0] > mnHeap[0]){
            val x = mxPop()
            val y = mnPop()
            mxPush(y);
            mnPush(x);
        }
        if(mxHeap.size > mnHeap.size){
            l.add(mxHeap[0].toDouble());
        }
        else{
            var ans = 0.toDouble()
            ans = (mxHeap[0] + mnHeap[0]).toDouble()
            ans = ans/2;
            l.add(ans);
        }
    }
    return l.toTypedArray();
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val aCount = scan.nextLine().trim().toInt()

    val a = Array<Int>(aCount, { 0 })
    for (aItr in 0 until aCount) {
        val aItem = scan.nextLine().trim().toInt()
        a[aItr] = aItem
    }

    val result = runningMedian(a)

    println(result.joinToString("\n"))
}

