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
int cnt[MAXN];

stack<int> st;

void f(){
	puts("-1");
	exit(0);
}

int main (){
	scanf("%d%d", &n, &k);
	int beg = 1;
	for(int a=0;a<k;a++){
		scanf("%d", s+a);
		cnt[s[a]]++;
		if(s[a] == beg)
			beg++;
		else{
			if(!st.empty() && st.top() < s[a])
				f();
			st.push(s[a]);
		}
		while(!st.empty() && st.top() == beg){
			st.pop();
			beg++;
		}
	}
	int deg = k;
	while(beg != n+1){
		if(!st.empty() && st.top() == beg){
			beg++;
			st.pop();
			continue;
		}
		int mx = n;
		if(!st.empty())
			mx = st.top()-1;
		for(int a=mx;a>=beg;a--){
			s[deg++] = a;
			st.push(a);
		}
	}
	for(int a=0;a<n;a++){
		printf("%d ", s[a]);
	}
}

