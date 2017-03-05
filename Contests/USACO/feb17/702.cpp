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
pii s[MAXN];

multiset <int> chi;

bool cmp(pii a, pii b){
	return (a.snd < b.snd || (a.snd == b.snd && a.fst < b.fst));
}

int main (){
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);
	scanf("%d%d", &n, &m);
	chi.insert(INT_MAX);
	for(int a=0;a<n;a++){
		int x;
		scanf("%d", &x);	
		chi.insert(x);
	}
	for(int a=0;a<m;a++){
		scanf("%d %d", &s[a].fst, &s[a].snd);
	}
	sort(s, s+m, cmp);
	int res = 0;
	for(int a=0;a<m;a++){
		if(*chi.lower_bound(s[a].fst) <= s[a].snd){
			chi.erase(chi.lower_bound(s[a].fst));
			res++;
		}
	}
	printf("%d\n", res);
}