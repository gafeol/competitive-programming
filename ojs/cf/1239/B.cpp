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

const int MAXN = 312345;

int n, m, k;

int q[MAXN];
int dp[MAXN][3];

int S;

int getind(int x){
    if(x < n - S)
        return x + S+1;
    else
        return x - (n-S)+1;
}

int go(int i, int t){
    int &r = dp[i][t];
    if(r != -1)
        return r;
    if(i == n) 
        r = 0;
    
}

int main (){
	scanf("%d", &n);
    int cnt = 0;  
    int from = 0;
    vector<char> inp(n);
	for(int a=0;a<n;a++){
        scanf(" %c", &inp[a]);
        cnt += (inp[a] == '(' ? 1 : -1);
        if(cnt < 0){
            from = a+1;
            cnt = 0;
        }
	}
    vector<char> s;
    S = from;
    int ate = from;
    for(;from < n;from++)
        s.pb(inp[from]);
    for(int i=0;i<ate;i++)
        s.pb(inp[i]);
    cnt = 0;
    for(int a=0;a<n;a++){
        cnt += (s[a] == '(' ? 1 : -1);
        if(cnt < 0){
            puts("0\n1 1");
            return 0;
        }
        q[a] = cnt;
    }
    if(cnt > 0){
        puts("0\n1 1");
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    int ans = go(0, 0);
    printf("%d\n", ans);
    re(0,0);
}
