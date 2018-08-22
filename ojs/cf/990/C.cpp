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

const int MAXN = 312345;

int n, m, k;

string s[MAXN];

int sum[MAXN];

map<int, int> bef, aft;

int main (){
	scanf("%d", &n);
	ll ans = 0;
	for(int a=0;a<n;a++){
		cin >> s[a];
		int tam = s[a].size();
		int cnt = 0;
		int okb = 1;
		int oka = 1;
		for(int i=0;i<tam;i++){
			cnt += (s[a][i] == '(');
			cnt -= (s[a][i] == ')');
			if(cnt < 0) okb = 0;
		}
		cnt = 0;
		for(int i=tam-1;i>=0;i--){
			cnt += (s[a][i] == '(');
			cnt -= (s[a][i] == ')');
			if(cnt > 0) oka = 0;

		}
		if(okb){
			ans += (ll)aft[-cnt];
			bef[cnt]++;
		}
		if(oka){
			ans += (ll)bef[-cnt];
			aft[cnt]++;
		}
	}
	printf("%lld\n", ans);
}
