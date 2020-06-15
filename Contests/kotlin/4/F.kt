var M:MutableList<MutableList<Long>> = mutableListOf();
var L:MutableList<Long> = mutableListOf();
var C:MutableList<Long> = mutableListOf();

fun goC():Long {
    var vai: MutableList<Long> = mutableListOf();
    var cnt:Long = 0;
    var soma:Long = 0;
    for(i in 0..C.size-1){
        vai.add(soma);
        cnt += C[i]; 
        soma += cnt;
    }
    var vem: MutableList<Long> = mutableListOf();
    cnt= 0;
    soma= 0;
    for(i in 0..C.size-1){
        vem.add(soma);
        cnt += C[C.size-1-i]; 
        soma += cnt;
    }
    var mn = vem[C.size-1]
    for(i in 0..C.size-1){
        var j = C.size-1-i
        var bef:Long = vai[i]
        var aft:Long = vem[j]
        mn = Math.min(mn, bef + aft);
    }
    return mn;
}

fun goL():Long {
    var vai: MutableList<Long> = mutableListOf();
    var cnt:Long = 0;
    var soma:Long = 0;
    for(i in 0..L.size-1){
        vai.add(soma);
        cnt += L[i]; 
        soma += cnt;
    }
    var vem: MutableList<Long> = mutableListOf();
    cnt= 0;
    soma= 0;
    for(i in 0..L.size-1){
        vem.add(soma);
        cnt += L[L.size-1-i]; 
        soma += cnt;
    }
    var mn = vem[L.size-1]
    for(i in 0..L.size-1){
        var j = L.size-1-i
        var bef:Long = vai[i]
        var aft:Long = vem[j]
        mn = Math.min(mn, bef + aft);
    }
    return mn;
}

fun main() {
    var (n, m, q) = readLine()!!.split(' ').map{it.toInt() }
    for(i in 0..n-1){
        var line:MutableList<Long> = mutableListOf(*readLine()!!.split(' ').map{it.toLong()}.toTypedArray())
        M.add(line);
    }
    for(i in 0..n-1){
        var som:Long = 0
        for(j in 0..m-1){
            som += M[i][j];
        }
        L.add(som);
    }
    for(j in 0..m-1){
        var som:Long = 0
        for(i in 0..n-1){
            som += M[i][j];
        }
        C.add(som);
    }
    print(goL() + goC());
    print(" ");
    for(a in 0..q-1){
        var (l, c, v) = readLine()!!.split(' ').map{it.toLong()}
        var i = l.toInt();
        var j = c.toInt();
        i--;
        j--;
        L[i] -= M[i][j];
        C[j] -= M[i][j];
        M[i][j] = v; 
        L[i] += M[i][j];
        C[j] += M[i][j];
        print(goL() + goC());
        print(" ");
    }
    println();
}

