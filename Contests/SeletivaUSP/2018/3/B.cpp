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

map<int, map<char, int> > qtd;
vector<char> v[2];

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &k);
		char c;
		v[0].clear();
		v[1].clear();
		qtd.clear();
		for(int a=0;a<n;a++){
			scanf(" %c", &c);	
			qtd[a%k][c]++;
			v[0].pb(c);
		}
		for(int a=0;a<n;a++){
			scanf(" %c", &c);
			qtd[a%k][c]--;
			v[1].pb(c);
		}
		int ans = 1;
		for(int b=0;b<2;b++){
			for(int a=0;a<n;a++){
				if(qtd[a%k][v[b][a]] != 0) 
					ans = 0;
				qtd[a%k][v[b][a]]=0;
			}
		}
		if(ans)
			puts("Yes");
		else
			puts("No");
	}
}

