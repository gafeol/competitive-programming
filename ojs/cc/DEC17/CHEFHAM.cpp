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

const int MAXN = 112345;

int n, m, k;
int s[MAXN];
int res[MAXN];
set<pii> p;
multiset<int> v;

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d", &s[a]);
			v.insert(s[a]);
			p.insert(pii(s[a], a));
		}
		int ans = 0;
		while(!v.empty()){
			int val = *v.begin();
			v.erase(v.begin());
			pii pos;
			if(p.lower_bound(pii(val+1, -1)) != p.end())
				pos = *p.lower_bound(pii(val+1, -1));
			else
				pos = *p.begin();
			p.erase(pos);	
			res[pos.snd] = val;
			ans += (s[pos.snd] != val);
		}
		printf("%d\n", ans);
		for(int a=0;a<n;a++){
			printf("%d ", res[a]);
		}
		puts("");
	}
}
