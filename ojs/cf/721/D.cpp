#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m;
ll k;
ll s[MAXN];
set<pii> v;
set<pii>:: iterator it;

void maxi(){
	for(int a=0;a<n;a++){
		v.insert(pii(a, s[a]));
	}
	for(it = v.begin();it != v.end();++it){
		
	}
}

int main (){
	scanf("%d%d%lld", &n, &m, &k);
	int neg = 0;
	int z = 0;
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);
		if(s[a] < 0)
			neg++;
		if(s[a] == 0)
			z++;
	}
	if(z)
		solz();
	else if(neg&1)
		soln();
	else{
		int imn = -1;
		int mn = INT_MAX;
		for(int a=0;a<n;a++){
			if(mn < abs(s[a])){
				mn = abs(s[a]);
				imn = a;
			}
		}
		int sin = s[a]/abs(s[a]);
		if(s[a] < 0){

		}
		
	}
}
