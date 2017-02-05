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

const int MAXN = 1123456;

int n, m, k;
char s[MAXN];



int main (){
	scanf("%[^\n]", s);
	int tam = strlen(s);
	int x = tam-1;
	while(s[x] != ' ')
		x--;
	x++;
	while(x < tam){
		n *= 10;
		n += s[x] - '0';
		x++;
	}
	int pos, neg;
	neg = 0;
	pos = 1;
	for(int a=0;a<tam;a++){
		if(s[a] == '+')
			pos++;
		else if(s[a] == '-')
			neg++;
	}
	if(pos*n - neg < n || pos - neg*n > n){
		puts("Impossible");
		return 0;
	}
	int sump, sumn;
	int i = pos, j = pos*n;
	while(i < j){
		int m = (i + j)/2;
		if(m-neg < n)
			i = m+1;
		else
			j = m;
	}
	sump = i;
	sumn = sump - n;
	debug("sump %d sumn %d\n", sump, sumn);
	puts("Possible");
	int is = 1, sum = 0;
	for(int a=0;a<tam;a++){
		if(s[a] == '?'){
			if(is){
				pos--;
				printf("%d", min(sump-pos, n));
				sump -= min(n, sump-pos);
			}
			else{
				neg--;
				printf("%d", min(sumn-neg, n));
				sumn -= min(sumn-neg, n);
			}
		}
		else{
			printf("%c", s[a]);
			if(s[a] == '-')
				is = 0;
			else if(s[a] == '+')
				is = 1;
		}
	}	
}
