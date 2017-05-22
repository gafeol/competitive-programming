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

const int MAXN = 212345, MAXX = 1123456;

int n, m, k;
pii s[MAXN][2];

struct arv{
	int sum, lz;
} tree[MAXX*4];

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			for(int b=0;b<2;b++){
				scanf("%d %d", &s[a][b].snd, &s[a][b].fst);
			}
			if(s[a][0] > s[a][1])
				swap(s[a][0], s[a][1]);
		}
	}
}
