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

const int MAXN = 1123;

int n, m, k;
int mrk[MAXN][MAXN], acu[MAXN][MAXN];

vector<pii> s;

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &k);
		s.clear();
		for(int a=0;a<=1001;a++){
			for(int b=0;b<=1001;b++){
				mrk[a][b] = 0;
				acu[a][b] = 0;
			}
		}
		for(int a=0;a<n;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			mrk[i][j] = 1;
			s.pb(pii(i, j));
		}
		for(int a=1;a<=1001;a++){
			for(int b=1;b<=1001;b++){
				acu[a][b] = mrk[a][b] + acu[a-1][b] + acu[a][b-1] - acu[a-1][b-1];
			}
		}
		int res = 0;
		for(pii e: s){
			for(pii u : s){
				if(e.fst > u.fst || e.snd < u.snd) continue;
				for(pii d: s){
					if(e.fst > d.fst || d.snd < u.snd || d.fst < u.fst) continue;
					int esq = e.fst;
					int dir = d.fst;
					if(esq == dir)
						dir++;
					int up = u.snd;
					if(dir - esq > k) continue;
					if((dir - esq)*(max(e.snd, d.snd) - up) > k) continue;
					int dw = min(1000, up + (k/(dir - esq)));
					//debug("esq %d dir %d up %d dw %d\n", esq, dir, up, dw);
					int ans = acu[dir][dw] + acu[esq-1][up-1] - acu[dir][up-1] - acu[esq-1][dw];
					res = max(res,ans);
				}
			}
		}
		printf("%d\n", res);
	}
}

