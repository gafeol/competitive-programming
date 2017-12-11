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

int lo[MAXN];

set<int> q;

int res[MAXN];
int pos[MAXN];
int ans;
int ok[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		pos[s[a]] = a;
	}
	for(int a=0;a<n;a++){
		auto it = q.upper_bound(s[a]);
		if(it == q.end()){
			ok[s[a]] = 1;
			debug("ok %d = 1\n", s[a]);
			ans++;
		}
		else{
			auto itt = it;
			itt++;
			if(itt == q.end()){
				res[(*it)]++;
				debug("res %d ++\n", (*it));
			}
		}
		q.insert(s[a]);
	}
	int bst = -2, ib;
	debug("ans %d\n", ans);
	for(int a=1;a<=n;a++){
		if(bst < ans - ok[a] + res[a]){
			debug("a = %d\n", a);
			debug("%d < %d - %d + %d\n", bst, ans, (lo[s[a]] == a), res[a]);
			bst = ans - ok[a] + res[a];
			ib = a;
		}
	}
	printf("%d\n", ib);
}
