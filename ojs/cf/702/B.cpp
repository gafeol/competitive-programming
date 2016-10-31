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

map<int, ll> ind;

map<pii, int> mrk;


ll res;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		ind[s[a]]++;
	}
	for(int a=0;a<n;a++){
		for(int d=1;d<=30;d++){
			if((1<<d) - s[a] > 0){
				if(mrk.find(pii(s[a], (1<<d)-s[a])) != mrk.end())
					continue;
				mrk[pii(s[a], (1<<d)-s[a])] = 1;
				mrk[pii((1<<d)-s[a], s[a])] = 1;
				if((1<<d) == s[a]*2){
					res += (ind[s[a]]*(ind[s[a]]-1))/2ll;
				}
				else{
					res += ind[s[a]]*ind[(1<<d)-s[a]];
				}
			}
		}
	}
	printf("%lld\n", res);
}
