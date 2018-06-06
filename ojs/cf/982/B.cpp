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

set<pii> i, e;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		i.insert(pii(s[a], a+1));
	}
	for(int a=0;a<2*n;a++){
		char c;
		scanf(" %c", &c); 
		if(c == '0'){
			pii se = *i.begin();
			i.erase(i.begin());
			printf("%d ", se.snd);
			e.insert(se);
		}
		else{
			pii se = *e.rbegin();
			e.erase(se);
			printf("%d ", se.snd);
		}
	}
}

