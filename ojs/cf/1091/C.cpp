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

bool cmp(int a, int b){
	return a > b;
}

ll pa(ll ini, ll fim, ll r){
	ll qtd = (fim - ini)/r + 1;
	return ((ini + fim)*qtd)/2ll - n - 1;
}

int main (){
	scanf("%d", &n);
	vector<int> d;
	for(int a=1;a<=sqrt(n);a++){
		if(n%a == 0){
			d.pb(a);
			d.pb(n/a);
		}
	}
	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());

	
	for(int i = d.size()-1;i>=0;i--){
		int v = d[i];
		printf("%lld ", pa(1, n+1, v));
	}
}

