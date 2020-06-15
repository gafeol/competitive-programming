fun main() {
    var (n, m, k) = readLine()!!.split(' ').map{it.toInt()}
    var s = mutableListOf(0);
    for(i in 1..n){
        s.add(m+1);
    }
    s[k] = 0;
    for(i in 0..m-1){
        var (i,j) = readLine()!!.split(' ').map{it.toInt()}
        var ni = s[j];var nj = s[i];
        s[i] = Math.min(s[i]+1, ni);
        s[j] = Math.min(s[j]+1, nj);
    }
    for(i in 1..n){
        if(s[i] > m){
            print("-1 ");
        }
        else{
            print("${s[i]} ");
        }
    }
    println();
}

