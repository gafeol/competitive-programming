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

const int SQRT = 318, MAXN = 112345;

struct cell{
	int nxt, bef;
	int val;
} s[a];

int cnt[SQRT][MAXN], fst[SQRT], lst[SQRT];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a].val);
		cnt[a/SQRT][s[a].val]++;
		if(a%SQRT == 0)
			fst[a/SQRT] = a;
		lst[a/SQRT] = a;
		s[a].nxt = a+1;
		if(a != 0) s[a].bef = a-1; 
		else s[a].bef = n;
	}
	scanf("%d", &m);
	int last_ans = 0;
	for(int a=0;a<m;a++){
		int t, i, j, k;
		scanf("%d %d %d", &t, &i, &j);
		i = (i + last_ans - 1)%n;
		j = (j + last_ans - 1)%n;
		if(i > j) swap(i, j);

		if(t == 1){
						
		}
		else{

		}
	}
}
