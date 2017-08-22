
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


const int MAXN = 5123;

int n, m, k;
int s[MAXN];

int M[MAXN][MAXN];

int asdas[3];
int op[3];

void solve(){
	printf("0 ");
	s[0] = 0;
	for(int a=1;a<n;a++){
		op[0] = -M[a][0];
		op[1] = M[a][0];
		asdas[0] = 1;
		asdas[1] = 1;
		for(int b=1;b<a;b++){
			for(int t=0;t<2;t++){
				if(abs(s[b] - op[t]) != M[b][a])
					asdas[t] = 0;
			}
		}
		if(asdas[0] == 0)
			s[a] = op[1];
		else if(asdas[1] == 0)
			s[a] = op[0];
		else
			s[a] = min(op[1], op[0]);
		printf("%d ", s[a]);
	}
	puts("");
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			scanf("%d", &M[a][b]);
		}
	}
	solve();
	while(m--){
		int i;
		scanf("%d", &i);
		i--;
		for(int a=0;a<n;a++){
			int x;
			scanf("%d", &x);
			M[i][a] = x;
			M[a][i] = x;
		}
		solve();
	}
}

