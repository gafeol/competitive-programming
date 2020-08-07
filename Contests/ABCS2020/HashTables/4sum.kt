import java.io.*
import java.util.*
import java.math.*;

fun main() {
    var s: Array<MutableList<BigInteger>> = Array<MutableList<BigInteger>>(4, { mutableListOf() });
    for(i in 0..3){
        s[i] = mutableListOf(*readLine()!!.split(' ').map{x -> x.toBigInteger()}.toTypedArray())
    }

    var cnt: MutableMap<BigInteger, BigInteger> = mutableMapOf();
    cnt.clear();
    for(x in s[0]){
        for(y in s[1]){
            var c = cnt.getOrElse(x.plus(y), { 0.toBigInteger() });
            cnt.put(x.plus(y), c.plus(1.toBigInteger()));
        }
    }
    
    var ans: BigInteger = 0.toBigInteger();
    for(x in s[2]){
        for(y in s[3]){
            ans += cnt.getOrElse(0.toBigInteger().minus(x).minus(y), {0.toBigInteger()}); 
        }
    }
    println(ans);
}

