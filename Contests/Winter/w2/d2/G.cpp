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

int main (){
	for_tests(t, tt){
		scanf("%d %d%d", &n, &m, &k);
		for(int a=0;a<n;a++){
			s[a] = 0;
			for(int b=0;b<m;b++){
				char c;
				scanf(" %c", &c);
				s[a] += (c == '*');
			}
		}
		while(k){
			int best = INT_MIN, ib;
			for(int a=0;a<n;a++){
				int bef = s[a];
				int aft = m - s[a];
				if(aft - bef > best){
					best = aft - bef;
					ib = a;
				}
			}
			s[ib] = m - s[ib];
			k--;
		}
		int res = 0;
		for(int a=0;a<n;a++){
			res += s[a];
		}
		printf("%d\n", res);
	}
}
