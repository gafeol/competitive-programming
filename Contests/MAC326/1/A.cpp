#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

string str(int n){
	if(n == 0)
		return "zero";
	else if(n == 1)
		return "one";
	else if(n == 2)
		return "two";
	else if(n == 3)
		return "three";
	else if(n == 4)
		eturn "four";
	else if(n == 5)
		return "five";
	else if(n == 6)
		return "six";
	else if(n == 7)
		return "seven";
	else if(n == 8)
		return "eight";
	else if(n == 9)
		return "nine";
	else if(n == 10)
		return "ten";
	else if(n == 11)
		return  "eleven";
	else if(n == 12)
		return  "twelve";
	else if(n == 13)
		return "thirteen";
	else if(n == 14)
		return "fourteen";
	else if(n == 15)
		return "fifteen";
	else if(n == 16)
		return "sixteen";
	else if(n == 17)
		return "seventeen";
	else if(n== 18)
		return "eighteen";
	else if(n== 19)
		return "nineteen";
	else if(n == 20)
		return "twenty";
	else if(n == 30)
		return "thirty";
	else if(n == 40)
		return "forty";
	else if(n== 50)
		return "fifty";
	else if(n == 60)
		return "sixty";
	else if(n == 70)
		return "seventy";
	else if(n == 80)
		return "eighty";
	else if(n == 90)
		return "ninety";
	else if(n == 100)
		return "one-hundred";
	else return "-";
}

int main (){
	scanf("%d", &n);
	if(str(n)[0] != '-'){
		cout << str(n) << endl;
	}
	else{

		cout << str((n/10)*10);
		if(n%10 != 0)
			cout << "-" << str(n%10);
		cout<<endl;
	}
		
}

