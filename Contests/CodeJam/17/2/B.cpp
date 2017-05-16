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

const int MAXN = 2123;

int n, m, c;
vector<int> s[4];

int cnt[MAXN];

int mrk[MAXN][4];

int main (){
	for_tests(t, tt){
		int prom = 0;
		s[2].clear();
		s[1].clear();
		memset(mrk, 0, sizeof(mrk));
		scanf("%d%d%d", &n, &c, &m);
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			s[j].pb(i);
		}
		if(s[1].size() < s[2].size())
			swap(s[1], s[2]);
		int res = s[1].size();
		for(int i =0;i < s[1].size();i++){
			mrk[i][1] = s[1][i];
		}
		int j = 0;
		while(j < s[2].size()){
			int ok = 0;
			//ve se encaixa
			for(int i=0;i<s[1].size();i++){
				if(mrk[i][2] == 0 && mrk[i][1] != s[2][j]){
					mrk[i][2] = s[2][j];
					ok = 1;
					break;
				}
			}
			if(!ok){
				// tentando trocar
				for(int ii = 0;ii<s[1].size();ii++){
					if(mrk[ii][2] != 0 || s[2][j] == mrk[ii][1]) continue;
					for(int i=0;i<s[1].size();i++){
						if(mrk[i][2] == 0 || mrk[i][2] == mrk[ii][1]) continue;
						ok = 1;
						mrk[ii][2] = mrk[i][2];
						mrk[i][2] = s[2][j];
						break;
					}
					if(ok) break;
				}
			}
			if(!ok){
				//tentando proover
				for(int i=0;i<s[1].size();i++){
					if(mrk[i][2] == 0 && mrk[i][1] != 1){
						mrk[i][1] = mrk[i][1]-1;
						prom++;
						mrk[i][2] = s[2][j];
						ok = 1;
						break;
					}
				}
			}
			if(!ok){
				res++;
			}
			j++;
		}
		printf("Case #%d: %d %d\n", tt, res, prom);
	}
}
