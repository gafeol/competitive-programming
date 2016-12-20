#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
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

const int MAXN = 212345, BITMASK = (1<<17) + 10;
const ll INF = LLONG_MAX;

int n, m, k;
int s[MAXN], mrk[MAXN];
char c[MAXN];
ll dp[BITMASK];
pii cus[MAXN], P[BITMASK], acu[BITMASK];
queue <int> q;

int main (){
	scanf("%d", &n);
	for(int a=0;a<=(1<<n);a++){
		dp[a] = LLONG_MAX;
	}
	for(int a=0;a<n;a++){
		ll r, b;
		scanf(" %c %lld %lld", &c[a], &r, &b);
		cus[a].fst = r;
		cus[a].snd = b;
	}
	for(int a=0;a<(1<<n);a++){
		P[a].fst = P[a].snd = 0;
		for(int i=0;i<n;i++){
			if(!(a&(1<<i))) continue;
			P[a].fst += (c[i] == 'R');
			P[a].snd += (c[i] == 'B');
		}
	}
	q.insert(0);
	dp[0] = 0;
	while(!q.empty()){
		int bm = q.front();
		q.pop();
		for(int a=0;a<n;a++){
			if(bm&(1<<a)) continue;
			if(dp[bm|(1<<a)] < dp[bm] + max(0, max(cus[a].fst - P[bm].fst -acu[bm].fst, cus[a].snd - P[bm].snd-acu[bm].snd)))
			dp[bm|(1<<a)] = min(dp[bm|(1<<a)], dp[bm] + max(0, max(cus[a].fst - P[bm].fst, cus[a].snd - P[bm].snd)));
			if(dp[bm|(1<<a)] == dp[bm] + max(0, max(cus[a].fst - P[bm].fst, cus[a].snd - P[bm].snd))){
				
			}
		}

	}

}
