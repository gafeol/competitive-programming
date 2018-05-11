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
char v[MAXN];
vector<char> p[2];

int main (){
	for_tests(t, tt){
		scanf(" %s %s", s, v); 
		p[0].clear();
		p[1].clear();
		int tam = strlen(s);
		int vtam = strlen(v);
		int b = 0;
		int ans = 1;
		for(int a=0;a<tam;a++){
			if(a != 0 && s[a] == s[a-1]) continue;
			p[0].pb(s[a]);
		}
		for(int a=0;a<vtam;a++){
			if(a != 0 && v[a] == v[a-1]) continue;
			p[1].pb(v[a]);
		}
		if(p[0].size() != p[1].size())
			ans = 0;
		else{
			for(int a=0;a<p[0].size();a++)
				if(p[0][a] != p[1][a]) ans = 0;
		}

		if(ans)
			puts("Yes");
		else
			puts("No");
	}
}

