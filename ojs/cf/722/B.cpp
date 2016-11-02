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

char f[MAXN];

bool vow(char a){
	a = toupper(a);
	return (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' || a == 'Y');
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	int fodeu = 0;
	for(int a=0;a<n;a++){
		scanf(" %[^\n]", f);
		int tam = strlen(f);
		for(int i=0;i<tam;i++){
			if(vow(f[i])){
				s[a]--;
			}
		}
		if(s[a] != 0)
			fodeu = 1;
	}
	if(fodeu)
		puts("NO");
	else
		puts("YES");
}
