// File Name
// https://codeforces.com/problemset/problem/978/B
fun main(){
    val n = readLine()!!.toInt()
    var str : String = readLine()!!
    var res = 0;
    str.forEachIndexed{ i, c ->
        if(i >= 2){
            if(str[i-1] == str[i-2] && c == str[i-1] && c == 'x')
                res++
        }
    }
    println(res);
}