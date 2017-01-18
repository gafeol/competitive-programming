#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
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

const int MAXN = 212345, INF = 0x3f3f3f3f;

int n, m, k;
int M[100][100], mrk[100][100];
set<ppi> s;

int vi[] = {1, -1, 0, 0};
int vj[] = {0, 0, -1, 1};

int dist(int i, int j, int ii, int jj, int t){
	if((M[i][j] + t)%10 + 1 >= (M[ii][jj] + t)%10){ 
		return 1;
	}
	else{
		return 11 - (M[ii][jj] + t)%10;
	}
}

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}

int main (){
	memset(mrk, INF, sizeof(mrk));
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf("%d", &M[a][b]);
		}
	}
	s.insert(ppi(0, pii(0, 0)));
	mrk[0][0] = 0;
	while(!s.empty()){
		ppi t = *(s.begin());
		int i = t.snd.fst;
		int j = t.snd.snd;
		int d = t.fst;
		s.erase(s.begin());
		for(int a=0;a<4;a++){
			int ii = i + vi[a], jj = j + vj[a];
			if(valid(i+vi[a], j+vj[a]) && mrk[ii][jj] > mrk[i][j] + dist(i, j, ii, jj, d)){
				mrk[ii][jj] = mrk[i][j] + dist(i, j, ii, jj, d);			
				s.insert(ppi(mrk[ii][jj], pii(ii, jj)));
			}
		}
	}
	printf("%d\n", mrk[n-1][m-1]);
}
