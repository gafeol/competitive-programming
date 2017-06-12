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
int s[MAXN];
int deg[MAXN];
int cor[MAXN], pai[MAXN];

int tot[2], cnt[2];

map<int, int> mrk[2];

queue<int> q;

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	for(int a=2;a<=n;a++){
		scanf("%d", &pai[a]);
		deg[pai[a]]++;
	}
	for(int a=1;a<=n;a++){
		if(deg[a] == 0){
			q.push(a);
			cor[a] = 0;
		}
	}
	while(!q.empty()){
		int u = q.front();
		tot[cor[u]] ^= s[u];
		cnt[cor[u]]++;
		mrk[cor[u]][s[u]]++;
		q.pop();
		deg[pai[u]]--;
		cor[pai[u]] = 1 - cor[u];
		if(deg[pai[u]] == 0)
			q.push(pai[u]);
	}

	ll res = 0;
	if(tot[0]){
		for(auto &r: mrk[0]){
			int key = r.fst;
			int val = r.snd;
			int proi = tot[0]^key;
			res += mrk[1][proi]*mrk[0][key];
		}
	}
	else{
		for(auto &r: mrk[0]){
			int key = r.fst;
			int val = r.snd;
			int proi = key;
			res += ((ll)cnt[1] - mrk[1][proi])*val;
		}
	}
	printf("%lld\n", res);
}
