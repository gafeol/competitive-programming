

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

const int MAXN = 301;

int n, m, k;
int res;
int s[MAXN], cnt[MAXN][MAXN];
bool mrk[MAXN][MAXN][10][31][6];

#define U 0
#define UL 1
#define L 2
#define LD 3
#define D 4
#define DR 5
#define R 6
#define RU 7

int vi[] = {1, 1, 0, -1, -1, -1, 0, 1};
int vj[] = {0, -1, -1, -1, 0, 1, 1, 1};

void count(int i, int j){
	if(cnt[i][j]) return;
	cnt[i][j] = 1;
	res++;
}

int dir(int i){
	if(i == -1) return 7;
	return i%8;
}

int nxti(int i, int j, int d){
	d = dir(d);
	return i+vi[d];
}

int nxtj(int i, int j, int d){
	d = dir(d);
	return j+vj[d];
}

void go(int i, int j, int d, int st, int r){
	if(r == n) return;
	if(mrk[i][j][d][r][st] != 0) return;
	mrk[i][j][d][r][st] = 1;
	count(i, j);
	if(st == s[r]){
		go(nxti(i, j, d-1), nxtj(i, j, d-1), dir(d-1), 1, r+1);
		go(nxti(i, j, d+1), nxtj(i, j, d+1), dir(d+1), 1, r+1);
	}
	else{
		go(nxti(i, j, d), nxtj(i, j, d), d, st+1, r);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	go(150, 150, U, 1, 0);
	printf("%d\n", res);
}
