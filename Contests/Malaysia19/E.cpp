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

const int MAXN = 2123;
const int MAXR = 112;

int n, m, k, t;
int dp[MAXR][MAXN];
vector<int> s;

bool go(int mn, int t){
    if(t < 0) return 0;
    int &r = dp[mn][t];
    if(r != -1) return r;
    if(mn == n) return 0;
    if(t == 0)
        return r = 1;
    r = (go(mn+1, t) || (mn < n ? go(mn+1, t-s[mn]) : false));
    return r;
}

void re(int mn, int t){
    if(t == 0)
        return ;
    if(go(mn+1, t-s[mn])){
        printf("%d ", s[mn]);
        re(mn+1, t-s[mn]);
    }
    else{
        assert(go(mn+1, t));
        re(mn+1, t);
    }
}

int main (){
    while(scanf("%d", &t) != EOF && t != 0){
        scanf("%d", &n);
        s.resize(n);
        for(int a=0;a<=n;a++){
            for(int b=0;b<=t;b++){
                dp[a][b] = -1;
            }
            dp[a][0] = n;
        }
        for(int a=0;a<n;a++)
            scanf("%d", &s[a]);


        for(int time=t;time>=0;time--){
            if(go(0, time)){
                re(0, time);
                printf("%d\n", time);
                break;
            }
        }
    }
}

