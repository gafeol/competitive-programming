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
char s[10];

int add = 0;
int dp[7][3][48];

int main (){
	while(scanf(" %s", s) != EOF && s[0] != 'E'){
		int tam = strlen(s);
		int val = 0;
		for(int a=0;a<tam;a++){
			val *= 10;
			val += (s[a]-'0');
			add += (s[a]-'0');
		}
		int dez = 1;
		for(int a=tam-1;a>=0;a--){
			if(s[a] != '0'){
				s[a]--;
				break;
			}
			dez *= 10;
		}
		int pt = 0;
		for(int a=0;a<tam;a++){
			if(s[a] != '0'){
				pt = 1;
				printf("%c", s[a]);
			}
			else if(pt == 1)
				printf("%c", s[a]);
		}
		if(pt == 0)
			printf("0");
		printf("\n");
	}
}
