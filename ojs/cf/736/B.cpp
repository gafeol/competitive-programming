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
int mrk[MAXN];

vector<int> p;

int ehp(int nn){
	int eh = 1;
	for(int pri:p){
		if(pri >= nn) continue; 
		eh = min(eh, nn%pri);
	}
	return eh;
}

int go(int nn){
	int eh = ehp(nn);	
	if(eh) return 1;
	else if(nn&1 && ehp(nn-2)) nn++;
	return 2 + (nn&1);
}

int main (){
	for(int a=2;a<MAXN-2;a++){
		if(!mrk[a])
			p.pb(a);
		for(ll b=a;b*a<MAXN-2;b++){
			mrk[b*a] = 1;
		}
	}
	scanf("%d", &n);
	printf("%d\n", go(n));
}
