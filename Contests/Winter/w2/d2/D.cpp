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

const int MAXN = 212;

int n, m, k;
char s[MAXN];
int tam;

bool check(int i, int j){
	int b = 0;
	for(int a=0;a<tam;a++){
		int ok = 0;
		for(int t=0;t<j-i+1;t++){
			if(s[j-t] != s[a+t]) break;
			if(t == j-i) ok = 1;
		}
		if(ok) return true;
	}
	return false;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %s", s);
		int fodeu = 0;
		tam = strlen(s);
		for(int i=0;fodeu == 0 && i<tam;i++){
			for(int j=i;fodeu == 0 && j<tam;j++){
				if(!check(i, j)){
					fodeu = 1;
				}
			}
		}
		if(fodeu)
			puts("NO");
		else
			puts("YES");
	}
}
