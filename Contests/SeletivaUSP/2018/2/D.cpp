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

int n, m;
ll k;
int s[MAXN];

map<ll, int> pos;

vector<ll> st;

int bb(ll x){
	int i = 0, j = st.size()-1;	
	while(i < j){
		int m = (i+j+1)/2;
		if(x - st[m] >= k)
			i = m;
		else
			j = m-1;
	}
	return i;
}

int main (){
	for_tests(t, tt){
		scanf("%d%lld", &n, &k);
		pos.clear();
		while(!st.empty())
			st.pop_back();
		ll sum = 0;
		st.push_back(0);
		pos[0] = -1;
		int ans = INT_MAX;
		for(int a=0;a<n;a++){
			ll x;
			scanf("%lld", &x);
			sum += x;
			if(sum - st[0] >= k){
				int i = bb(sum);
				ans = min(ans, a - pos[st[i]]);
			}
			while(!st.empty() && st.back() > sum)
				st.pop_back();
			st.push_back(sum);
			pos[sum] = a;
		}
		if(ans == INT_MAX)
			puts("-1");
		else
			printf("%d\n", ans);
	}
}

