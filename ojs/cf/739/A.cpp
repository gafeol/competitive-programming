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
vector<pii> v;
pii s[MAXN];

int main (){
	int res = INT_MAX;
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		scanf("%d%d", &s[a].fst, &s[a].snd);
		res = min(res, s[a].snd - s[a].fst+1);
	}
	/*
	sort(s, s+m);
	for(int i=0;i<m;i++){
		if((i == 0 || s[i-1].fst != s[i].fst) && (i == m-1 || s[i].snd < s[i+1].snd)){
			debug("PUT %d %d\n", s[i].fst, s[i].snd);
			v.pb(s[i]);
		}
	}
	*/
	printf("%d\n", res);
	for(int a=0;a<n;a++){
		printf("%d ", a%res);
	}
}
