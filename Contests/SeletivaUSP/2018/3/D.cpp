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

int n, m, k;
char s[20][10];

int sz[20];

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf(" %s", s[a]);
			sz[a] = strlen(s[a]);
		}
		int ans = 0;
		for(int tam=1;!ans;tam++){
			for(int bm=0;!ans && bm<(1<<tam);bm++){
				int ok = 1;
				for(int a=0;ok && a<n;a++){
					int b = 0;
					for(int j=0;b < sz[a] && j<tam;j++){
						if((s[a][b] == 'B') == ((bm&(1<<j)) > 0))
							b++;
					}
					if(b < sz[a]) ok = 0;
				}
				if(ok){
					for(int j=0;j<tam;j++){
						printf("%c", ((bm&(1<<j)) > 0 ? 'B' : 'G'));
					}
					puts("");
					ans = 1;
				}
			}
		}
	}
}

