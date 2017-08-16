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

vector<char> p;


void add(char c){
	int a;
	for(a=1;a<p.size();a++){
		if(p[a] > c)
			break;
	}
	if(c == p[a-1]) return;
	if(a == p.size())
		p.pb(c);
	else
		p[a] = min(p[a], c);
}

int main (){

	p.pb('a'-1);
	scanf(" %s", s);
	n = strlen(s);
	for(int a=0;a<n;a++){
		add(s[a]);
	}
	printf("%d\n", 27 - (int)p.size());
}

