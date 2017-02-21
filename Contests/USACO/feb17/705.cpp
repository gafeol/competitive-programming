#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
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

const int MAXN = 212, INF = 3e8;

int n, m, k, t;
int s[MAXN], M[MAXN][MAXN], d[MAXN][MAXN], mrk[MAXN][MAXN];

set<pip> q;

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < n);
}

int main (){
	freopen("visitfj.in", "r", stdin);
	freopen("visitfj.out", "w", stdout);
	scanf("%d%d", &n, &t);
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			d[a][b] = INF;
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			scanf("%d", &M[a][b]);
		}
	}
	d[0][0] = 0;
	q.insert(pip(0, pii(0,0)));
	while(!q.empty()){
		pip top = *q.begin();
		q.erase(top);
		int i = top.snd.fst;
		int j = top.snd.snd;
		mrk[i][j] = 1;
		for(int a=-3;a<=3;a++){
			for(int b=-3;b<=3;b++){
				int ii = i + a, jj = j+b;
				if(!valid(i+a, j+b) || abs(a) + abs(b) > 3 || mrk[ii][jj]) continue;
				if(ii == n-1 && jj == n-1)
					d[ii][jj] = min(d[ii][jj], d[i][j] + (abs(a)+abs(b))*t + (abs(a)+abs(b)==3)*M[ii][jj]);
				if(!((abs(a)+abs(b))&1)) continue;
				if(d[ii][jj] != INF)
					q.erase(pip(d[ii][jj], pii(ii, jj)));
				d[ii][jj] = min(d[ii][jj], d[i][j] + 3*t + M[ii][jj]);
				q.insert(pip(d[ii][jj], pii(ii, jj)));
			}
		}
	}
	printf("%d\n", d[n-1][n-1]);
}
