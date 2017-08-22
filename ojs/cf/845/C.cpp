
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
pii s[MAXN];
int lst[3];

int main (){
	scanf("%d", &n);
	lst[0] = lst[1] = -1;
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		s[a] = pii(i, j);
	}
	sort(s, s+n);
	for(int a=0;a<n;a++){
		if(lst[0] < s[a].fst){
			lst[0] = s[a].snd;
		}
		else{
			if(lst[1] < s[a].fst)
				lst[1] = s[a].snd;
			else{
				puts("NO");
				return 0;	
			}
		}
	}
	puts("YES");
}

