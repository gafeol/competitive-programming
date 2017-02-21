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
int s[MAXN], pos[MAXN], mx[MAXN], res[MAXN], cnt[MAXN];

vector<pii> lis;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		mx[a] = INT_MIN;
	}
	lis.pb(pii(s[0], 0));
	pos[0] = 0;
	for(int a=1;a<n;a++){
		int i = lower_bound(lis.begin(), lis.end(), pii(s[a],  -a)) - lis.begin();
		if(i == lis.size())
			lis.pb(pii(s[a], -a));
		else
			lis[i] = pii(s[a], -a);
		pos[a] = i;
		debug("s[%d] %d pos %d\n", a, s[a], pos[a]);
	}
	mx[lis.size()] = INT_MAX;
	debug("sz %d\n", (int)lis.size());
	for(int a=n-1;a>=0;a--){
		if(mx[pos[a]+1] <= s[a]){
			res[a] = 1;
			continue;
		}
		mx[pos[a]] = max(mx[pos[a]], s[a]);
		cnt[pos[a]]++;
	}
	for(int a=0;a<n;a++){
		if(res[a] != 1)
			res[a] = 2 + (cnt[pos[a]] == 1);
		printf("%d", res[a]);
	}

}
