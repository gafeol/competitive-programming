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
ll s[MAXN], v[MAXN], ind[MAXN];

bool cmp(int a, int b){
	return s[a] < s[b];
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%lld", &c[a]);
	}
	for(int a=0;a<m;a++){
		ind[a] = a;
		scanf("%lld", &s[a]);
	}
	sort(ind, ind+m, cmp);
	sort(s, s+m);
	sort(c, c+n);
	for(int a=0;a<n;a++){
		 
	}

}
