var np:Int = 0; 
var n:Int = 0; 
var p :MutableList<Int> = mutableListOf()
var pex: MutableMap<Int, Boolean> = mutableMapOf<Int, Boolean>()
var testou: MutableMap<Int, Boolean> = mutableMapOf<Int, Boolean>()
var s :MutableList<Int> = mutableListOf()

fun gcd(a:Int, b:Int) : Int {
    if(a == 0){
        return b;
    }
    return gcd(b%a, a);
}

fun test(i:Int, pp:Int):Boolean {
    var s1 = s[i];
    var p1 = pp;
    var pri = -1;
    var gc = 0;
    for(a in 0..n-1){
        if((s[a] - s1)%p1 != 0){
            if(pri != -1){
                gc = gcd(gc, s[a] - s[pri]);
            }
            else{
                pri = a;
            }
        }
    }

    if(pri == -1){
        pri = 0;
    }
    if(gc == 0){
        println("YES");
        println("$s1 $p1");
        println("${s[pri]} ${p[0]}");
        return true;
    }
    
    var s2 = s[pri];
    var p2 = 0;
    for(a in 0..np-1){
        var per = p[a];
        if(gc%per == 0){
            p2 = per;      
            println("YES");
            println("$s1 $p1");
            println("$s2 $p2");
            return true;
        }
    }
    return false;
}

fun go(i:Int, j:Int):Boolean {
    val dif = s[j] - s[i];
    for(a in 0..np-1){
        var per = p[a];
        if(dif%per == 0){
            if(testou.containsKey(per) == false){ // checar se e log
                if(test(i, per)){
                    return true;
                }
                testou.put(per, true);
            }
        }
    }
    return false;
}

fun main() {
    var (npp, nn) = readLine()!!.split(' ').map{it.toInt() }
    np = npp;
    n = nn;
    var pp :MutableList<Int> = mutableListOf(*readLine()!!.split(' ').map{x -> x.toInt()}.toTypedArray())
    p = pp;
    p.forEach{x -> pex.put(x, true)}
    var ss :MutableList<Int> = mutableListOf(*readLine()!!.split(' ').map{x -> x.toInt()}.toTypedArray())
    s = ss;

    if(n < 3){
        println("YES"); 
        println("${s[0]} ${p[0]}")
        println("${s[1]} ${p[0]}")
        return ;
    }
    
    if(go(0, 1)){
        return;
    }
    if(go(0, 2)){
        return ;
    }
    if(go(1, 2)){
        return ;
    }
    println("NO");
}

