#include <iostream>
#include<cstdlib>
#include <algorithm>
#include <climits>
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

const int MAXN = 6;

int n, m, k;
int s[MAXN];
int mrk[MAXN][MAXN];
char M[MAXN][MAXN];

int vi[] = {0, 0, -1, 1, 1, 1, -1, -1};
int vj[] = {1, -1, 0, 0, -1, 1, -1, 1};

bool valid(int i, int j){
	return (i>= 0 && j>=0 && i < n &&  j< n);
}

int res = INT_MIN;

void go(int i, int j, int p, int ld){
	mrk[i][j] = 1;
	char c = M[i][j];
	if(M[i][j] == '1')
		p++;
	else if(M[i][j] == '#')
		p = p*2;
	else if(c == '-')
		p--;
	else if(c == '*')
		p = 0;

	res = max(res, p);
	
	for(int d=0;d<8;d++){
		int ii = i + vi[d];
		int jj = j + vj[d];

		if(valid(ii, jj) && !mrk[ii][jj])
			go(ii, jj, p - (ld != -1 && ld != d), d);
	}
	mrk[i][j] = 0;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			scanf(" %c", &M[a][b]);
			if(M[a][b] == '-')
				scanf("1");
		}
	}
	go(n-1, 0, 0, -1);
	printf("%d", res);
}

