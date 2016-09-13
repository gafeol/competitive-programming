
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

const int MAXN = 212345;

int n, m, k;

int s[MAXN];

map<int, int> ind;

set<int> v;
int main (){
	scanf("%d", &n);
	int mn = INT_MAX;
	int mx = INT_MIN;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		mn = min(mn , s[a]);
		mx = max(mx, s[a]);
		v.insert(s[a]);
		ind[s[a]] = 1;
	}
	if(v.size() <= 2){
		puts("YES");
	}
	else if(v.size() > 3){
		puts("NO");
	}
	else{
		if(!((mn + mx)&1) && ind[(mn+mx)/2] == 1){
			puts("YES");
		}
		else
			puts("NO");
	}
}
