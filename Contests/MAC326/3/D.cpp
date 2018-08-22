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
vector<char> lis;

int main (){
	scanf(" %s", s);
	int ans =0;
	n = strlen(s);
	for(int i=0;i<n;i++){
		int ok = 0;
		for(int a=0;a<lis.size();a++){
			if(lis[a] >= s[i]){
				lis[a] = s[i];
				ok = 1;
				break;
			}
		}
		if(!ok)
			lis.pb(s[i]);
	}
	printf("%d\n", 26 - (int)lis.size());
}

