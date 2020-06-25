import java.io.*
import java.util.*
    
var f:MutableMap<Long, Long> = mutableMapOf();

fun fat(n:Long):Long {
	if(n <= 1)
		return 1;
	if(f.contains(n))
		return f.getOrDefault(n, 0);
	f.put(n, n*fat(n-1));
	return f.getOrDefault(n, 0);
}
    
fun main(args: Array<String>) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. */
    var (n, m) = readLine()!!.split(' ').map{it.toLong()};
    println(fat(n+m-2)/(fat(n-1)*fat(m-1)));
}
