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

const int MAXN = 212345, MAXB = 1000010;

int n, m, k;
int s[MAXN];

int bit[MAXB];

void upd(int i, int val){
	while(i < MAXB){
		bit[i] += val;
		i += (i&-i);

	}
}

int bb(){
	int p = 27;
	int i = 0, cnt = 0;
	while(p >= 0){
		if(i + (1<<p) < MAXB && cnt + bit[i+(1<<p)] < (k+1)/2){
			i += (1<<p);
			cnt += bit[i];
		}
		p--;
	}
	return i;
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		s[a]++;
	}
	int res = 0;
	for(int a=0;a<k;a++)
		upd(s[a], 1);

	res = max(res, bb());
	for(int a=k;a<n;a++){
		upd(s[a-k], -1);
		upd(s[a], 1);
		res = max(res, bb());
	}
	printf("%d\n", res);
}
