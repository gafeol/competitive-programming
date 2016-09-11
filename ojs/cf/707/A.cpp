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

int main (){
	int n, m;
	int ans = 1;
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			char c;
			scanf(" %c", &c); 
			if(c != 'W' && c != 'B' && c != 'G'){
				ans = 0;
			}
		}
	}
	if(ans)
		puts("#Black&White");
	else
		puts("#Color");
}
