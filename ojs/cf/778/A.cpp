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

int n, m, k, o[MAXN];
char s[MAXN], ss[MAXN], p[MAXN], sz[500];
vector<int> v[500];

bool test(int i){
	for(int a=0;a<i;a++){
		s[o[a]] = '?';
	}
	int j = 0;
	for(int a=0;a<n && j < m;a++){
		if(s[a] == p[j])
			j++;
	}
	for(int a=0;a<i;a++){
		s[o[a]] = ss[o[a]];
	}
	debug("test %d j %d\n", i, j);
	return (j == m);
}

int main (){
	scanf(" %s", s);
	scanf(" %s", p);
	n = strlen(s);
	m = strlen(p);
	for(int a=0;a<n;a++){
		ss[a] = s[a];
		scanf("%d", &o[a]);
		o[a]--;
	}
	int i = 0, j = n;
	while(i < j){
		int m = (i+j+1)/2;
		if(test(m))
			i = m;
		else
			j = m-1;
	}
	printf("%d\n", i);
}
