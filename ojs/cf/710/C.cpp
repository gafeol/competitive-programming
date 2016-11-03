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
int s[MAXN], lin[MAXN];

stack<int> odd, eve;

int dist(int i, int j){
	return abs(i - (n+1)/2) + abs(j - (n+1)/2);
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n*n;a++){
		if(a&1)
			odd.push(a);
		else
			eve.push(a);
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
	//		debug("to em %d %d\n", a, b);
			if(dist(a, b) < (n+1)/2){
				printf("%d ", odd.top());
				odd.pop();
			}
			else{
				printf("%d ", eve.top());
				eve.pop();
			}
		}
		putchar('\n');
	}
}
