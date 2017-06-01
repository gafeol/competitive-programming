#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define int ll
typedef unsigned long long ull;
typedef long long ll;
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

int n, m, k;
int N, K;
int s[MAXN];

vector<pii> ev[2];
multiset<int> q;
int fodeu;

int go(int t){
	q.clear();
	vector<pii> v = ev[t];
	sort(v.begin(), v.end());
	int ate = (N - K)/2 + 1;
	int ans = 0;
	for(int i =0;i < v.size();i++){
		pii e = v[i];
		if(e.fst <= ate)
			q.insert(e.snd); 
		else{
			if(q.empty()){
				fodeu = 1;
				return 0;
			}
			int prox = *q.rbegin();
			if(prox <= ate){
				fodeu = 1;
				return 0;
			}
			else{
				ans++;
				ate = prox;
				q.erase(q.find(prox));
				i--;
			}
		}
		if(ate >= (N-K)/2 + 1 + K)
			return ans;
	}
	if(q.empty()){
		fodeu = 1;
		return 0;
	}
	int prox = *q.rbegin();
	if(prox <= ate){
		fodeu = 1;
		return 0;
	}
	else{
		ans++;
		ate = prox;
		q.erase(q.find(prox));
	}
	if(ate >= (N-K)/2 + 1 + K)
		return ans;
	fodeu = 1;
	return 0;
}

main (){
	for_tests(t, tt){
		scanf("%lld%lld %lld", &N, &K, &n);
		ev[0].clear();
		ev[1].clear();
		for(int a=0;a<n;a++){
			int x, y, xx, yy;
			scanf("%lld %lld %lld %lld", &x, &y, &xx, &yy);
			if(x > xx || y > yy){
				swap(x, xx);
				swap(y, yy);
			}
			ev[0].pb(pii(x, xx+1));
			ev[1].pb(pii(y, yy+1));
		}
		fodeu = 0;
		int ans = go(0) + go(1);
		if(fodeu)
			puts("-1");
		else
			printf("%lld\n", ans);
	}
}
