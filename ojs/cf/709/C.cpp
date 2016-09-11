

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

char s[112345];

bool best(int i){
	return (s[i] != 'a');
}

char shift(int i){
	if(s[i] == 'a')
		return 'z';
	return (s[i] - 1);
}

int main (){
	scanf(" %s", s);
	int tam = strlen(s);
	int fiz = 0, term = 0;
	for(int a=0;a<tam;a++){
		if(!fiz && !term){
			if(best(a)){
				fiz = 1;
				printf("%c", shift(a));
			}
			else if(a == tam-1){
				printf("%c", shift(a));
			}
			else{
				printf("%c", s[a]);
			}
		}
		else if(fiz && !term){
			if(!best(a)){
				term = 1;
				printf("%c", s[a]);
			}
			else{
				printf("%c", shift(a));
			}
		}
		else{

			printf("%c", s[a]);
		}
	}
}
