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

const int MAXN = 41234;

int n, m, k;
struct pti{
	int x, y;
} s[MAXN][2];

map<int, vector<pii> > ind;

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d%d%d%d", &s[a][0].x, &s[a][0].y, &s[a][1].x, &s[a][1].y);
			if(s[a][0].x > s[a][1].x)
				swap(s[a][0], s[a][1]);
			ind[s[a][0].x].pb(pii(s[a][0].y, 
		}
	}	
}	
