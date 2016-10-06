#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 32, INF = 0x3f3f3f3f;

int n, m, k, h, d[MAXN][MAXN], grv[MAXN][MAXN];
int mrk[MAXN][MAXN];

pair<pii, int> htd[MAXN][MAXN];

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m && !grv[i][j] && !mrk[i][j]);
}

int vi[] = {0, 0, -1, 1};
int vj[] = {1, -1, 0, 0};

void go(int i, int j){
	mrk[i][j] = 1;
	if(grv[i][j] == -1){
		if(valid(htd[i][j].fst.fst, htd[i][j].fst.snd))
			go(htd[i][j].fst.fst, htd[i][j].fst.snd);
	}
	else{
		for(int a=0;a<4;a++){
			if(valid(i+vi[a], j + vj[a]))
				go(i+vi[a], j + vj[a]);		
		}
	}
}

int main (){
	while(scanf("%d%d", &n, &m) != EOF && n+m){
		scanf("%d", &k);
		int i, j;
		for(int a=0;a<k;a++){
			scanf("%d%d", &i, &j);
			grv[i][j] = 1;
		}
		scanf("%d", &k);
		for(int a=0;a<k;a++){
			int ii, jj, c;
			scanf("%d%d%d%d%d", &i, &j, &ii, &jj, &c);
			htd[i][j] = ppi(pii(ii,	 jj), c);
			if(grv[i][j])
				grv[i][j] = -1;
		}
		memset(d, INF, sizeof(d));
		go(0, 0);
		for(int i=0;i<n-1;i++){
			for(int a=0;a<n;a++){
				for(int b=0;b<m;b++){
					if(!mrk[a][b]) continue;
					if(grv[a][b] == -1){
						if(d[htd[a][b].fst.fst][htd[a][b].fst.snd] > d[a][b] + htd[a][b].snd)
							d[htd[a][b].fst.fst][htd[a][b].fst.snd] = d[a][b] + htd[a][b].snd;

					}
					else if(grv[a][b] == 0){
						for(int c=0;c<4;c++){
							if(valid(a + vi[c], b + vj[c])){
								if(d[a+vi[c]][b+vj[c]] > d[a][b] + 1){
									d[a+vi[c]][b+vj[c]] = d[a][b] + 1;

								}
							}
						}
					}
				}
			}
		}
		int mudou = 0;
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				if(!mrk[a][b]) continue;
				if(grv[a][b] == -1){
					if(d[htd[a][b].fst.fst][htd[a][b].fst.snd] > d[a][b] + htd[a][b].snd){
						d[htd[a][b].fst.fst][htd[a][b].fst.snd] = d[a][b] + htd[a][b].snd;
						mudou = 1;
					}
				}
				else if(grv[a][b] == 0){
					for(int c=0;c<4;c++){
						if(valid(a + vi[c], b + vj[c])){
							if(d[a+vi[c]][b+vj[c]] > d[a][b] + 1){
								d[a+vi[c]][b+vj[c]] = d[a][b] + 1;
								mudou = 1;

							}
						}
					}
				}
			}
		}
		if(mudou)
			puts("Never");
		else{
			if(d[n-1][m-1] == INF)
				puts("Impossible");
			else
				printf("%d\n", d[n-1][m-1]);
		}
	}
}
