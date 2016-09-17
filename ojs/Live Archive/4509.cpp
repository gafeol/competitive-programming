#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 32, INF = 0x3f3f3f3f;

int n, m, k, h, d[MAXN][MAXN], grv[MAXN][MAXN];

pair<pii, int> htd[MAXN][MAXN];

int main (){
	scanf("%d%d", &n, &m);
	scanf("%d", &k);
	for(int a=0;a<k;a++){
		scanf("%d%d",&
	}
	memset(d, INF, sizeof(d));
	for(int i=0;i<n;i++){
		for(int a
	}
}
