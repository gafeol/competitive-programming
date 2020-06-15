fun main () {
    var t = readLine()!!.toInt();
    while(t-- > 0) {
        var n = readLine()!!.toInt();
        var s = readLine()!!.split(' ').map{x->x.toInt()}
        var mnpos = 10001
        var mxneg = -10001
        var sum = 0
        var take:MutableList<Int> = mutableListOf();
        for(i in 0..n-1){
            if(s[i] > 0){
                mnpos = Math.min(mnpos, s[i]);
                sum += s[i];
                take.add(1);
            }
            else if(s[i] < 0){
                mxneg = Math.max(mxneg, s[i]);
                take.add(0);
            }
            else {
                take.add(0);
            }
        }
        if(mnpos < -mxneg){
            sum -= mnpos;
            mxneg = 10001;
        }
        else{
            sum += mxneg;
            mnpos = 10001;
        }
        for(i in 0..n-1){
            if(s[i] == mxneg){
                take[i] = 1
                mxneg = 10001;
            }
            if(s[i] == mnpos){
                take[i] = 0
                mnpos = 10001;
            }
        }

        println(sum);
        for(i in 0..n-1){
            print(take[i]);
        }
        println();
    }
}
