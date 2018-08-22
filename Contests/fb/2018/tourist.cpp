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

const int MAXN = 52;

ll n, m, k, v;
char s[MAXN][30];

vector<int> ans;

int main (){
	for_tests(t, tt){
		scanf("%lld%lld%lld", &n, &k, &v);
		ll ini = (k*(v-1))%n;
		for(int a=0;a<n;a++){
			scanf(" %s", s[a]);
		}
		int cnt = 0;
		ans.clear();
		while(cnt < k){
			ans.pb(ini);
			ini = (ini+1)%n;
			cnt++;
		}
		sort(ans.begin(), ans.end());
		printf("Case #%d:", tt);
		for(int a=0;a<ans.size();a++){
			printf(" %s", s[ans[a]]);
		}
		puts("");
	}
}

