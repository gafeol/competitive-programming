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

const int MAXN = 22;

int n, m, k;
int s[MAXN][MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf("%d", &s[a][b]);
			s[a][b]--;
		}
	}
	int res = 0;
	int deu = 1;
	for(int a=0;a<n;a++){
		int cnt = 2;
		for(int b=0;b<m;b++){
			if(s[a][b] != b){
				if(s[a][s[a][b]] == b)
					cnt--;
				else
					deu = 0;
			}
		}
		if(cnt < 0) deu = 0;
	}
	res = max(res, deu);

	for(int i = 0;i < m;i++){
		for(int j = 0;j < m;j++){
			if(i == j) continue;
			deu = 1;
			for(int a=0;a<n;a++){
				swap(s[a][i], s[a][j]);
				int cnt = 2;
				for(int b=0;b<m;b++){
					if(s[a][b] != b){
						if(s[a][s[a][b]] == b)
							cnt--;
						else
							deu = 0;
					}
				}
				if(cnt < 0) deu = 0;
			}
			for(int a=0;a<n;a++)
				swap(s[a][i], s[a][j]);
			res = max(res, deu);
		}
	}
	if(res)
		puts("YES");
	else
		puts("NO");
}
