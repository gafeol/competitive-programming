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
char v[MAXN];
map<char, int> mrk;

void fail(){
	printf("-1\n");
	exit(0);
}

int main (){
	scanf(" %s", s);
	scanf(" %s", v);
	n = strlen(s);
	m = strlen(v);
	if(n != m)
		fail();

	for(int a=0;a<n;a++){
		mrk[s[a]]++;
	}
	for(int a=0;a<m;a++){
		mrk[v[a]]--;
	}
	for(int a=0;a<n;a++){
		if(mrk[s[a]] != 0)
			fail();
	}
	for(int a=0;a<m;a++){
		if(mrk[v[a]] != 0)
			fail();
	}
	
	int i = n-1, j = m-1;
	int res = 0;
	while(i > 0 && j > 0){
		if(s[i] == v[j]){
			i--;
			j--;
		}
		else{
			if(mrk[v[j]] != 0){
				mrk[v[j]]--;
				j--;
			}
			else{
				mrk[s[i]]++;
				i--;
				res++;
			}
		}
	}
	printf("%d\n", res);

}
