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

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		int bef = 0;
		int falhou = 0;
		for(int a=0;a<n;a++){
			char ch;
			scanf(" %c", &ch);
			if(ch == 'H')
				bef++;
			else if(ch == 'T')
				bef--;

			if(bef > 1 || bef < 0)
				falhou = 1;
		}
		if(bef != 0)
			falhou = 1;
		if(falhou)
			puts("Invalid");
		else
			puts("Valid");
	}
}
