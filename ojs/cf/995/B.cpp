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
	scanf("%d", &n);
	for(int a=0;a<2*n;a++){
		scanf("%d", s+a);
	}
	int res = 0;
	for(int a=0;a<2*n;a+=2){
		for(int b=a+1;b<2*n;b++){
			if(s[a] == s[b]){
				int bb = b;
				while(bb > a+1){
					res++;
					swap(s[bb], s[bb-1]);
					bb--;
				}
				break;
			}
		}
	}
	printf("%d\n", res);
}

