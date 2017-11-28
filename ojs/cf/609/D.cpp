#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k, d;
ll s[2][MAXN];

ll mn[2][MAXN];

vector<pii> q[2];
vector<pii> ans;

int go(int t){
	ans.clear();
	int S = d, cnt = 0;
	int i = 0, j = 0;
	while(cnt < k && S >= 0){
		if(i < q[0].size() && (j == q[1].size() || (q[0][i].fst)*mn[0][t] < (q[1][j].fst)*mn[1][t])){
			S -= (q[0][i].fst)*mn[0][t];
			ans.pb(pii(0, q[0][i].snd));
			cnt++;
			i++;
		}
		else{
			S -= (q[1][j].fst)*mn[1][t];
			ans.pb(pii(1, q[1][j].snd));
			cnt++;
			j++;
		}
	}
	return (S >= 0 && cnt == k);
}

int ib[2][MAXN];

main (){
	scanf("%lld%lld%lld%lld", &n, &m, &k, &d);
	for(int t=0;t<2;t++){
		for(int a=0;a<n;a++){
			scanf("%lld", &s[t][a]);
			mn[t][a] = s[t][a];
			ib[t][a] = a;

			if(a != 0 && mn[t][a-1] < mn[t][a]){
				mn[t][a] = mn[t][a-1];
				ib[t][a] = ib[t][a-1];
			}
		}
	}
	int deg[3];
	deg[0] = deg[1] = 0;
	for(int a=0;a<m;a++){
		int t, c;
		scanf("%lld %lld", &t, &c);
		t--;
		q[t].pb(pii(c, a));
	}
	for(int a=0;a<2;a++){
		sort(q[a].begin(), q[a].end());
	}
	int i = 0, j = n-1;
	while(i < j){
		int m = (i + j)/2;
		if(go(m))
			j = m;
		else
			i = m + 1;
	}
	if(go(i)){
		printf("%lld\n", i+1);
		for(pii p: ans){
			printf("%lld %lld\n", p.snd + 1, ib[p.fst][i]+1);
		}
	}
	else
		puts("-1");
}

