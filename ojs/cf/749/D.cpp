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

int add[MAXN];

vector<int> p[MAXN];

set<pii> q;

pii big(int x){
	return s[p[x][p[x].size()-1]];
}

void rmv(){
	for(int a=0;a<k;a++){
		if(p[add[a]].empty()) continue;
		q.erase(big(add[a]));
	}
}

void adi(){
	for(int a=0;a<k;a++){
		if(p[add[a]].empty()) continue;
		q.insert(big(add[a]));
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d %d", &s[a].snd, &s[a].fst);
		s[a].fst = -s[a].fst;
		p[s[a].snd].pb(a);
	}
	for(int a=1;a<=n;a++){
		if(p[a].empty()) continue;
		q.insert(s[p[a][p[a].size()-1]]);
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		scanf("%d", &k);
		for(int b=0;b<k;b++){
			scanf("%d", &add[b]);
		}
		rmv();
		if(q.size() == 0)
			puts("0 0");
		else if(q.size() == 1){
			int u = q.begin()->snd;
			printf("%d %d\n", u, -s[p[u][0]].fst);
		}
		else{
			pii b = *(q.begin());
			int u = q.begin()->snd;
			q.erase(b);
			int v = q.begin()->snd;
			int i = upper_bound(p[u].begin(), p[u].end(), p[v][p[v].size()-1]) - p[u].begin();
			printf("%d %d\n", u, -s[p[u][i]].fst);
			q.insert(b);
		}
		adi();
	}
}
