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
ll s[MAXN], v[MAXN], ss[MAXN], e;

int res;

void test(ll x){
	x = min(x,  2000000000ll);
	x = max(x, -2000000000ll);
	for(int a=0;a<n;a++){
		ss[a] = s[a];
		s[a] += x;
	}

//	debug("testa x %lld\n", x);
	int i =0, j =0;
	int ans = 0;
	while(i < n){
		while(j < m && s[i] > v[j] + e)
			j++;
		if(j < m && s[i] >= v[j] - e && s[i] <= v[j]+e){
			j++;
			ans++;
		}
		i++;
	}
//	debug("dando %d\n", ans);
	res = max(res, ans);
	for(int a=0;a<n;a++)
		s[a] = ss[a];
}

int main (){
	for_tests(t, tt){
		scanf("%d %d %lld", &n, &m, &e);
		for(int a=0;a<n;a++){
			scanf("%lld", &s[a]);	
		}
		for(int a=0;a<m;a++){
			scanf("%lld", &v[a]);
		}
		sort(s, s+n);
		sort(v, v+m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				test(v[j] - e - s[i]);
				test(v[j] + e - s[i]);
			}
		}
		printf("%d\n", res);
		res = 0;
	}
}
