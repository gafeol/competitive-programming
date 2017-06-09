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

struct pti{
	int x, y, c;
	pti(){}
	pti(int xx, int yy, int cc){
		x = xx;
		y = yy;
		c = cc;
	}
} s[MAXN];

vector<int> Y;

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &k);
		for(int a=0;a<n;a++){
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c);
			s[a] = pti(x, y, c);
			Y.pb(y);
		}
		sort(Y.begin(), Y.end());
		int i = 0, j = Y.size()-1;
	}
}
