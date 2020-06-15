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
const int MAXS = 1000009;

int n, m, k;
int s[MAXN];
ll sum[MAXN];
ll ans[MAXS];

int solve(int x){
    int ans = 0;   
    for(int i=0;i<n;i++){
        ans++;
        int l = i, r = n-1;
        while(l < r){
            int m = (l + r + 1)/2;
            if(sum[m] - (i > 0 ? sum[i-1] : 0) <= x)
                l = m;
            else
                r = m-1;
        }
        i = l;
    }
    return ans;
}

int main (){
    memset(ans, -1, sizeof(ans));
	scanf("%d", &n);
    int mx = 0;
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
        mx = max(s[a], mx);
        sum[a] = s[a] + (a > 0 ? sum[a-1] : 0);
	}
    scanf("%d", &m);
    for(int a=0;a<m;a++){
        int x;
        scanf("%d", &x);
        if(x < mx){
            puts("Impossible");
            continue;
        }
        if(ans[x] == -1)
            ans[x] = solve(x);
        printf("%lld\n", ans[x]);
    }
}

