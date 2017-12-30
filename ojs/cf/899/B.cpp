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

int c[2][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);	
	}
	for(int bm=0;bm<4;bm++){
		for(int i=0;i<12;i++){
			int b = (1<<bm);
			b /= 2;
			int m = i;
			int t = (b&1);
			b/=2;
			int ok = 1;
			for(int a=0;a<n;a++){
				if(s[a] != c[t][m]){
					ok = 0;
					break;
				}
				m = (m+1)%12;
				if(m == 0){
					t = (b&1);
					b/=2;
				}
			}
			if(ok){
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
}

