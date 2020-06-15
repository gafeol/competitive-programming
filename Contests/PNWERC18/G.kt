import kotlin.math.round
import kotlin.math.sqrt
fun sq(x: Int): Int{
    return x*x;
}

fun dist(x:Int, y:Int, xx:Int, yy:Int): Int = (sq(x - xx) + sq(y - yy));

fun min(x:Int, y:Int):Int = if(x < y) x else y;

fun main() {
    var l = readLine()!!.split(' ').map{x -> x.toInt()}
    var x = l[0];var y = l[1];
    var x1 = l[2];var y1 = l[3];
    var x2 = l[4];var y2 = l[5];

    if(x1 > x2){
        var aux = x2;
        x2 = x1;
        x1 = aux;
    }

    if(y1 > y2){
        var aux = y2;
        y2 = y1;
        y1 = aux;
    }

    var ans = dist(x, y, x1, y1)
    ans = min(ans, dist(x, y, x2, y2))
    ans = min(ans, dist(x, y, x1, y2))
    ans = min(ans, dist(x, y, x2, y1))

    if(x >= x1 && x <= x2){
        ans = min(ans, dist(x, y, x, y1));
        ans = min(ans, dist(x, y, x, y2));
    }
    if(y >= y1 && y <= y2){
        ans = min(ans, dist(x, y, x1, y));
        ans = min(ans, dist(x, y, x2, y));
    }
    
    var res: Double = sqrt(ans.toDouble());
    println("%.3f".format(res))
}
