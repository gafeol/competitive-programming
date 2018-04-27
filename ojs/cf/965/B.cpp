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
int s[MAXN];
char M[MAXN][MAXN];
int cnt[MAXN][MAXN];

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			scanf(" %c", &M[a][b]);
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b+k-1<n;b++){
			int ok = 1;
			for(int c=0;c<k;c++)
				if(M[a][b+c] == '#')
					ok = 0;
			for(int c=0;c<k;c++){
				cnt[a][b+c] += ok;
			}
		}
	}
	for(int a=0;a+k-1<n;a++){
		for(int b=0;b<n;b++){
			int ok = 1;
			for(int c=0;c<k;c++)
				if(M[a+c][b] == '#')
					ok = 0;
			for(int c=0;c<k;c++){
				cnt[a+c][b] += ok;
			}
		}
	}
	int mx = 0;
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			mx = max(mx, cnt[a][b]);
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			if(cnt[a][b] == mx){
				printf("%d %d\n", a+1, b+1);
				return 0;
			}
		}
	}
}

