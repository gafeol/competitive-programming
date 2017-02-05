#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
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
#define ff fst
#define xx snd.fst
#define rr snd.snd

const int MAXN = 212345;

int n, m, k;

pip s[MAXN];

multiset<pii> q; 

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		int x, r, f;
		scanf("%d%d%d", &x, &r, &f);
		s[a].xx = x;
		s[a].ff = f;
		s[a].rr = r;
	}
	sort(s, s+n);
	q.insert(s[0].snd);
	int i = 0, l = 0, r = 0;
	while(i < n){
		while(r + 1 < n && s[r+1].ff - s[i].ff <= k){
			q.insert(s[r+1].snd);
			r++;
		}
		while(s[i].ff - s[l].ff <= kk){
			q.erase(s[l].snd);
			l++;
		}
		
	}
}
