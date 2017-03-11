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

const int MAXN = 31234;

int n, m, k;
int s[MAXN];
vector<int> p;
vector<int> res;

int mrk[MAXN];

int main (){
	for(ll a=2;a<MAXN;a++){
		if(mrk[a]) continue;
		p.pb(a);
		for(ll b=2;a*b<MAXN;b++){
			mrk[a*b]++;
		//	if(a*b == 30) printf("p %d b %d mrk[a*b] %d\n", a, b, mrk[a*b]);
			if(mrk[a*b] == 3)
				res.pb(a*b);
		}
	}
//	printf("sz %d\n", res.size());
	sort(res.begin(), res.end());
	for_tests(t, tt){
		scanf("%d", &n);
		n--;
		printf("%d\n", res[n]);
	}
}
