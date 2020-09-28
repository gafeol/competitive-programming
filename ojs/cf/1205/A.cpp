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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

int n, m, k;
int s[MAXN];
int ans[2*MAXN];

int main (){
	scanf("%d", &n);
    for(int a=0;a<n;a++){
        int bg = 2*a+2, sm = 2*a+1;
        if(a&1){
            ans[a] = bg;
            ans[a+n] = sm;
        }
        else{
            ans[a] = sm;
            ans[a+n] = bg;
        }
    }
    ll sum = 0;
    ll mnsum, mxsum;
    for(int a=0;a<n;a++){
        sum += ans[a];
    }
    mnsum = mxsum = sum;
    for(int a=n;a<2*n;a++){
        sum += - ans[a-n] + ans[a];
        mnsum = min(mnsum, sum);
        mxsum = max(mxsum, sum);
    }
    for(int a=0;a<n;a++){
        sum += ans[a] - ans[n+a];
        mnsum = min(mnsum, sum);
        mxsum = max(mxsum, sum);
    }
    if(abs(mnsum - mxsum) <= 1){
        puts("YES");
        for(int a=0;a<2*n;a++)
            printf("%d ", ans[a]);
        puts("");
    }
    else
        puts("NO");
}

