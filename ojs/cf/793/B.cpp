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
int s[MAXN];
char M[MAXN][MAXN], mrk[MAXN][MAXN][5][3];

int inii, inij, fimi, fimj;
int res;

int vi[] = {1, -1, 0, 0};
int vj[] = {0, 0, -1, 1};

bool valid(int i, int j){
	return (i > 0 && j > 0 && i <= n && j <= m && M[i][j] != '*');
}

void go(int i, int j, int d, int cnt){
	if(cnt == 3) return ;
	if(mrk[i][j][d][cnt]) return ;
	mrk[i][j][d][cnt] = 1;
	if(i == fimi && j == fimj)
		res = 1;
	for(int dir =0;dir < 4;dir++){
		if(valid(i+vi[dir], j+vj[dir]))
			go(i+vi[dir], j + vj[dir], dir, cnt + (dir != d));	
	}
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			scanf(" %c", &M[a][b]);
			if(M[a][b] == 'S'){
				inii = a;
				inij = b;
			}
			else if(M[a][b] == 'T'){
				fimi = a;
				fimj = b;
			}
		}
	}
	for(int a=0;a<4;a++){
		go(inii, inij, a, 0);
	}
	if(res)
		puts("YES");
	else
		puts("NO");
}
