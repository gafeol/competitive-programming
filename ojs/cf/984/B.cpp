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

const int MAXN = 212;

int n, m, k;
int s[MAXN][MAXN];
int d[MAXN];

bool valid(int i, int j){
	return (i>=0 && j >= 0 && i < n && j < m);

}

int vi[] = {0, 0, 1, 1, 1, -1, -1, -1};
int vj[] = {1, -1, 1, -1, 0, 1, -1, 0};

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			char c;
			scanf(" %c", &c);
			s[a][b] = (c-'0');
			if(c == '*') s[a][b] = 0;
			if(c == '.') s[a][b] = -1;
		}
	}
	int ok = 1;
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			if(s[a][b] == 0){
				for(int d=0;d<8;d++){
					int ii = a + vi[d];
					int jj = b + vj[d];
					if(valid(ii, jj) && s[ii][jj] < 0)
						ok = 0;
				}
			}
			else if(s[a][b] == -1){
				for(int d=0;d<8;d++){
					int ii = a + vi[d];
					int jj = b + vj[d];
					if(valid(ii, jj) && s[ii][jj] == 0)
						ok = 0;
				}
			}
			else{
				int cnt = 0;
				for(int d=0;d<8;d++){
					int ii = a + vi[d];
					int jj = b + vj[d];
					if(valid(ii, jj) && s[ii][jj] == 0)
						cnt++;
				}
				if(cnt != s[a][b]) ok = 0;
			}
		}
	}
	if(ok)
		puts("YES");
	else
		puts("NO");
}


