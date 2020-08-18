import java.io.*
import java.math.*
import java.security.*
import java.text.*
import java.util.*
import java.util.concurrent.*
import java.util.function.*
import java.util.regex.*
import java.util.stream.*
import kotlin.collections.*
import kotlin.comparisons.*
import kotlin.io.*
import kotlin.jvm.*
import kotlin.jvm.functions.*
import kotlin.jvm.internal.*
import kotlin.ranges.*
import kotlin.sequences.*
import kotlin.text.*

// Complete the bfs function below.
fun bfs(n: Int, m: Int, edges: Array<Array<Int>>, s: Int): Array<Int> {
    var q: Queue<Int> = LinkedList<Int>();
    var ans = Array<Int>(n+1, { -1 });
    var adj = Array<Vector<Int>>(n+1, { Vector<Int>() }); 
    for(p in edges){
        adj[p[0]].add(p[1]);
        adj[p[1]].add(p[0]);
    }
    q.add(s);
    ans[s] = 0;
    while(!q.isEmpty()){
        var u = q.remove();
        for(nxt in adj[u]){
            if(ans[nxt] == -1){
                ans[nxt] = ans[u] + 6;
                q.add(nxt);
            }
        }
    }

    var res = Array<Int>(n-1, {i -> ans[i + 1 + if(i+1 >= s) 1 else 0] });
    return res;
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)
    val q = scan.nextLine().trim().toInt()
    for (qItr in 1..q) {
        val nm = scan.nextLine().split(" ")
        val n = nm[0].trim().toInt()
        val m = nm[1].trim().toInt()
        val edges = Array<Array<Int>>(m, { Array<Int>(2, { 0 }) })
        for (i in 0 until m) {
            edges[i] = scan.nextLine().split(" ").map{ it.trim().toInt() }.toTypedArray()
        }
        val s = scan.nextLine().trim().toInt()
        val result = bfs(n, m, edges, s)
        println(result.joinToString(" "))
    }
}
