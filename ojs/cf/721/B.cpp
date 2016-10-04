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

const int MAXN = 112;

int n, m, k, t[MAXN], ind[MAXN], cnt[MAXN];
char s[MAXN][MAXN];
char p[MAXN];

int f(int x){
	return (((int)(x/k))*5);
}

int main (){
	scanf("%d %d", &n, &k);
	for(int a=0;a<n;a++){
		scanf(" %s", s[a]);
		t[a] = strlen(s[a]);
		cnt[t[a]]++;
	}
	scanf(" %s", p);
	int ip;
	for(int a=0;a<n;a++){
		if(strcmp(p, s[a]) == 0){
			ip = a;
		}
	}
	int sum = 0;
	for(int a = 0;a<t[ip];a++){
		sum += cnt[a];
	}
	printf("%d %d\n", sum+1+f(sum), sum+cnt[t[ip]] + f(sum + cnt[t[ip]]-1));
}
