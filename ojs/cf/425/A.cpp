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

const int MAXN = 212;

int n, m, k;
int s[MAXN], som[MAXN];
multiset<int> q, mn;

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		if(a != 0)
			som[a] = som[a-1];
		som[a] += s[a];
	}
	int res = INT_MIN;
	for(int l=0;l<n;l++){
		for(int r=l;r<n;r++){
			q.clear();
			for(int i=0;i < l;i++)
				q.insert(-s[i]);
			for(int i=r+1;i<n;i++)
				q.insert(-s[i]);
			for(int i=l;i<=r;i++)
				mn.insert(s[i]);
			int cnt = k;
			int soma = 0;
			while(!q.empty() && !mn.empty() && -(*q.begin()) > (*mn.begin())  && cnt){
				int v1 = *mn.begin();
				int v2 = -(*q.begin());
				soma += v2;
				q.erase(q.begin());
				mn.erase(mn.begin());
				q.insert(-v1);
				mn.insert(v2);
				cnt--;
			}
			int ans = 0;
			while(!mn.empty()){
				ans += *mn.begin();
				mn.erase(mn.begin());
			}
			res = max(res, ans);	
		}
	}
	printf("%d\n", res);
}
