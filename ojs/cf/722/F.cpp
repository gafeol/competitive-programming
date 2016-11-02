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

int n, m, k, res[MAXN];
int s[MAXN][50];
int tam[MAXN], mx[MAXN];
int ind[MAXN];

map<int, int> freq[MAXN];

bool cmp(int a, int b){
	return tam[a] < tam[b];
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		scanf("%d", &tam[a]);
		ind[a] = a;
		for(int i =0;i < tam[a];i++){
			scanf("%d", &s[a][i]);
		}
	}
	sort(ind+1, ind+n+1, cmp);
	int ult = 1;
	for(int a=1;a<=n;a++){
		int aa = ind[a];
		if((a != 1 && tam[ind[a]] != tam[ind[a-1]])){
			for(int i=ult;i<a;i++){
				for(int j=0;j<tam[ind[i]];j++){
					res[s[i][j]] += mx[s[i][j]];
					if(mx[s[i][j]] != 0){
						freq[s[i][j]].clear();
						mx[s[i][j]] = 0;
					}

				}
			}
			ult = a;
		}
		for(int b=0;b<tam[ind[a]];b++){
			freq[s[a][b]][b]++;
			if(freq[s[a][b]][b] > mx[s[a][b]])
				mx[s[a][b]] = freq[s[a][b]][b];
		}
	}
	for(int i=ult;i<=n;i++){
		for(int j=0;j<tam[ind[i]];j++){
			res[s[i][j]] += mx[s[i][j]];
			if(mx[s[i][j]] != 0){
				freq[s[i][j]].clear();
				mx[s[i][j]] = 0;
			}

		}
	}
	for(int a=1;a<=m;a++){
		printf("%d\n", res[a]);
	}
	//fazer pra a = n+1;
}
