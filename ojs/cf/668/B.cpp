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

const int MAXN = 1123456;

int n, m, k;
int res[MAXN];

int c(int x){
	if(x < 0)
		x = x + n;
	return x%n;
}

int main (){
	scanf("%d%d", &n, &k);
	int u, v;
	u = 0;
	v = 1;
	for(int a=0;a<k;a++){
		int t;
		scanf("%d", &t);	
		if(t == 1){
			int x;
			scanf("%d", &x);
			u = c(u + x);
			v = c(v + x);
		}
		else{
			u ^= 1;
			v ^= 1;
		}
	}
	res[u] = 1;
	res[v] = 2;
	int cnt = 1;
	while(res[(u+2)%n] == 0){
		u = c(u+2);
		res[u] = cnt*2+1;
		cnt++;
	}
	cnt = 2;
	while(res[(v+2)%n] == 0){
		v = c(v+2);
		res[v] = cnt*2;
		cnt++;
	}
	for(int a=0;a<n;a++){
		printf("%d ", res[a]);
	}
}
