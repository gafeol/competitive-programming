// Restoring three numbers
// https://codeforces.com/contest/1298/problem/A

fun main() {
    var list = readLine()!!.split(' ').map{x -> x.toInt()}
    list = list.sorted()
    val A = list[3] - list[0]
    val B = list[3] - list[1]
    val C = list[3] - list[2]
    println("$A $B $C");
}
