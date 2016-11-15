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

const int MAXN = 2920;

int n, m, k;
int s[MAXN], mrk[MAXN][MAXN];
char M[MAXN][MAXN];


int vi[] = {0, 0, 1, -1};
int vj[] = {1, -1, 0, 0};

bool valid(int i, int j){
	return (i > 0 && j > 0 && i <= n && j <= m && M[i][j]== '.'); 
}

int cnt = 0;

void go(int i, int j){
	mrk[i][j] = 1;
	cnt++;
	for(int a=0;a<4;a++){
		int ii = i + vi[a];
		int jj = j + vj[a];
		if(valid(ii, jj) && !mrk[ii][jj]){
			go(ii, jj);
		}
	}
}

vector<pii> lag;
int sz[MAXN], ind[MAXN];

bool cmp(int a, int b){
	return sz[a] > sz[b];
}

void trans(int i, int j){
	M[i][j] = '*';
	for(int a=0;a<4;a++){
		int ii = i + vi[a];
		int jj = j + vj[a];
		if(valid(ii, jj)){
			trans(ii, jj);
		}
	}
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			scanf(" %c", &M[a][b]);
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			if(a == 1 || b == 1 || a == n || b == m){
				if(!mrk[a][b] && M[a][b] == '.'){
					go(a, b);
				}
			}
		}
	}
	int degl = 0;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			if(!mrk[a][b] && M[a][b] == '.'){
				cnt = 0;
				go(a, b);
				lag.pb(pii(a, b));
				ind[degl] = degl;
				sz[degl++] = cnt;
			}
		}
	}
	sort(ind, ind + degl, cmp);
	int res = 0;
	for(int a=degl-1;a>=k;a--){
		trans(lag[ind[a]].fst, lag[ind[a]].snd);
		res += sz[ind[a]];
	}
	printf("%d\n", res);
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			printf("%c", M[a][b]);
		}
		puts("");
	}
}
