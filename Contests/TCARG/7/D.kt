import java.io.*
import java.util.*
import java.math.BigInteger;

fun getSum(x: BigInteger): BigInteger {
    var ans = 0.toBigInteger();
    for(c in x.toString()){
        ans = ans.plus((c - '0').toBigInteger());
    }
    return ans;
}


fun main() {
    var (n, m) = readLine()!!.split(' ').map{it.toInt() }
    var ans = getSum(n.toBigInteger().pow(m));
    while(ans >= 10.toBigInteger()){
        ans = getSum(ans);
    }
    println(ans);
}

