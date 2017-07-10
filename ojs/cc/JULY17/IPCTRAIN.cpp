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

multiset<pii> q;

vector<pii> s[MAXN];

int main (){
	for_tests(t, tt){
		scanf(" %d %d", &m, &n);
		for(int a=0;a<m;a++){
			int d, t, c;
			scanf("%d %d %d", &d, &t, &c);
			s[d].pb(pii(-c, t));
		}
		for(int a=1;a<=n;a++){
			for(pii ev: s[a]){
				q.insert(ev);
			}
			s[a].clear();
			if(!q.empty()){
				pii top = *q.begin();
				q.erase(q.begin());
				top.snd--;
				if(top.snd != 0)
					q.insert(top);
			}
		}
		ll res = 0;
		while(!q.empty()){
			pii top = *q.begin();
			res += ((ll)-top.fst)*top.snd;
			q.erase(q.begin());
		}
		printf("%lld\n", res);
	}
}
