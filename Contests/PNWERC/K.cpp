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

const int MAXN = 45, INF = 20000;

int n, m, k;
int s[MAXN];
int dp[MAXN][3][3];

int go(int i, int fe, int fd){
	if(dp[i][fe][fd] < INF) return dp[i][fe][fd];
	int &r = dp[i][fe][fd];
	if(i == n/2 + (n&1) - 1){
		if(n&1){
			int nv = s[i] + fd;
			if(fe)
				return r = 10 - nv;
			return r = INF*(nv > 9);
		}
		else{
			int nv = s[i+1]+fd + 10*s[i];
			assert(nv <= 100);
			if(fe)
				return r = min(100 - nv, 10-(nv/10)+(nv%10));
			if(nv == 100)
				return r = INF;
			return r = abs(nv%10 - nv/10);
		}
	}
	for(int d=0;d<=9;d++){
		for(int te=0;te<2;te++){
			for(int td=0;td<2;td++){
				int vd = s[n-1-i] + fd;
				if((d < vd || vd == 10) && td == 0) continue; 
				int cus = 0;
				if(td == 1)
					cus += 10+d - vd;
				else 
					cus += d - vd;
				
				int ve = s[i];
				if(te)
					ve++;
				if(fe)
					cus += 10+d-ve;
				else{
					if(d < ve || ve == 10) continue;
					cus += d - ve;
				}

				r = min(r, cus + go(i+1, te, td));
			}
		}
	}
	return r;
}

char st[MAXN];

int main (){
	scanf(" %s", st);
	n = strlen(st);
	for(int a=0;a<n;a++){
		char c;
		c = st[a];
		s[a] = c-'0';
	}
	int ans = 0;
	for(int a=0;a<=n;a++){
		for(int b=0;b<2;b++){
			for(int c=0;c<2;c++){
				dp[a][b][c] = INF;
			}
		}
	}
	printf("%d\n", min(go(0, 0, 0), go(0, 1, 0)));
}

