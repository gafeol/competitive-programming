
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

const int MAXN = 1123, INF = 0x3f3f3f3f;

int n, m, k;

int d[MAXN][MAXN];
char M[MAXN][MAXN];
int s[MAXN];

int vi[] = {0, 0, -1, 1};
int vj[] = {1, -1, 0, 0};

queue<pii> q;

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m && M[i][j] != '#');
}

void go(int i, int j){
	d[i][j] = 0;
	q.push(pii(i, j));
	while(!q.empty()){
		i = q.front().fst;
		j = q.front().snd;
		q.pop();
		for(int dir=0;dir<4;dir++){
			int ni = i + vi[dir];
			int nj = j + vj[dir];
			if(!valid(ni, nj)) continue;
			if(d[ni][nj] > d[i][j] + 1)
				q.push(pii(ni, nj));
			d[ni][nj] = min(d[ni][nj], d[i][j] + 1);
		}
	}
}

int mn = INT_MAX, mni, mnj;



void atu(int i, int j){
	if(!valid(i, j)) return ;
	if(mn > d[i][j]){
		mn = d[i][j];
		mni = i;
		mnj = j;
	}
}

int main (){
	memset(d, INF, sizeof(d));
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf(" %c", &M[a][b]); 
		}
	}
	int i, j, ii, jj;
	scanf("%d %d %d %d", &i, &j, &ii, &jj);
	i--;
	j--;
	ii--;
	jj--;
	d[ii][jj] = 0;
	go(ii, jj);
	int res = 0;
	if(d[i][j] == INF){
		puts("-1");
		return 0;
	}
	while(i != ii || j != jj){
		mn = INT_MAX;
		for(int a=1;a<=k;a++){
			if(!valid(i+a, j)) break;
			atu(i+a, j);
		}
		for(int a=1;a<=k;a++){
			if(!valid(i-a, j)) break;
			atu(i-a, j);
		}
		for(int a=1;a<=k;a++){
			if(!valid(i, j+a)) break;
			atu(i, j+a);
		}
		for(int a=1;a<=k;a++){
			if(!valid(i, j-a)) break;
			atu(i, j-a);
		}
		res++;
		i = mni;
		j = mnj;
		debug("i %d j %d\n", i, j);
	}
	printf("%d\n", res);
}

