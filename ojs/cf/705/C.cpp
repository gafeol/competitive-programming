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

const int MAXN = 312345;

int n, m, k;

int qtd[MAXN];

int bit[MAXN];

queue <int> f[MAXN];

int qry(int i){
	int ans = 0;
	while(i > 0){
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

void upd(int i, int v){
	while(i < MAXN - 10){
		bit[i]+= v;
		i += (i&-i);
	}
}

int main (){
	scanf("%d%d", &n, &m);
	int res = 0;
	int deg = 1;
	int apa = -1;
	int i = 1;
	for(int a=0;a<m;a++){
		int t, x;
		scanf("%d %d", &t, &x);
		if(t == 1){
			f[x].push(deg);
			res++;
			deg++;
		}
		else if(t == 2){
			while(!f[x].empty()){
				int ta = f[x].front();
				f[x].pop();
				if(ta > apa){
					upd(ta, 1);
					res--;
				}
			}
		}
		else{
			if(x > apa){
				int aux = x - qry(deg);
				res -= aux;	
				apa = max(apa, x);
				upd(1, aux);
			}
		}
		printf("%d\n", res);
	}
}


