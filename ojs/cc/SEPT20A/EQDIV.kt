import java.io.*
import java.util.*
import java.math.*

fun expo(base: BigInteger, e: Int): BigInteger{
    if(e == 0)
        return BigInteger.ONE; 
    var ans = expo(base, e/2);
    ans = ans.multiply(ans);
    if(e%2 == 1)
        ans = ans.multiply(base);
    return ans;
}

fun main(args:Array<String>) {
    val input = Scanner(System.`in`)
    val k = input.nextInt();
    val t = input.nextInt();
    for(tt in 1..t){
        var n = input.nextInt();
        var sum = BigInteger.ZERO;
        var s: MutableList<BigInteger> = mutableListOf(BigInteger.ZERO);
        var ans: MutableList<Int> = mutableListOf(0);
        for(i in 1..n){
            s.add(expo(BigInteger("" + i), k));
            ans.add(0);
            sum = sum.add(s[i]);
        }
        var orisum = sum;
        var mnDif = sum;
        var o = BigInteger.ZERO;
        var dif: MutableList<BigInteger> = ArrayList(n+1);
        for(i in 0..n)
            dif.add(BigInteger.ZERO)
        for(i in n downTo 1){
            var summ = sum.minus(s[i])
            var oo = o.plus(s[i])
            //println("Poss valor pra mnDif eh " + summ.toString() + " - " + oo.toString() + " .abs() = " + summ.minus(oo).abs().toString())
            dif[i] = summ.minus(oo).abs();
            if(mnDif < dif[i]){
                mnDif = dif[i];
            }
            if(oo < summ){
                o = oo
                sum = summ
            }
        }
        mnDif = mnDif.min(sum.minus(o).abs())

        sum = orisum;
        o = BigInteger.ZERO;
        if(!mnDif.equals(sum)){
            for(i in n downTo 1){
                var summ = sum.minus(s[i])
                var oo = o.plus(s[i])
                if(mnDif.equals(dif[i])){
                    ans[i] = 1;
                    break;
                }
                if(oo < summ){
                    o = oo
                    sum = summ
                    ans[i] = 1;
                }
            }
        }
        println(mnDif)
        for(i in 1..n)
            print(ans[i])
        println()
    }
}

