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

int n, m;
ll k;
int nxt[MAXN];
ll w[MAXN];
int mrk[MAXN];
vector<int> head;
ll dc[MAXN];
int c[MAXN];

vector<int> pil;

void cyc(){
	c[*pil.rbegin()] = head.size();
	head.pb(*pil.rbegin());
	while(
}

void dfs(int v, int t){
	if(mrk[v]){
		if(mrk[v] != t){
			pil.pop_back();
			return;
		}
		else{
			cyc();
		}
	}
	mrk[v] = 1;
	

}


int main (){
	scanf("%d%lld", &n, &k);
	for(int a=1;a<=n;a++){
		scanf("%d", &nxt[a]);
		deg[nxt[a]]++;
	}
	for(int a=1;a<=n;a++){
		scanf("%lld", &w[a]);
	}
	for(int a=1;a<=n;a++){
		if(mrk[a] == 0){
			pil.pb(a);
			dfs(a, a);
		}
	}
}
