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

const int MAXN = 212345;

int n, m, k;
int s[MAXN], p[MAXN];
int mrk[MAXN];

map<int, int> ind[MAXN];

int raiz(int i){
	if(p[i] == i) return i;
	return p[i] = raiz(p[i]);
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);
	if(i == j) return;
	if(ind[i].size() < ind[j].size())
		swap(i, j);
	for(auto& x: ind[j]){
		ind[i][x.fst] += x.snd;
	}
	ind[j].clear();
	p[j] = i;
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=1;a<=n;a++){
		p[a] = a;
		scanf("%d", &s[a]);
		ind[a][s[a]] = 1;
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		join(i, j);
	}
	int res = 0;
	for(int a=1;a<=n;a++){
		int u = raiz(a);
		if(mrk[u]) continue;
		mrk[u] = 1;
		int imx, mx = INT_MIN;
		for(auto& x: ind[u]){
			if(x.snd > mx){
				mx = x.snd;
				imx = x.fst;
			}
		}
		for(auto& x: ind[u]){
			if(x.fst != imx){
				res += x.snd;
			}
		}
	}
	printf("%d\n", res); 

}
