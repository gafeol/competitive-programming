#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

int n[2], m, k;
pll s[MAXN][2], c, o;
int ind[MAXN][2];

vector<pll> q[2][4];

ll res;

bool cmp(pll a, pll b){
	// sl(a) < sl(b)
	return (a.snd*b.fst < a.fst*b.snd);
}

int quad(pii x){
/*    0|1
      ---
      3|2   */
	if(x.fst == 0){
		if(x.snd > 0) return 1;
		return 3;
	}
	int ans = 0;
	if(x.fst < 0){
		if(x.snd < 0)
			ans = 3;
		else
			ans = 0;
	}
	else{
		if(x.snd < 0)
			ans = 2;
		else
			ans = 1;
	}
	return ans;
}

int main (){
	for_tests(te, tt){
		scanf("%d%d", &n[0], &n[1]);
		res = min(n[0], n[1]);
		for(int t=0;t<2;t++){
			for(int a=0;a<n[t];a++){
				int x, y;
				scanf("%d %d", &x, &y);
				s[a][t] = pii(x, y);
			}
		}
		for(int i=0;i<n[0];i++){
			c = s[i][0];
			for(int t=0;t<2;t++){
				for(int a=0;a<n[t];a++){
					s[a][t].fst -= c.fst;
					s[a][t].snd -= c.snd;
					if(s[a][t] != pll(0, 0))
						q[t][quad(s[a][t])].pb(s[a][t]);
				}
			}
			for(int t=0;t<2;t++){
				for(int qd=0;qd<4;qd++){
					sort(q[t][qd].begin(), q[t][qd].end(), cmp);
				}
			}
			ll qtd[2];
			memset(qtd, 0, sizeof(qtd));


			for(int j=0;j<n[1];j++){
				o = s[j][1];
				int qd = quad(o);
				debug("c %lld %lld o %lld %lld qd %d\n", c.fst, c.snd, o.fst, o.snd, qd);
				for(int t=0;t<2;t++){
					qtd[t] += q[t][(qd+3)%4].size();
					debug("no quadrante (%d) abaixo %d\n", (qd+3)%4, q[t][(qd+3)%4].size());
					qtd[t] += q[t][qd].end() - upper_bound(q[t][qd].begin(), q[t][qd].end(), o, cmp);
					debug("em %d slp > %d\n", qd, (int)(q[t][qd].end() - upper_bound(q[t][qd].begin(), q[t][qd].end(), o, cmp)));
					int op = (qd+2)%4;
					qtd[t] += lower_bound(q[t][op].begin(), q[t][op].end(), o, cmp) - q[t][op].begin();
					debug("em %d slp < %d\n", op, (int)(lower_bound(q[t][op].begin(), q[t][op].end(), o, cmp) - q[t][op].begin()));
				}
				debug("res = min(%lld, min(%lld, %lld))\n", res, qtd[0] + (n[1] - qtd[1] -1), (n[0] - qtd[0] - 1) + qtd[1]); 
				res = min(res, min(qtd[0] + (n[1] - qtd[1] - 1), (n[0] - qtd[0] - 1) + qtd[1]));
				qtd[0] = 0;
				qtd[1] = 0;
			}

			
			for(int t=0;t<2;t++){
				for(int a=0;a<n[t];a++){
					s[a][t].fst += c.fst;
					s[a][t].snd += c.snd;
				}
				q[t][0].clear();
				q[t][1].clear();
				q[t][2].clear();
				q[t][3].clear();
			}
		}
		printf("%lld\n", res);
	}
}

