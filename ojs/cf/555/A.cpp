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

vector<int> c[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	int res = 0;
	int nm = m;
	int i = 0;
	for(int a=0;a<m;a++){
		int t, tt = 0;
		scanf("%d", &t);
		for(tt = 0;tt<t;tt++){
			int x;
			scanf("%d", &x);
			if(x == 1) i = a;
			c[a].pb(x);
		}
	}
	int mn=1;
	for(mn=1;mn<c[i].size();mn++){
		if(c[i][mn] != mn+1)
			break;
	}
	for(int a=0;a<m;a++){
		int t = c[a].size(), tt;
		for(tt = 0;tt<t;tt++){
			if(c[a][tt] > mn){
				res += t-tt;
				nm += t-tt;
				if(tt == 0){
					res--;
					nm--;
				}
				//printf("a %d tt %d res %d nm %d\n", a, tt, res, nm);
				break;
			}
		}
	}
	res += nm-1;
	printf("%d\n", res);
}
