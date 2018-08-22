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
char v[MAXN], s[MAXN];

map<char, map<char, int> > ch;

vector<int> w[MAXN];

int main (){
	scanf("%d", &n);
	scanf(" %s %s", s, v);
	for(int a=0;a<n;a++){
		if(s[a] != v[a]){
			w[s[a]].pb(a);
			ch[s[a]][v[a]] = a;
		}
	}
	pii swp = pii(-1, -1);
	for(int a=0;a<n;a++){
		if(s[a] != v[a] && ch[v[a]].find(s[a]) != ch[v[a]].end()){
			swp = pii(a+1, ch[v[a]][s[a]]+1);
			swap(s[a], s[ch[v[a]][s[a]]]);
			break;
		}
	}
	if(swp == pii(-1, -1)){
		for(int a=0;a<n;a++){
			if(s[a] != v[a] && w[v[a]].size() != 0){
				swp = pii(a+1, w[v[a]][0]+1);
				swap(s[a], s[w[v[a]][0]]);
				break;
			}
		}
	}
	int res =0;
	for(int a=0;a<n;a++){
		res += (s[a] != v[a]);
	}
	printf("%d\n%d %d\n", res, swp.fst, swp.snd);
}
