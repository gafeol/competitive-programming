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

const int MAXN = 212345;

int n, m, k, i, j, d;
char s[MAXN];
int M[110][110];

/*
0 up
1 ri
2 lf
3 d
*/

int di[] = {-1, 0, 0, 1};
int dj[] = {0, 1, -1, 0};

int F, B, R, L;
int ind[4][4];

int l(int x){
	char c = s[x];
	if(c == 'F')
		return F;
	if(c == 'B')
		return B;
	if(c == 'R')
		return R;
	return L;
}

inline void mv(int a){
	int mov = ind[d][l(a)];
	i += di[mov];
	j += dj[mov];
	d = mov;
}

int main (){
	F = 0;
	R = 1;
	L = 2;
	B = 3;
	ind[R][F] = R;
	ind[R][R] = B;
	ind[R][L] = F;
	ind[R][B] = L;

	ind[L][F] = L;
	ind[L][R] = F;
	ind[L][L] = B;
	ind[L][B] = R;

	ind[F][F] = F;
	ind[F][R] = R;
	ind[F][L] = L;
	ind[F][B] = B;

	ind[B][F] = B;
	ind[B][R] = L;
	ind[B][L] = R;
	ind[B][B] = F;

	for_tests(t, tt){
		memset(M, 0, sizeof(M));
		if(tt == 1)
			printf("%d\n", t);
		scanf(" %s", s);
		n = strlen(s);
		i = j = 0;
		d = 1;
		int mxi, mni, mxj, mnj;
		mxi = mxj = 0;
		mni = mnj = 0;
		for(int a=0;a<n;a++){
			mv(a);	
			mxi = max(mxi, i);
			mxj = max(mxj, j);
			mni = min(mni, i);
			mnj = min(mnj, j);
		}
		printf("%d %d\n", 2+mxi-mni+1, 1+mxj-mnj+1);
		int h = 2+mxi-mni+1;
		int w = 1+mxj-mnj+1;
		i = abs(mni) + 1;
		j = 0;
		d = 1;
		for(int a=0;a<n;a++){
			mv(a);	
			M[i][j] = 1;
		}
		for(int a=0;a<h;a++){
			for(int b=0;b<w;b++){
				if(M[a][b])
					printf(".");
				else
					printf("#");
			}
			printf("\n");
		}
	}
}
