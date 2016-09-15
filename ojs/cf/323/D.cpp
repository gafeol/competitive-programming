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

const int MAXN = 11234;

int n, m, k, s[MAXN];

vector<int> v;

int st[MAXN], deg;

int bb(int i, int j, int v){
	while(i < j){
		int m = (i + j)/2;
		if(st[m] > v)
			j = m;
		else
			i = m + 1;
	}
	if(st[i] > v) i--;
	return i;
}

int go(int i, int j){
	deg = 0;
	for(int a=0;a<n;a++){
		if(s[a] >= i && s[a] <= j){
			int p = bb(0, deg-1, s[a])+1;
			st[p] = s[a];
			deg = max(deg, p+1);
		}
	}
	return deg;
}

int main (){
	scanf("%d %d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		v.push_back(s[a]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int a=0;a<v.size();a++){
		for(int b=a;b<v.size();b++){
			dp[a][b] = go(a, b);
		}
	}

}
