
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

int n, m, k, deg;


struct arv{
	int mrk;
	int f[3];
	arv(){
		mrk = 0;
		f[0] = -1;
		f[1] = -1;
	}
} v[MAXN*20];

int newa(){
	v[deg].f[0] = v[deg].f[1] = -1;
	v[deg].mrk = 0;
	deg++;
	return deg-1;
}

int go(int u, int d, int val){
//	printf("to em %d com %d %d\n", u, d, val);
	if(v[u].f[d] == -1)
		v[u].f[d] = newa();
	u = v[u].f[d];
	v[u].mrk+=val;
	//printf("vou para %d v[u].mrk %d l %d r %d \n", u, v[u].mrk, v[u].f[0], v[u].f[1]);
	return u;
}

int main (){
	scanf("%d", &n);
	int r = newa();
	for(int a=0;a<n;a++){
		char t;
		ll x;
		scanf(" %c %lld", &t, &x);
		if(t == '+'){
			int cnt = 18;
			int u = r;
			while(cnt >0){
				u = go(u, ((x%10)&1), 1);
				x/=10;
				cnt--;
			}
		}
		else if(t == '-'){
			int cnt = 18;
			int u = r;
			while(cnt >0){
				u = go(u, ((x%10)&1), -1);
				x/=10;
				cnt--;
			}
		}
		else{
			int cnt = 18;
			int u = r;
			while(cnt > 0){
				u = go(u, ((x%10)&1), 0);
				x/=10;
				cnt--;
			}
			printf("%d\n", v[u].mrk);
		}
	}
}
