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

int n, m, k;
char s[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %c", &s[a]);
	}
	int res =0;
	for(int a=0;a<n;a++){
		if(s[a] != '<') break;
		res++;
	}
	for(int a=n-1;a>=0;a--){
		if(s[a] != '>')
			break;
			res++;
	}
	printf("%d", res);
}

