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
char s[MAXN];

bool vow(char a){
	return(a == 'A' || a == 'E' || a== 'I' || a== 'O' || a == 'U' || a=='Y');
}

int main (){
	scanf("%s", s);
	int tam = strlen(s);
	int res = 0;
	int ult = -1;
	for(int a=0;a<tam;a++){
		if(vow(s[a])){
			res = max(res, a - ult);
			ult = a;
		}
	}
	res = max(res, tam-ult);
	printf("%d\n", res);
}