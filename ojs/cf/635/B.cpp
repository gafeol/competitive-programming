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
int v[MAXN];

int cs[MAXN];
int cv[MAXN];

void fail(){
	puts("NO");
	exit(0);
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		cs[s[a]]++;
	}
	for(int a=0;a<n;a++){
		scanf("%d", v+a);
		cv[v[a]]++;
	}
	for(int a=0;a<n;a++){
		if(cs[s[a]] != cv[s[a]] || cs[v[a]] != cv[v[a]])
			fail();
	}
	int i = 0;
	int j = 0;
	while(i < n && s[i] == 0)
		i++;
	while(j < n && v[j] != s[i])
		j++;
	if(j == n)
		fail();
	while(i < n){
		while(s[i] != v[j]){
			if(v[j] != 0)
				fail();
			j = (j + 1)%n;
		}
		i++;
		while(i < n && s[i] == 0)
			i++;
		j = (j + 1)%n;
	}
	puts("YES");
}

