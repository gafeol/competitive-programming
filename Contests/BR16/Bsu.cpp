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
int s[MAXN], B, A;
int mrk[MAXN];

vector<int> adj[MAXN];

set<int> no[MAXN];

int main (){
	scanf("%d%d %d %d", &n, &m, &A, &B);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		i--;j--;
		s[i]++;
		s[j]++;
		adj[i].pb(j);
		adj[j].pb(i);
	}
	queue<int> q;
	int tot = n;
	for(int a=0;a<n;a++){
		no[s[a]].insert(a);
		if(s[a] < A || tot-s[a]-1 < B){
			q.push(a);
			no[s[a]].erase(a);
			mrk[a] = 1;
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int nxt: adj[u]){
			no[s[nxt]].erase(nxt);
			s[nxt]--;
			no[s[nxt]].insert(nxt);
			if(mrk[nxt]) continue;
			if(s[nxt] < A){
				q.push(nxt);
				no[s[nxt]].erase(nxt);
				mrk[nxt] = 1;
			}
		}
		if(tot-B-1 >= 0){
			for(auto &v: no[tot-B-1]){
				if(mrk[v]) continue;
				mrk[v] = 1;
				q.push(v);
			}
		}
		tot--;
	}
	printf("%d\n", tot);
}
