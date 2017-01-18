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
int s[MAXN], f[MAXN];

map<int, int> mrk;
int res;

map<int, int> ja;

void factor(int x){
	ja.clear();
	while(x != 1){
		if(ja.find(x/f[x]) == ja.end())
			mrk[x/f[x]]++;
		ja[x/f[x]] = 1;
		res = max(res, mrk[x/f[x]]);
		x = f[x];
	}
}

int main (){
	f[0] = f[1] = 1;
	res = 1;
	for(ll i=2;i<MAXN;i++){
		if(f[i] != 0) continue;
		f[i] = 1;
		for(ll d=i;i*d < MAXN;d++){
			f[i*d] = i;
		}
	}
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		factor(s[a]);
	}
	printf("%d\n", res);
}
