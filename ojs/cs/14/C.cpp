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

int n, m, k;
int M[MAXN][MAXN], sum[MAXN][MAXN];
int mrk[MAXN][MAXN];
int vi[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int vj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool valid(int i, int j){
	return (i >= 1 && j >0 && i <=n && j <= m);
}
int mrk2[MAXN][MAXN], qtd;

int w(int i, int j){
	int r = j;
	while(valid(i, r+1) && M[i][r+1] == 1)
		r++;
	return r;
}

int l(int i, int j){
	int d = i;
	while(valid(d+1,j) && M[d+1][j])
		d++;
	//ta inverttidoo
	return d;
}

pii mn, mx;

void cnt(int i, int j){
	debug("CNT %d %d\n", i, j);
	mn = min(mn, pii(i, j));
	mx = max(mx, pii(i, j));
	mrk2[i][j] = 1;
	qtd++;
	for(int a=0;a<8;a++){
		int ii = i + vi[a], jj = j+vj[a];
		if(valid(ii, jj) && !mrk2[ii][jj] && M[ii][jj])
			cnt(ii, jj);
	}
}

void go(int i, int j){
	debug("GO %d %d\n", i, j);
	mrk[i][j] = 1;
	for(int a=0;a<8;a++){
		int ii = i + vi[a], jj = j+vj[a];
		if(valid(ii, jj) && !mrk[ii][jj] && M[ii][jj])
			go(ii, jj);
	}
}
int res = 0;

int soma(int i, int j, int ii, int jj){
	return sum[ii][jj] - sum[ii][j-1] - sum[i-1][jj] + sum[i-1][j-1];
}

void proi(int a, int b){
	if(M[a][b] == 0) return ;
	if(a == 1 || b == 1 || a == n || b == m){
		go(a, b);
		return;
	}
	qtd = 0;
	mn = mx = pii(a, b);
	cnt(a, b);
	int i = mn.fst, j = mn.snd, ii = mx.fst, jj = mx.snd;
	debug("%d %d - %d %d\n", i, j, ii, jj);
	if(qtd != (ii - i + 1)*(jj - j + 1) || soma(i, j, ii, jj) != qtd  || soma(i-1, j-1, ii + 1, jj + 1) != qtd)
		go(a, b);
	else
		res = max(qtd, res);
}

int main (){
	res = -1;
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n+1;a++){
		for(int b=1;b<=m+1;b++){
			M[a][b] = 0;
			if(a <= n && b <= m) scanf("%d", &M[a][b]);
			sum[a][b] = sum[a-1][b] + sum[a][b-1] - sum[a-1][b-1] + M[a][b];
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			if(a == 1 || a== n || b == 1 || b == m){
				if(!mrk[a][b] && M[a][b] == 1)
					go(a, b);
			}
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			if(!mrk[a][b] && !mrk2[a][b])
				proi(a, b);
		}
	}
	printf("%d\n", res);
}
