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

int mnL[MAXN], mnR[MAXN], mxL[MAXN], mxR[MAXN];

stack<int> q;

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", s+a);
	}
	q.push(0);
	s[0] = INT_MAX;
	s[n+1] = INT_MAX;
	for(int a=1;a<=n+1;a++){
		while(!q.empty() && s[q.top()] < s[a]){
			mxR[q.top()] = a;
			q.pop();
		}
		mxL[a] = q.top();
		q.push(a);
	}

	while(!q.empty())
		q.pop();

	s[0] = INT_MIN;
	s[n+1] = INT_MIN;
	q.push(0);

	for(int a=1;a<=n+1;a++){
		while(!q.empty() && s[q.top()] > s[a]){
			mnR[q.top()] = a;
			q.pop();
		}
		mnL[a] = q.top();
		q.push(a);
	}

	while(!q.empty())
		q.pop();

	ll res = 0;
	for(int a=0;a<n;a++){
		debug("%d Lmx %d Rmx %d Lmn %d Rmn %d\n", a, );
		res += s[a]*(a - mxL[a]+ 1)*(mxR[a] - a + 1);
		res -= s[a]*(a - mnL[a] + 1)*(mnR[a] - a + 1);
	}
	printf("%lld\n", res);
}
