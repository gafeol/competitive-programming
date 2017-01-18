
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
int s[MAXN], f[MAXN];

map<int, int> mrk;
int res;

vector<int> p;

int main (){
	f[0] = f[1] = 1;
	res = 1;
	for(ll i=2;i<MAXN;i++){
		if(f[i] != 0) continue;
		f[i] = 1;
		p.pb(i);
		for(ll d=i;i*d < MAXN;d++){
			f[i*d] = i;
		}
	}
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		mrk[s[a]]++;
	}
	for(ll pri:p){
		int cnt = 0;
		for(ll d=1;d*pri < MAXN;d++){
			if(mrk.find(pri*d) != mrk.end()){
				cnt += mrk[pri*d];
			}
		}
		res = max(res, cnt);
	}
	printf("%d\n", res);
}
