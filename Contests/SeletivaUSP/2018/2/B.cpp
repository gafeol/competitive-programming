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

const int MAXP = 1123456, MAXQ = 11234, MAXN = 1123;

int n, m, k;

int x[MAXQ], y[MAXQ], xx[MAXQ], yy[MAXQ];

int M[MAXN][MAXN];

int cnt;
int p[MAXP], sz[MAXP];

int vi[] = {1, -1, 0, 0};
int vj[] = {0, 0, 1, -1};

int id(int i, int j){
	return (i-1)*m + j-1;
}

bool valid(int i, int j){
	return (i > 0 && j > 0 && i <= n && j <= m && !M[i][j]);
}

int raiz(int u){
	if(p[u] == u) return u;
	return p[u] = raiz(p[u]);
}

void join(int i, int j, int ii, int jj){
	if(!valid(ii, jj)) return ;
	int u = id(i, j);
	int uu = id(ii, jj);
	int r = raiz(u);
	int rr = raiz(uu);
	if(r == rr) return ;
	cnt--;
	if(sz[rr] < sz[r])
		swap(rr, r);
	p[r] = rr;
	sz[rr] += sz[r];
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			sz[id(a, b)] = 1;
			p[id(a, b)] = id(a, b);
		}
	}
	for(int a=0;a<k;a++){
		scanf("%d %d %d %d", &x[a], &y[a], &xx[a], &yy[a]);
		if(xx[a] < x[a])
			swap(xx[a], x[a]);
		if(yy[a] < y[a])
			swap(yy[a], y[a]);
		for(int i=x[a];i<=xx[a];i++){
			for(int j=y[a];j<=yy[a];j++){
				M[i][j]++;					
			}
		}
	}
	stack<int> ans;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			if(M[a][b]) continue;
			cnt++;
			for(int d=0;d<4;d++){
				join(a, b, a+vi[d], b+vj[d]);
			}
		}
	}
	ans.push(cnt);
	for(int a=k-1;a>=0;a--){
		for(int i=x[a];i<=xx[a];i++){
			for(int j=y[a];j<=yy[a];j++){
				M[i][j]--;					
				if(M[i][j] == 0){
					cnt++;
					for(int d=0;d<4;d++){
						join(i, j, i+vi[d], j+vj[d]);
					}
				}
			}
		}
		ans.push(cnt);
	}
	ans.pop();
	while(!ans.empty()){
		printf("%d\n", ans.top());
		ans.pop();
	}
}

