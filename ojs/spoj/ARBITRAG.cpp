#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;
const int MX = 32;

int n, m, k, deg;

string s[MX];
map<string, int> ind;


long double d[MX][MX];
long double ini[MX][MX];
char s1[MAXN], s2[MAXN];

int main (){
	int tt = 0;
	while(1){
		scanf("%d", &n);
		if(!n) break;
		deg = 1;
		for(int a=0;a<n;a++){
			scanf("\n");
			getline(cin, s[a]);
			ind[s[a]] = deg++;
		}
		for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++){
				d[a][b] = 0;
			}
		}
		scanf("%d", &m);
		long double ex;
		for(int a=0;a < m;a++){
			scanf(" %s %Lf %s", s1, &ex, s2);
			int u = ind[s1];
			int v = ind[s2];
			d[u][v] = ini[u][v] = ex;
		}
		for(int k = 1;k <= n;k++){
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){

					d[i][j] = max(d[i][j], d[i][k]*d[k][j]);
					
				}
			}
		}
		printf("Case %d: ", ++tt);
		int res = 0;
		for(int a=1;a<=n;a++){
			if(d[a][a] > 1.){
				//	printf("%d %d : %Lf > %Lf\n", a, a, d[a][a], ini[a][a]);
				res =1;
				break;
			}
		}
		if(res)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
