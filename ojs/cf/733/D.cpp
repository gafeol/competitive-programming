#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define thd second
typedef unsigned long long ull;
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN]; 

map<pii, int> mrk, ind;

int mn(int a, int b, int c){
	return min(a, min(b, c));
}
pii ir;

main (){
	scanf("%lld", &n);
	int res = LLONG_MIN;
	int v[3];
	for(int a=0;a<n;a++){
		scanf("%lld%lld%lld", &v[0], &v[1], &v[2]);
		res = max(res, mn(v[0], v[1], v[2]));
		if(res == mn(v[0], v[1], v[2]))
			ir = pii(a, -1);
		do{
			if(mrk.find(pii(v[0], v[1])) != mrk.end()){
				if(res < mn(v[0], v[1], v[2] + mrk[pii(v[0], v[1])])){
					res = mn(v[0], v[1], v[2] + mrk[pii(v[0], v[1])]);
					ir = pii(a, ind[pii(v[0], v[1])]);
				}
			}
			if(mrk[pii(v[0], v[1])] < v[2]){
				mrk[pii(v[0], v[1])] = v[2];
				ind[pii(v[0], v[1])] = a;
			}
		} while(next_permutation(v, v+3));
	}
	printf("%lld\n%lld ", ((ir.snd==-1)? 1ll:2ll), ir.fst+1ll);
	if(ir.snd != -1)
		printf("%lld", ir.snd+1);
}
