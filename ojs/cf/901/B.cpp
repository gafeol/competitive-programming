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
int s[MAXN];
map<int, int> p[2], aux; 

void print(int t){
	printf("%d\n", (int)p[t].size()-1);
	for(auto it: p[t])
		printf("%d ", it.snd);
	puts("");
}

int main (){
	scanf("%d", &n);
	p[0][0] = 1;
	p[1][0] = 0;
	p[1][1] = 1;
	for(int i=2;i<=n;i++){
		int t = (i&1);
		aux.clear();
		for(auto it: p[t^1]){
			aux[it.fst + 1] += it.snd;
		}
		for(auto it: p[t]){
			aux[it.fst] += it.snd;
		}
		int ok = 1;
		for(auto it: aux){
			if(it.snd > 1 || it.snd < -1)
				ok = 0;
		}
		if(!ok){
			for(auto it: p[t])
				aux[it.fst] -= 2*it.snd;
		}
		p[t].clear();
		p[t] = aux;
	}
	print((n&1));
	print(1 - (n&1));
}

